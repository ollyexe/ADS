#ifndef LIBRARY_H_cwicnalsicnileaa
#define LIBRARY_H_cwicnalsicnileaa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HEIGHT 6

typedef struct _SkipList SkipList;
typedef struct _Node Node;

void insertSkipList(SkipList * list, void * I);
void * searchSkipList(SkipList * list, void* I);

Node* createNode(void* I, unsigned int lvl);
SkipList* createSkipList(int(*compare)(void*, void*));

void freeNode(Node* n);
void freeSkipList(SkipList *list);
#endif /* LIBRARY_H_cwicnalsicnileaa */