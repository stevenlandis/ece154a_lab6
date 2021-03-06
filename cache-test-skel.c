/*
Steven Landis
ECE 154A - Fall 2018
Lab 6 - Mystery Caches

Mystery Cache Geometries:
mystery0:
        block size = 64 bytes
        cache size = 4194304 bytes
        associativity = 16
mystery1:
        block size = 4 bytes
        cache size = 4096 bytes
        associativity = 1
mystery2:
        block size = 32 bytes
        cache size = 4096 bytes
        associativity = 128
*/

#include <stdlib.h>
#include <stdio.h>

#include "mystery-cache.h"

/* 
     Returns the size (in B) of the cache
*/
int get_cache_size(int block_size) {
    /* YOUR CODE GOES HERE */
    int i = 0;
    int size = 2*block_size;
    while (1) {
        access_cache(i);

        if (i > size) {
            // check previous cache hits to see when overwritten
            for (int j = 0; j < i; j += block_size) {
                if (!access_cache(j)) {
                    return i-block_size;
                }
            }
            size *= 2;
        }
        

        i += block_size;
    }
    return -1;
}

/*
     Returns the associativity of the cache
*/
int get_cache_assoc(int size) {
    // test for cache associacivity:
    int i = 0;
    while (1) {
        access_cache(i);

        // check previous cache hits to see when overwritten
        for (int j = 0; j < i; j += size) {
            if (!access_cache(j)) {
                return i/size;
            }
        }

        i += size;
    }
}

/*
     Returns the size (in B) of each block in the cache.
*/
int get_block_size() {
    /* YOUR CODE GOES HERE */
    flush_cache();
    access_cache(0);
    int i = 1;
    while (access_cache(i)) {
        i++;
    }
    return i;
}

int main(void) {
    int size;
    int assoc;
    int block_size;
    
    /* The cache needs to be initialized, but the parameters will be
         ignored by the mystery caches, as they are hard coded.
         You can test your geometry paramter discovery routines by 
         calling cache_init() w/ your own size and block size values. */
    cache_init(0,0);
    
    block_size = get_block_size();
    printf("Cache block size: %d bytes\n",block_size);
    size = get_cache_size(block_size);
    printf("Cache size: %d bytes\n",size);
    assoc = get_cache_assoc(size);
    printf("Cache associativity: %d\n",assoc);
    
    
    return EXIT_SUCCESS;
}
