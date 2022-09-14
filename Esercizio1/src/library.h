#ifndef LIBRARY_H
#define LIBRARY_H

void high_quicksort(void *, unsigned long size, int first, int last, int (*compare)(void *, void*));
void low_quicksort(void *, unsigned long size, int first, int last, int (*compare)(void *, void*));
void binary_insertion_sort(void *array, unsigned long size, unsigned long capacity, int (*compare)(void *, void *));

#endif