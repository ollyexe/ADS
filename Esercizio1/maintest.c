
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
    int capacity = 5;
    while(i < capacity){
        printf("%d ",a[i]);
        i++;
    }
    printf("\n");
}

static int int_cmp(void *id1, void *id2){
    if(*((int*)id1) < *((int*)id2)){
        return -1;
    }else if(*((int*)id1) == *((int*)id2)){
        return 0;
    }else 
        return 1;
}


int main (){
    int a[] = {0, 12, 3, 5, 1};
    puts("Print before quicksort...");
    print_array(a);
    quicksort(a, sizeof(int), 0, 4, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(a);

    int b[] = {15, 29, 2, 4, 11};
    puts("Print before quicksort...");
    print_array(b);
    quicksort(b, sizeof(int), 0, 4, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(b);

    int c[] = {12, 2, 9, 3, 4};
    puts("Print before quicksort...");
    print_array(c);
    quicksort(c, sizeof(int), 0, 4, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(c);

    int d[] = {12, 2, 9, 3, 12};
    puts("Print before quicksort...");
    print_array(d);
    quicksort(d, sizeof(int), 0, 4, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(d);

    int e[5];
    puts("Print before quicksort...");
    print_array(e);
    quicksort(e, sizeof(int), 0, 4, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(e);

    return 0;
}