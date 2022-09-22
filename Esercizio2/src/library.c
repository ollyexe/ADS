#include "library.h"

/**
 * @param head pointer at the first SkipList's Node
 * @param max_level unsogned int max level the SkipList can archive
 * @param compare pointer to a function which determines the precedence relation between the list elements.
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
struct _SkipList {
  Node *head;
  unsigned int max_level;   
  int (*compare)(void*, void*);
};

/**
 * @param next pointer at the next Node
 * @param size random size level
 * @param item pointer at the Node's element.
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
struct _Node {
  Node **next;
  unsigned int size;    
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
    SkipList* list = (SkipList*)malloc(sizeof(SkipList));
    list->head =(Node*)malloc(sizeof(Node));
    list->head = createNode(NULL,MAX_HEIGHT);
    list->max_level = 1;
    list->compare = compare;
    return list;
}

int insertSkipList(SkipList * list, void * I){
    Node *new , *x; 
    new = createNode(I, randomLevel());
    if(new == NULL){
        return -1;
    }
    if (new->size > list->max_level)
       { //se il numero di puntatori e maggiore di quello attuale della lista
        // la size del nodo diventa la piu grande della lista
        list->max_level = new->size;
       }

    x = list->head;
    
    for(int k = (int)(list->max_level-1); k >= 0; k--){   
        if (x->next[k] == NULL || (list->compare(I, x->next[k]->item) < 0)){ // (I < x->next[k]->item) return -1
            if (k < (int)new->size) {
              new->next[k] = x->next[k];
              x->next[k] = new;
            }
        }else{
            x = x->next[k];
            k++;
        }
    }
    return 1;
}

int searchSkipList(SkipList *list, void *I){
    int i;
    Node* x;
    x = list->head;
    if(list == NULL || I == NULL){
        fprintf(stderr, "searchSkiplist -> argument NULL");
    }
    // loop invariant: x->item < I
    for (i = (int)(list->max_level-1); i >= 0 ;i--)
     {
        while (x->next[i] != NULL && (list->compare(x->next[i]->item, I) < 0))   // x->next[i]->item < I 
       {
         x = x->next[i];
       }
    }
    // x->item < I <= x->next[1]->item
    x = x->next[0];

    if(x->next[i] != NULL && list->compare(x->item, I) == 0){ // x->item == I
        return 0;       // return 0 if I found
    }
    else{
        return -1;
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
