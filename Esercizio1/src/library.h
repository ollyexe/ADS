#ifndef LIBRARY_H
#define LIBRARY_H

/**
 * Orders the array using the quick sort algorithm
 * @param array generic array 
 * @param size unsigned long dimension array's elements
 * @param first int index of the first array's element
 * @param last int index of the last array's elements
 * @param compare pointer to a function which determines the precedence relation between the array elements.
 * It returns 1 iff the first element is greater than the second.
 * It returns -1 iff the first element is smaller than the second.
 * It returns 0 iff the first and the second elements are equal.
 * @pre Array cannot be NULL
 * @pre *compare must be a reference to a valid function
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
void high_quicksort(void *, unsigned long size, int first, int last, int (*compare)(void *, void*));

/**
 * Orders the array using the quick sort algorithm
 * @param array generic array 
 * @param size unsigned long dimension array's elements
 * @param capacity unsigned long array elements's number
 * @param compare pointer to a function which determines the precedence relation between the array elements.
 * It returns 1 iff the first element is greater than the second.
 * It returns -1 iff the first element is smaller than the second.
 * It returns 0 iff the first and the second elements are equal.
 * @pre Array cannot be NULL
 * @pre *compare must be a reference to a valid function
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
void binary_insertion_sort(void *array, unsigned long size, unsigned long capacity, int (*compare)(void *, void *));

#endif