#include "library.h"


#define MAX_HEIGHT 0

typedef struct _SkipList SkipList;
typedef struct _Node Node;

struct _SkipList {
  Node *head;
  unsigned int max_level;
  int (*compare)(void*, void*);
}List;

struct _Node {
  Node **next;
  unsigned int size;
  void *item;
};







int main (){

    createSkipList()









}
