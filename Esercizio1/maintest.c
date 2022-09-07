
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library.h"

#define INIT_SIZE   2
#define BUFFER_SIZE 1024

typedef struct _Record {
	int		id_record;	// 4 bytes
	char	*str_rec;	// 8 bytes
	int 	int_rec;	// 4 bytes
	double 	doub_rec;	// 8 bytes
}Record;				// 32 bytes

/*
int find_capacity(int a[]){
    return (int)(sizeof(a[0])/sizeof(int)); 
}*/

void print_array(int a[]){
    int i = 0;
    int capacity = 6;
    while(i < capacity){
        printf("%d ",a[i]);
        i++;
    }
    printf("\n");
}

static int int_cmp(void *id1, void *id2){
    return (int *)id1 - (int *)id2;
}

/*
static int id_cmp(void *r1, void *r2){
	Row *id1 = (Row*)r1;
	Row *id2 = (Row*)r2;
	if(id1->id_row < 0 || id2->id_row < 0) fprintf(stderr, "errore id null");
	return id1->id_row - id2->id_row;
}
*/


int main (){
    int a[] = {3, 4, 1, 0, 12, 10};
    puts("Print before quicksort...");
    print_array(a);
    quicksort(a, sizeof(int), 0, 5, int_cmp);
    puts("Print after quicksort...");
    print_array(a);

    return 0;
}