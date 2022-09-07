#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library.h"

/* function used to swap 2 records */

void swap(void *low, void *high, unsigned long size){ /* num of bytes to copy*/

    void *tmp = malloc(size);

    memcpy(tmp, low, size);     /* copy dest from source (copy size bytes)*/
    memcpy(low, high, size);
    memcpy(high, tmp, size);
}

static int partition(void *array, unsigned long  size, int low, int high, int (*compare)(void *, void *)){
    int j, i;
    char *pt = (char*)array;                /* copy so I can calculate element position*/ /* use char* because can do the cast*/
    void *pivot = pt + (high * size);       /* pivot is always the last element in the array*/
    i = low;                            /* i and j determine where the swap is gonna happen*/

    for(j = low; j < high; j++){
        
        if((*compare)((pt + ((unsigned long)j * size)), (void*) pivot) <= 0){           
            swap(pt + ((unsigned long)i * size), pt + ((unsigned long)j * size), size);     /* swap when I find an element (pos j) < pivot, so elements less than pivot are on left*/
            i++;                                                                            /* increment because I have to find the right pivot position*/
        }
    }

    swap(pt + ((unsigned long)i * size), (void *) pivot, size); /* j no more less than high so swap high with i (ordered pivot's position)*/

    return i;
}

void quicksort(void *array, unsigned long size, int low, int high, int (*compare)(void *, void *)){
    if(array == NULL){
        fprintf(stderr, "quicksort -> NULL array\n");
        exit(EXIT_FAILURE);
    }
    if(low < high){
        int pivot = partition(array, size, low, high, compare); 
        quicksort(array, size, low, pivot - 1, compare);
        quicksort(array, size, pivot + 1, high, compare);
    }
}