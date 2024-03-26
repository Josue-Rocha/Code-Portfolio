/* main.c: string library utility */

#include "str.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Globals */

char *PROGRAM_NAME = NULL;

/* Flags */

enum {
    /* TODO*: Enumerate Flags */
    STRIP       = 1<<1,
    REVERSE     = 1<<2,
    LOWER       = 1<<3,
    UPPER       = 1<<4,
    TITLE       = 1<<5,
    DELETE      = 1<<6,

};

/* Functions */

void usage(int status) {
    fprintf(stderr, "Usage: %s SOURCE TARGET\n\n", PROGRAM_NAME);
    fprintf(stderr, "Post Translation filters:\n\n");
    fprintf(stderr, "   -s      Strip whitespace\n");
    fprintf(stderr, "   -r      Reverse line\n");
    fprintf(stderr, "   -l      Convert to lowercase\n");
    fprintf(stderr, "   -u      Convert to uppercase\n");
    fprintf(stderr, "   -t      Convert to titlecase\n");
    fprintf(stderr, "   -d      Delete letters in SOURCE\n");
    exit(status);
}

void translate_stream(FILE *stream, char *source, char *target, int flags) {
    /* TODO: Process each line in stream by performing transformations */
    char buffer[BUFSIZ];
    while (fgets(buffer, BUFSIZ, stream)){
        str_chomp(buffer);

        if (flags & DELETE){
            str_delete(buffer, source);
        }
        if (target){
            str_translate(buffer, source, target);
        }

        if (flags & STRIP){
            str_strip(buffer);
        }
        if (flags & REVERSE){
            str_reverse(buffer);
        }
        if (flags & LOWER){
            str_lower(buffer);
        }
        if (flags & UPPER){
            str_upper(buffer);
        }
        if (flags & TITLE){
            str_title(buffer);
        }
        printf("%s\n", buffer);
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int bitset = 0;
    char *source = NULL;
    char *target = NULL;
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-s") == 0){
            bitset |= STRIP;
        }else if(strcmp(argv[i], "-h") ==0){
            usage(0);
        }else if(strcmp(argv[i], "-r") ==0){
            bitset |= REVERSE;
        }else if(strcmp(argv[i], "-l") ==0){
            bitset |= LOWER;
        }else if(strcmp(argv[i], "-u") ==0){
            bitset |= UPPER;
        }else if(strcmp(argv[i], "-t") ==0){
            bitset |= TITLE;
        }else if(strcmp(argv[i], "-d") ==0){
            bitset |= DELETE;
        }else if (i < argc -1){
            source = argv[i];
            target = argv[i+1];
            break;
        }else if(i < argc){
            source = argv[i];
        }
    }
    translate_stream(stdin, source, target, bitset);

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
