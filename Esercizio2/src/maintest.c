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

/** skp_compare compare two generic elements
 * It returns 1 iff the first element is greater than the second.
 * It returns -1 iff the first element is smaller than the second.
 * It returns 0 iff the first and the second elements are equal.
 * @param it1 generic element
 * @param it2 generic element
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
int skp_compare(void* it1, void*it2){
  return strcmp((char*)it1, (char*)it2);
}
/** printSkipList print element of a generic list
 * @param list generic SkipList
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
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

/** load_dictionary load a file in a generic skiplist
 * @param list generic SkipList
 * @param fp pointer a opened file
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
void load_dictionary(SkipList* list, FILE* fp){  
  char buffer[BUFF_SIZE];
  char* riga;
  int i = 0;

  if(list == NULL){
    fprintf(stderr, "load_dictionary -> list NULL");
    exit(EXIT_FAILURE);
  }

  printf("Loading dictionary...\n");

  while(fgets(buffer, BUFF_SIZE, fp) != NULL){

    riga = malloc((strlen(buffer)) * sizeof(char*));
    if(riga == NULL){
      fprintf(stderr, "load_dictionary -> riga NULL");
      exit(EXIT_FAILURE);
    }

    strncpy(riga, buffer, strlen(buffer)-1);

    if(insertSkipList(list, riga) == -1){
      fprintf(stderr, "load_dictionary -> insertSkiplist -1\n");
      exit(EXIT_FAILURE);
    }

    i++;
    if((i % 100000) == 0){
      printf(".");
      fflush(stdout);
    }
  }
  printf("Dictionary loaded...\n");
}

/** checkme_file check if file's word (taken by a SkipList) are correct
 * It print the wrong word
 * @param list generic SkipList
 * @param fp pointer a opened file
 * @authors Alessio Chimento  &  Oliviu Gratii
 * */
static void checkme_file(SkipList* list, FILE* fp){
  char c;
  char string[35] = "";

  printf("Word to correct :\n");

  while((c = (char)fgetc(fp)) != EOF){

    if(IS_LETTER(c)){   
      c = (char)tolower(c);             
      strncat(string, &c, 1);  

    }else if(c == ' '){
      if(searchSkipList(list, string) == -1){ // return 0 if exist
        printf("%s\n", string);
      }

      strcpy(string, "");
    }
  }
  
  if (searchSkipList(list, string) == -1) {   // check last string
        printf("%s\n", string);
    }
    strcpy(string, "");
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
  fclose(fp1);
  
  fp2 = fopen(argv[2], "r");
  if(fp2 == NULL){
    fprintf(stderr, "main -> fp2 error\n");
    exit(EXIT_FAILURE);
  }
  checkme_file(list, fp2);
  //printSkipList(list);
  fclose(fp2);
  freeSkipList(list);
  
  return EXIT_SUCCESS;
}
