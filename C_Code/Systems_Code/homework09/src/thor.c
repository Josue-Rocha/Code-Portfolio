/* thor.c */

#include "hammer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Functions */

void usage(const char *progname, int status) {
    fprintf(stderr, "Usage: %s [options] URL\n", progname);
    fprintf(stderr, "    -n HAMMERS How many times to hammer the URL\n");
    exit(status);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    char *progname = argv[0];

    if (argc < 2){
        usage(progname, 1);
    }

    int hammers = 1;
    int argind = 1;

    /* TODO: Parse command line arguments */
     while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char *arg = argv[argind++];

        switch(arg[1]){
            case 'h':
                usage(progname, 0);
                break;
            case 'n':
                hammers = atoi(argv[argind++]);
                break;
            default:
                usage(progname, 1);
                break;
        }
    }
    char *url = argv[argind];

    /* TODO: Throw Hammers */
    if(throw(url, hammers, stdout)){
        return EXIT_SUCCESS;
    }else{
        return EXIT_FAILURE;
    }
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
