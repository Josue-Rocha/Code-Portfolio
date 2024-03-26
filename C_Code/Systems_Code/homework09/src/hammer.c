/* hammer.c: Make HTTP request and measure bandwidth */

#include "hammer.h"
#include "macros.h"
#include "request.h"
#include "timestamp.h"

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Constants */

#define MEGABYTE    (double)(1<<20)

/* Functions */

/**
 * Perform a hammer through by making a HTTP request to the specified URL and
 * printing the contents of the response to the given stream.
 * Function prints the bandwidth of the HTTP transaction if it is successful to
 * stderr.
 *
 * @param   url         Make HTTP request to this URL.
 * @param   stream      Write the contents of each response to this stream.
 *
 * @return  Whether or not the HTTP request was successful.
 **/
bool	hammer(const char *url, FILE *stream) {
    /* TODO: Perform HTTP request */
    double start_time = timestamp();
    Request *request = request_create(url);
    ssize_t bytes_written = request_stream(request, stream);
    
    if(bytes_written < 0){
        request_delete(request);
        return false;
    }

    /* TODO: Compute and display bandwidth to stderr if HTTP request was
     * successful */
    double end_time = timestamp();
    double bandwidth = bytes_written / 1048576.0 / (end_time - start_time);
    fprintf(stderr, "Bandwidth: %0.2lf MB/s\n", bandwidth);
    request_delete(request);
    return true;
}

/**
 * Make hammers HTTP requests to the specified url, while writing the contents
 * of the request to the specified stream.
 *
 * Each HTTP request must be performed by a separate child process.
 *
 * Function prints the total elapsed time for all throws to stderr at the end.
 *
 * @param   url         Make HTTP requests to this URL.
 * @param   hammers     The number of HTTP requests to make.
 * @param   stream      Write the contents of each response to this stream.
 *
 * @return  Whether or not all hammer throws were successful.
 **/
bool	throw(const char *url, size_t hammers, FILE *stream) {
    /* TODO: Throw all hammers by spawning child processes that call hammer and
     * exit success if the hammer throw was successful. */

    double start_time = timestamp();
    int status = 0;
    pid_t pid;

    for(size_t i = 0; i < hammers; i++){
        pid = fork();

        if(pid < 0){
            exit(EXIT_FAILURE);
        }
        
        if (pid == 0){ // Child
            bool check = hammer(url, stream);

            if(check){
                exit(EXIT_SUCCESS);
            }else{
                exit(EXIT_FAILURE);
            }
        }
    }

    /* TODO: Collect results of throws by waiting for all children */
    int all_status = 0;
    for(size_t i = 0; i < hammers; i++){
        pid = wait(&status);
        all_status += status;
    }

    double end_time = timestamp();

    /* TODO: Print elapsed time to stderr */
    fprintf(stderr, "Elapsed Time: %0.2lf seconds\n", end_time - start_time);

    if(all_status){
        return false;
    }else{
        return true;
    }
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
