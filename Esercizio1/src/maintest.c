#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library.h"

#define INIT_SIZE   2
#define BUFFER_SIZE 1024

// - - - - - - - - - - RECORD STRUCT - - - - - - - - - - - - -

typedef struct _Record {
	int		id_rec;	        // id
	char	*str_rec;	    // string
	int 	int_rec;	    // integer
	double 	doub_rec;       // double
}Record;				
/*
void print_array(int a[]){
    int i = 0;
    int capacity = 10;
    while(i < capacity){
        printf("%d ",a[i]);
        i++;
    }
    printf("\n");
}

static int int_cmpp(void *id1, void *id2){
    if(*((int*)id1) < *((int*)id2)){
        return -1;
    }else if(*((int*)id1) == *((int*)id2)){
        return 0;
    }else 
        return 1;
}*/

// - - - - - - - - - - - - - - COMPARE FUNCTIONS - - - - - - - - - - -
/*
static int id_cmp(void *r1, void *r2){
    Record *id1 = (Record *) r1;
    Record *id2 = (Record *) r2;
    if(id1->id_rec < 0 || id2->id_rec < 0){
        fprintf(stderr, "id_cmp -> id NULL\n");
        exit(EXIT_FAILURE);
    }else if(id1->id_rec < id2->id_rec)
        return -1;
    else if(id1->id_rec == id2->id_rec)
        return 0;
    else
        return 1;
}

static int int_cmp(void *r1, void *r2){
    Record *id1 = (Record *) r1;
    Record *id2 = (Record *) r2;
    if(id1->int_rec < 0 || id2->int_rec < 0){
        fprintf(stderr, "int_cmp -> int NULL\n");
        exit(EXIT_FAILURE);
    }else if(id1->int_rec < id2->int_rec)
        return -1;
    else if(id1->int_rec == id2->int_rec)
        return 0;
    else 
        return 1;
}

static int dbl_cmp(void *r1, void *r2){
    Record *id1 = (Record *)r1;
    Record *id2 = (Record *)r2;
    if(id1->doub_rec < 0 || id2->doub_rec < 0){
        fprintf(stderr, "dbl_cmp -> double NULL\n");
        exit(EXIT_FAILURE);
    }
    if(id1->doub_rec < id2->doub_rec)
        return -1;
    else if(id1->doub_rec == id2->doub_rec)
        return 0;
    else
        return 1;
}

static int str_cmp(void *r1, void *r2){
    Record *id1 = (Record *)r1;
    Record *id2 = (Record *)r2;
    if(id1->str_rec == NULL || id2->str_rec == NULL){
        fprintf(stderr, "str_cmp -> string is NULL\n");
        exit(EXIT_FAILURE);
    }
    return strcmp(id1->str_rec, id2->str_rec);  // return 0 if equal --- return -1 if str1 < str2 --- return 1 if str1 > str2
}
*/
// - - - - - - - - - - - - - - CSV MANAGING - - - - - - - - - - - -
/*

static void print_rec(Record *r, unsigned long capacity){
    for(long unsigned int i = 0; i < capacity; i++){
        printf("%10d, %15s, %15d, %16.8f\n", r[i].id_rec, r[i].str_rec, r[i].int_rec, r[i].doub_rec);
    }
}
*/
static Record* load_file(FILE *fp, unsigned long *cap){
    long unsigned int i;
    char buffer[BUFFER_SIZE];
    unsigned long capacity = *cap;

    clock_t starttime = clock();

    Record *csv = (Record*)malloc(sizeof(Record) * capacity);
    if(csv == NULL){
        fprintf(stderr, "LOAD_FILE -> csv NULL in malloc\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Loading file...\n");
    for(i = 0; fgets(buffer, BUFFER_SIZE, fp) != NULL; i++){
        // alloca memoria
        char *riga = malloc(sizeof(char*)*strlen(buffer));
        // controllo se memoria è allocata
        if(riga == NULL){
            fprintf(stderr, "LOAD_FILE -> riga NULL\n");
            exit(EXIT_FAILURE);
        }
        
    // tokenizzo la riga
        strcpy(riga, buffer); // dest -> src copio riga nel buffer
        char *tmp_id = strtok(riga, ",");
        char *tmp_str = strtok(NULL, ",");
        char *tmp_int = strtok(NULL, ",");
        char *tmp_dbl = strtok(NULL, ",");

    // check se c'è abbastanza capienza nell'array e realloc
        if(i == capacity){
            capacity *= 2;          // tengo aggiornata la capacity
            csv = realloc(csv, sizeof(Record) * capacity);
        }
        if(csv == NULL){
            fprintf(stderr, "LOAD_FILE -> csv NULL in realloc\n");
            exit(EXIT_FAILURE);
        }
    
        // inserisco i valori nel record
        csv[i].id_rec = atoi(tmp_id);
        csv[i].str_rec = tmp_str;
        csv[i].int_rec = atoi(tmp_int);
        csv[i].doub_rec = atoi(tmp_dbl);
        
        free(riga);
        if(i%1000000 == 0)
            printf("%ld\n", i);
        *cap = i;
    }

    clock_t endtime = clock();
    printf("Time spent on loading %2.fs\n", (double)(endtime - starttime)/CLOCKS_PER_SEC);

    printf("File correctly loaded\n");
    return csv;
}

static void free_file(Record *csv, unsigned long capacity){
    unsigned long i;
    printf("Cleaning memory...\n");
    for(i = 0; i < capacity; i++){
        free(csv[i].str_rec);
    }
    free(csv);
    printf("Memory succesfully cleaned...\n");
}



int main (int argc, char **argv){

    unsigned long int capacity = INIT_SIZE;

    if(argc < 1){
        fprintf(stderr, "Main -> argc error\n");
        exit(EXIT_FAILURE);
    }
    
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        fprintf(stderr, "MAIN -> Error opening file...");
        exit(EXIT_FAILURE);
    }

    Record *csv = load_file(fp, &capacity);
    if(capacity <= 0){
        fprintf(stderr, "Main -> capacity <= 0");
        exit(EXIT_FAILURE);
    }
    if(fp == NULL){
        fprintf(stderr, "Main -> fp is NULL");
        exit(EXIT_FAILURE);
    }

    free_file(csv, capacity);
    fclose(fp);
    printf("execution ended\n");



    /*  TESTING HIGH QUICKSORT  */  /* EVERYTHING OK */
/*
    int a[] = {0, 12, 3, 5, 1, 6, 23, 97, 46, 8};
    puts("Print before quicksort...");
    print_array(a);
    high_quicksort(a, sizeof(int), 0, 9, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(a);

    int b[] = {15, 29, 2, 23, 97, 46, 8, 4, 11};
    puts("Print before quicksort...");
    print_array(b);
    high_quicksort(b, sizeof(int), 0, 9, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(b);

    int c[] = {12, 23, 97, 46, 8, 2, 9, 3, 4};
    puts("Print before quicksort...");
    print_array(c);
    high_quicksort(c, sizeof(int), 0, 9, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(c);

    int d[] = {12, 2, 9, 3, 23, 97, 46, 8, 12};
    puts("Print before quicksort...");
    print_array(d);
    high_quicksort(d, sizeof(int), 0, 9, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(d);

    int e[5];
    puts("Print before quicksort...");
    print_array(e);
    high_quicksort(e, sizeof(int), 0, 9, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(e);
*/

    /*  TESTING LOW QUICKSORT   */  /* EVERYTHING OK */
/*
    int a[] = {0, 12, 3, 5, 1, 6, 23, 97, 46, 8};
    puts("Print before quicksort...");
    print_array(a);
    low_quicksort(a, sizeof(int), 0, 9, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(a);

    int b[] = {15, 29, 2, 23, 97, 46, 8, 4, 11};
    puts("Print before quicksort...");
    print_array(b);
    low_quicksort(b, sizeof(int), 0, 9, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(b);

    int c[] = {12, 23, 97, 46, 8, 2, 9, 3, 4};
    puts("Print before quicksort...");
    print_array(c);
    low_quicksort(c, sizeof(int), 0, 9, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(c);

    int d[] = {12, 2, 9, 3, 23, 97, 46, 8, 12};
    puts("Print before quicksort...");
    print_array(d);
    low_quicksort(d, sizeof(int), 0, 9, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(d);

    int e[5];
    puts("Print before quicksort...");
    print_array(e);
    low_quicksort(e, sizeof(int), 0, 9, int_cmp); // capacity - 1
    puts("Print after quicksort...");
    print_array(e);
*/

    // BINARY INSERTION SORT
/*
    
    int a[] = {0, 12, 3, 5, 1, 6, 23, 97, 46, 8};
    //puts("Print before binary_insertion_sort...");
    //print_array(a);
    binary_insertion_sort(a, sizeof(int), 10, int_cmpp);
    puts("Print after binary_insertion_sort...");
    print_array(a);

    int b[] = {15, 29, 2, 23, 97, 46, 8, 4, 11};
    //puts("Print before binary_insertion_sort...");
    //print_array(b);
    binary_insertion_sort(b, sizeof(int), 10, int_cmpp);
    puts("Print after binary_insertion_sort...");
    print_array(b);

    int c[] = {12, 23, 97, 46, 8, 2, 9, 3, 4};
    //puts("Print before binary_insertion_sort...");
    //print_array(c);
    binary_insertion_sort(c, sizeof(int), 10, int_cmpp);
    puts("Print after binary_insertion_sort...");
    print_array(c);

    int d[] = {12, 2, 9, 3, 23, 97, 46, 8, 12};
    //puts("Print before binary_insertion_sort...");
    //print_array(d);
    binary_insertion_sort(d, sizeof(int), 10, int_cmpp);
    puts("Print after binary_insertion_sort...");
    print_array(d);

    int e[5];
    //puts("Print before binary_insertion_sort...");
    //print_array(e);
    binary_insertion_sort(e, sizeof(int), 10, int_cmpp);
    puts("Print after binary_insertion_sort...");
    print_array(e);
*/
    exit(EXIT_SUCCESS);
}