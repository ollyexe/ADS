#ifndef LIBRARY_H_cwicnalsicnileaa
#define LIBRARY_H_cwicnalsicnileaa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HEIGHT 12

typedef struct _SkipList SkipList;
typedef struct _Node Node;

/**
 * insert generic element in a generic list 
 * @param list generic Skiplist 
 * @param I generic void element
 * @pre list cannot be NULL
 * @pre I must be a reference to a valid element
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
int insertSkipList(SkipList * list, void * I);

/**
 * search generic element in a due list 
 * @param list generic Skiplist 
 * @param I generic void element
 * @pre list cannot be NULL
 * @pre I must be a reference to a valid element
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
int searchSkipList(SkipList * list, void* I);

/**
 * create a generic Node
 * @param I generic element
 * @param lvl pointer's number of element
 * @pre I cannot be NULL
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
Node* createNode(void* I, unsigned int lvl);

/**
 * create a generic SkipList
 * @param compare pointer to a function which determines the precedence relation between the list elements.
 * It returns 1 iff the first element is greater than the second.
 * It returns -1 iff the first element is smaller than the second.
 * It returns 0 iff the first and the second elements are equal.
 * @pre compare cannot be NULL
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
SkipList* createSkipList(int(*compare)(void*, void*));

/**
 * delete a generic Node
 * @param n generic Node
 * @pre n cannot be NULL
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
void freeNode(Node* n);

/**
 * delete a generic SkipList
 * @param list generic SkipList
 * @pre list cannot be NULL
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
void freeSkipList(SkipList *list);
#endif /* LIBRARY_H_cwicnalsicnileaa */