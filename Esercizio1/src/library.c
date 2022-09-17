#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library.h"

/* function used to swap 2 records */

void swap(void *low, void *high, unsigned long size){   /* num of bytes to copy */
    void *tmp = malloc(size);                           /* temporary memory alocation */
    memcpy(tmp, low, size);                             /* copy dest from source (copy size bytes) */
    memcpy(low, high, size);
    memcpy(high, tmp, size);
}

// - - - - - - - - - - - - - - - HIGH QUICKSORT - - - - - - - - - - - - - - - -

static int high_partition(void *array, unsigned long  size, int low, int high, int (*compare)(void *, void *)){
    int j, i;
    char *pt = (char*)array;                
    void *pivot = pt + ((unsigned long)high * size);        /* pivot is always the last element in the array*/
    i = low;                                                /* i and j determine where the swap is gonna happen*/
    for(j = low; j < high; j++){                            /* if j < pivot then i++ */                                      
        if((*compare)((pt + ((unsigned long)j * size)), (void*) pivot) <= 0){               //* compare if j > pivot return 1  */     
            swap(pt + ((unsigned long)i * size), pt + ((unsigned long)j * size), size);     /* swap when I find an element (pos j) < pivot, so elements less than pivot are on left */
            i++;                                            /* increment because I have to find the right pivot position */                                                                          
        }
    }
    swap((char*)array + ((unsigned long)i * size), (void *) pivot, size); /* j no longer less than high so swap high with i (ordered pivot's position)*/
    return i;
}
void high_quicksort(void *array, unsigned long size, int low, int high, int (*compare)(void *, void *)){
    if(array == NULL){
        fprintf(stderr, "high_quicksort -> NULL array\n");
        exit(EXIT_FAILURE);
    }    
    if(low < high){
        int pivot = high_partition(array, size, low, high, compare); 
        high_quicksort(array, size, low, pivot - 1, compare);
        high_quicksort(array, size, pivot + 1, high, compare);
    }
}

// - - - - - - - - - - - - - BINARY INSERTION SORT - - - - - - - - - - -

static int binary_search(void *array, void *selected, int low, int high, unsigned long size, int (*compare)(void *, void *)){
    char *pt = (char*) array;
    if(high <= low) return (compare(selected, (pt + low*(int)size)) > 0) ? low+1 : low;
    int mid = (low+high)/2;
    if(compare(selected, pt + mid*(int)size) == 0) return mid+1;
    if(compare(selected, pt + mid*(int)size) > 0)
        return binary_search(array, selected, mid+1, high, size, compare);
    return binary_search(array, selected, low, mid-1, size, compare);
}

void binary_insertion_sort(void *array, unsigned long size, unsigned long capacity, int (*compare)(void *, void *)){
    if(array == NULL){
        fprintf(stderr, "binary_insertion_sort -> array NULL");
        exit(EXIT_FAILURE);
    }
    char *pt = (char *)array;

    for(int i = 1; i < (int)capacity; i++){
        int j = i - 1;
        void *selected = malloc(size);
        memcpy(selected, pt + (i * (int)size), size);
        int loc = binary_search(array, selected, 0, j, size, compare);  // return index
        while(j >= loc){
            memcpy(pt + ((j+1)*(int)size), pt + (j * (int)size), size);
            j--;
        }
        memcpy(pt + ((j+1)*(int)size), selected, size);
        free(selected);
    }
}
