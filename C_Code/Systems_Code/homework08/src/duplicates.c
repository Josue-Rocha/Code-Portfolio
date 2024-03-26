/* duplicates.c */

#include "hash.h"
#include "macros.h"
#include "table.h"

#include <dirent.h>
#include <limits.h>
#include <sys/stat.h>

/* Globals */

char * PROGRAM_NAME = NULL;

/* Structures */

typedef struct {
    bool count;
    bool quiet;
} Options;

/* Functions */

void usage(int status) {
    fprintf(stderr, "Usage: %s paths...\n", PROGRAM_NAME);
    fprintf(stderr, "    -c     Only display total number of duplicates\n");
    fprintf(stderr, "    -q     Do not write anything (exit with 0 if duplicate found)\n");
    exit(status);
}

/**
 * Check if path is a directory.
 * @param       path        Path to check.
 * @return      true if Path is a directory, otherwise false.
 */
bool is_directory(const char *path) {
    struct stat st;
    return !stat(path, &st) && S_ISDIR(st.st_mode);
}

/**
 * Check if file is in table of checksums.
 *
 *  If quiet is true, then exit if file is in checksums table.
 *
 *  If count is false, then print duplicate association if file is in
 *  checksums table.
 *
 *
 * @param       path        Path to file to check.
 * @param       checksums   Table of checksums.
 * @param       options     Options.
 * @return      0 if Path is not in checksums, otherwise 1.
 */
size_t check_file(const char *path, Table *checksums, Options *options) {
    char hexdigest[HEX_DIGEST_LENGTH];
    if (hash_from_file(path, hexdigest)){
        Value *value = table_search(checksums, hexdigest);
        if(value){
            if(options->quiet){
                //table_delete(checksums);
                exit(EXIT_SUCCESS);
            }
            if(!options->count){
                printf("%s is duplicate of %s\n", path, value->string);
            }
            return 1;
        }else{
            table_insert(checksums, hexdigest, (Value){.string = (char *)path}, STRING);
        }
    }
    return 0;
}

/**
 * Check all entries in directory (recursively).
 * @param       root        Path to directory to check.
 * @param       checksums   Table of checksums.
 * @param       options     Options.
 * @return      Number of duplicate entries in directory.
 */
size_t check_directory(const char *root, Table *checksums, Options *options) {
    size_t count = 0;
    DIR* d = opendir(root);
    if (!d){
        return 0;
    }
    for (struct dirent *e = readdir(d); e; e = readdir(d)){
        if (strcmp(".", e->d_name) == 0 || strcmp("..", e->d_name) == 0){
            continue;
        }
        char epath[BUFSIZ];
        sprintf(epath, "%s/%s", root, e->d_name);

        if(is_directory(epath)){
            //count += check_directory(e->d_name, checksums, options);
            count += check_directory(epath, checksums, options);
        }else{
            //count += check_file(e->d_name, checksums, options);
            count += check_file(epath, checksums, options);
        }
    }
    closedir(d);
    return count;
}

/* Main Execution */

int main(int argc, char *argv[]) {
    PROGRAM_NAME = argv[0];

    Options op;
    op.count = false;
    op.quiet = false;

    int c = 0;
    int q = 0;
    Options *options = &op;

    size_t count = 0;
    int index = 0;

    Table *checksums = table_create(0);
    int argind = 1;

    /* Parse command line arguments */
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char *arg = argv[argind++];
        /* Check each argument */
        switch (arg[1]) {
            case 'h':
                usage(0);
                break;
            case 'c':
                c = 1;
                break;
            case 'q':
                q = 1;
                break;
            default:
                usage(1);
                break;
        }
    }
    if(c){
        options->count = true;
    }
    if(q){
        options->quiet = true;
    }

    index = argind;
    while(index < argc){
        if(is_directory(argv[index])){
            count += check_directory(argv[index], checksums, options);
        }else{
            count += check_file(argv[index], checksums, options);
        }
        index++;
    }

    table_delete(checksums);
    /*if (count){
        if(options->count){
            printf("%ld\n", count);
        }
        return EXIT_SUCCESS;
    }*/

    if(options->count){
        printf("%ld\n", count);
    }
    
    if (options->quiet){
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
