/* hash.c: hash functions */

#include "hash.h"

#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>


/**
 * Constants
 * http://isthe.com/chongo/tech/comp/fnv/
 */

#define FNV_OFFSET_BASIS    (0xcbf29ce484222325ULL)
#define FNV_PRIME           (0x100000001b3ULL)

/**
 * Compute FNV-1 hash.
 * @param   data            Data to hash.
 * @param   n               Number of bytes in data.
 * @return  Computed hash as 64-bit unsigned integer.
 */
uint64_t    hash_from_data(const void *data, size_t n) {
    uint8_t *bytes = (uint8_t *)data;
    uint64_t hash = FNV_OFFSET_BASIS;
    for (int i = 0; i < n; i++){
        hash = hash ^ bytes[i];
        hash = hash * FNV_PRIME;
    }
    return hash;
}

/**
 * Compute SHA1 digest.
 * @param   path            Path to file to checksum.
 * @param   hexdigest       Where to store the computed checksum in hexadecimal.
 * @return  Whether or not the computation was successful.
 */

bool        hash_from_file(const char *path, char hexdigest[HEX_DIGEST_LENGTH]) {
    /* Stat file */
    struct stat st;
    stat(path, &st);
    off_t size = st.st_size;
    if (size < 0){
        return false;
    }
    /* Open file for reading */
    FILE *stream;
    stream = fopen(path, "r");
    if(!stream){
        return false;
    }

    /* Allocate data buffer */
    uint8_t*  data = malloc(size);
    if (!data){
        return false;
    }

    /* Read data into buffer */
    fread(data, size, 1, stream);
    if(!data){
        free(data);
        return false;
    }

    unsigned char raw_digest[SHA_DIGEST_LENGTH];
    /* Compute raw SHA1 digest */
    SHA1(data, size, raw_digest);
    if(!data){
        free(data);
        return false;
    }

    /* Convert raw SHA1 digest to hexadecimal digest */
    for(int i = 0; i < SHA_DIGEST_LENGTH; i++){
        sprintf(hexdigest + i*2, "%02x", raw_digest[i]);
    }
    free(data);
    
    return true;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
