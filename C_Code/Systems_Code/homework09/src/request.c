/* request.c: Make HTTP Requests */

#include "request.h"

#include "macros.h"
#include "socket.h"

#include <stdlib.h>
#include <string.h>

/* Constants */

#define HOST_DELIMITER  "://"
#define PATH_DELIMITER  '/'
#define PORT_DELIMITER  ':'

/* Functions */

/**
 * Construct Request structure by parsing URL string into separate host, port,
 * and path components.
 *
 * @param   url         URL string to parse.
 *
 * @return  Request structure.
 **/
Request *   request_create(const char *url) {
    /* TODO: Copy data to local buffer */
    char buffer[BUFSIZ];
    strcpy(buffer, url);

    /* TODO: Skip scheme to host */
    char *host;
    host = strstr(buffer, HOST_DELIMITER);
    if (host){
        host = host + 3;
    }else{
        host = buffer;
    }

    /* TODO: Split host:port from path */
    char *path = strchr(host, PATH_DELIMITER);
    if(path){
        *path = '\0';
        path++;
    }else{
        path = "";
    }

    /* TODO: Split host and port */
    char *port;
    port = strchr(host, PORT_DELIMITER);

    if(port){
        *port = '\0';
        port++;
    }else{
        port = "80";
    }

    /* TODO: Allocate Request structure */
    Request *request = calloc(1, sizeof(Request));

    /* TODO: Copy components to URL structure */
    request->host = strdup(host);
    request->port = strdup(port);
    request->path = strdup(path);

    if ((!request->host) || (!request->port) || (!request->path)){
        return NULL;
    }
    return request;
}

/**
 * Deallocate Request structure.
 *
 * @param   request     Request structure to deallocate.
 **/
void	    request_delete(Request *request) {
    free(request->host);
    free(request->port);
    free(request->path);
    free(request);
}

/**
 * Make a HTTP request and write the contents of the response to the specified
 * stream.
 *
 * @param   url         Make a HTTP request to this URL.
 * @param   stream      Write the contents of response to this stream.
 *
 * @return  -1 on error, otherwise the number of bytes written.
 **/
ssize_t     request_stream(Request *request, FILE *stream) {
    /* TODO: Connect to remote host and port */
    FILE *client_stream = socket_dial(request->host, request->port);
    if(!client_stream){
        return -1;
    }

    /* TODO: Send request to server */
    fprintf(client_stream, "GET /%s HTTP/1.0\r\n", request->path);
    fprintf(client_stream, "Host: %s\r\n", request->host);
    fprintf(client_stream, "\r\n");

    /* TODO: Read response status from server */
    char buffer[BUFSIZ];

    fgets(buffer, BUFSIZ, client_stream);
    char *check = strstr(buffer, "200 OK");
    if(!check){
        return  -1;
    }

    /* TODO: Read response headers from server */
    ssize_t content_length = 0;
    while(fgets(buffer, BUFSIZ, client_stream)  && strlen(buffer) > 2){
        sscanf(buffer, "Content-Length: %lu", &content_length);
    }

    /* TODO: Read response body from server */
    size_t nread;
    while((nread = fread(buffer, 1, BUFSIZ, client_stream)) > 0){
        fwrite(buffer, 1, nread, stream);
    }
    /* TODO: Close connection */
    fclose(client_stream);

    /* TODO: Return number of bytes written and check if it matches Content-Length */

    return content_length;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
