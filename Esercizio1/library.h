#ifndef LIBRARY_H
#define LIBRARY_H

void high_quicksort(void *, unsigned long size, int first, int last, int (*compare)(void *, void*));
void low_quicksort(void *, unsigned long size, int first, int last, int (*compare)(void *, void*));
//void mid_quicksort(void *, unsigned long size, int first, int last, int (*compare)(void *, void*));
//void rand_quicksort(void *, unsigned long size, int first, int last, int (*compare)(void *, void*));

#endif