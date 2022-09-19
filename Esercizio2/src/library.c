#include "library.h"

struct _SkipList {
  Node *head;
  unsigned int max_level;   
  int (*compare)(void*, void*);
};
struct _Node {
  Node **next;
  unsigned int size;    //random level
  void *item;
};

static unsigned int randomLevel(){
    unsigned int lvl = 1;
    // random() returns a random value in [0...1)
    srand((unsigned)time(NULL));    // reset seed
    while ((rand() % 2) < 0.5 && lvl < MAX_HEIGHT) {
        lvl = lvl + 1;
    }  
    return lvl;
}

Node* createNode(void *I, unsigned int lvl){
    Node* n =(Node*)malloc(sizeof(Node));
    n->next = (Node**)malloc(sizeof(Node)*lvl);
    n->size = lvl;       // random level
    n->item = I;
    return n;
}

SkipList* createSkipList(int(*compare)(void*, void*)){
    SkipList* list = malloc(sizeof(SkipList));
    list->head = createNode(NULL,MAX_HEIGHT);
    list->max_level = 1;
    list->compare = compare;
    return list;
}

void insertSkipList(SkipList * list, void * I){
    Node *new , *x; 
    new = createNode(I, randomLevel());
    if (new->size > list->max_level)
       { //se il numero di puntatori e maggiore di quello attuale della lista
        // la size del nodo diventa la piu grande della lista
        list->max_level = new->size;
       }

    x = list->head;
    
    for(unsigned int k = list->max_level; k >= 1; k--){   // k down to 1
        if (x->next[k] == NULL || (list->compare(I, x->next[k]->item) < 0)){ // (I < x->next[k]->item) return -1
            if (k < new->size) {
              new->next[k] = x->next[k];
              x->next[k] = new;
            }
        }else{
            x = x->next[k];
            k++;
        }
    }
}

void* searchSkipList(SkipList *list, void *I){
    unsigned int i;
    Node* x;
    x = list->head;
    if(list == NULL || I == NULL){
        fprintf(stderr, "searchSkiplist -> argument NULL");
    }
    // loop invariant: x->item < I
    for (i = list->max_level; i >= 1 ;i--)
     {
        while (list->compare(x->next[i]->item, I) < 0)   // x->next[i]->item < I 
       {
         x = x->next[i];
       }
    }
    printf("i am here\n");
    // x->item < I <= x->next[1]->item
    x = x->next[1];

    if(list->compare(x->item, I) == 0){ // x->item == I
        return x->item;
    }
    else{
        exit(EXIT_FAILURE);
    }    
}

void freeNode(Node *n) {
    free(n->item);
    //n->item = NULL;
    free(n->next);
    free(n);
    //n = NULL;
}

void freeSkipList(SkipList *list){
    Node* current = list->head;
    Node* next = NULL;

    printf("\nDeleting SkipList ...\n");
    while (current) {
        next = current->next[0];
        freeNode(current);
        current = next;
    }
    printf("\nSkipList Deleted!\n");
}