#include "library.h"
#include <ctype.h>
#define BUFF_SIZE 1024
#define IS_LETTER(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z'))

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

int skp_compare(void* it1, void*it2){
  return strcmp((char*)it1, (char*)it2);
}
/*
void printSkipList(SkipList* list) {
    Node* x = list->head;
    for (int i = 0; i < (int)list->max_level; i++) {
        while (x != NULL && x->next[i] != NULL) {
            printf("[%s]->", (char*)(x->next[i]->item));
            x = x->next[i];
        }
        printf("NIL\n");
    }
}
*/
void load_dictionary(SkipList* list, FILE* fp){   // fp have to be already opened
  char buffer[BUFF_SIZE];
  char* riga;
  int i = 0;
  if(list == NULL){
    fprintf(stderr, "load_dictionary -> list NULL");
    exit(EXIT_FAILURE);
  }
  printf("Loading dictionary...\n");
  while(fgets(buffer, BUFF_SIZE, fp) != NULL && i < 100){
    riga = malloc((strlen(buffer)) * sizeof(char*));
    if(riga == NULL){
      fprintf(stderr, "load_dictionary -> riga NULL");
      exit(EXIT_FAILURE);
    }
    strncpy(riga, buffer, strlen(buffer)); // vengono copiati al più n caratteri
    insertSkipList(list, riga);
    i++;
    if((i % 100000) == 0){
      printf(".");
      fflush(stdout);
    }
  }
  printf("Dictionary loaded...\n");
}

static void checkme_file(SkipList* list, FILE* fp){
  char c;
  char string[35];
  while((c = (char)fgetc(fp)) != EOF){
    printf("B%c\n", c);
    if(IS_LETTER(c)){   // return 0 if c is not alphabetic  /* ERROR HEREEEE /*
      c = (char)tolower(c);               // all char in loewr case
      strncat(string, &c, 1);  // concatenate char
      printf("A%s\n", string);
    }else if(c == ' '){
      if(searchSkipList(list, string) == -1){ // return 0 if exist
        printf("ok man\n");
        printf("%s\n", string);
      }
    }
    strcpy(string, "");
  }
}

int main (int argc, char **argv){
  SkipList *list;
  FILE *fp1, *fp2;

  if(argc < 2){
    fprintf(stderr, "main -> argc error\n");
    exit(EXIT_FAILURE);
  }

  fp1 = fopen(argv[1], "r");
  if(fp1 == NULL){
    fprintf(stderr, "main -> fp1 error\n");
    exit(EXIT_FAILURE);
  }

  list = createSkipList(skp_compare);
  load_dictionary(list, fp1);
  
  
  fp2 = fopen(argv[2], "r");
  if(fp2 == NULL){
    fprintf(stderr, "main -> fp2 error\n");
    exit(EXIT_FAILURE);
  }
  checkme_file(list, fp2);
  //printSkipList(list);
  freeSkipList(list);
  
}
