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

// - - - - - - - - - - - - - - COMPARE FUNCTIONS - - - - - - - - - - -


static int int_cmp(void *r1, void *r2){
    Record *id1 = (Record *) r1;
    Record *id2 = (Record *) r2;
    if(id1->int_rec < 0 || id2->int_rec < 0){
        fprintf(stderr, "int_cmp -> int NULL\n");
        exit(EXIT_FAILURE);
    }
    if(id1->int_rec < id2->int_rec)
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

// - - - - - - - - - - - - - - CSV MANAGING - - - - - - - - - - - -

static void print_rec(Record *r, unsigned long capacity){
    for(long unsigned int i = 0; i < capacity; i++){
        printf("%10d, %15s, %15d, %16.8f\n", r[i].id_rec, r[i].str_rec, r[i].int_rec, r[i].doub_rec);
    }
    printf("\n");
}

static Record* load_file(FILE *fp, unsigned long *cap){
    long unsigned int i;
    char buffer[BUFFER_SIZE];
    unsigned long capacity = *cap;

    Record *csv = (Record*)malloc(sizeof(Record) * capacity);
    if(csv == NULL){
        fprintf(stderr, "LOAD_FILE -> csv NULL in malloc\n");
        exit(EXIT_FAILURE);
    }

    clock_t starttime = clock();
    
    printf("Loading file...\n");
    fflush(stdout);
    for(i = 0; fgets(buffer, BUFFER_SIZE, fp) != NULL && i < 10; i++){
        // alloca memoria
        char *riga = malloc(sizeof(char*)*(strlen(buffer)+1));
        // controllo se memoria è allocata
        if(riga == NULL){
            fprintf(stderr, "LOAD_FILE -> riga NULL\n");
            exit(EXIT_FAILURE);
        }
        
    // tokenizzo la riga
        strcpy(riga, buffer); // dest -> src copio riga nel buffer
        char* tmp_id = strtok(riga, ",");
        char* tmp_str = strtok(NULL, ",");
        char* tmp_int = strtok(NULL, ",");
        char* tmp_dbl = strtok(NULL, ",");

    char* strcpyed = malloc((strlen(tmp_str)+1) * sizeof(char*));
    if(strcpyed == NULL){
            fprintf(stderr, "LOAD_FILE -> strcpyed NULL\n");
            exit(EXIT_FAILURE);
    }
    // check se c'è abbastanza capienza nell'array e realloc
        if(i == capacity){
            capacity *= 2;          // tengo aggiornata la capacity
            csv = realloc(csv, sizeof(Record) * capacity);
            if(csv == NULL){
            fprintf(stderr, "LOAD_FILE -> csv NULL in realloc\n");
            exit(EXIT_FAILURE);
            }
        }
        
    
        // inserisco i valori nel record
        
        csv[i].id_rec = atoi(tmp_id);
        strcpy(strcpyed, tmp_str);
        csv[i].str_rec = strcpyed;
        csv[i].int_rec = atoi(tmp_int);
        csv[i].doub_rec = atof(tmp_dbl);
        
        
        if(i%1000000 == 0){
            printf(".");
            fflush(stdout);
        }
        free(riga);
    }
    *cap = i;
    printf("File correctly loaded\n");
    
    clock_t endtime = clock();
    printf("Time spent on loading %2.fs\n", (double)(endtime - starttime)/CLOCKS_PER_SEC);
    fflush(stdout);
    
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

    if(argc < 2){
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

    if (strcmp(argv[2], "qui") == 0){
        high_quicksort(csv, sizeof(Record), 0, (int)capacity-1, int_cmp);
        print_rec(csv, capacity);
        high_quicksort(csv, sizeof(Record), 0, (int)capacity-1, dbl_cmp);
        print_rec(csv, capacity);
        high_quicksort(csv, sizeof(Record), 0, (int)capacity-1, str_cmp);
        print_rec(csv, capacity);
    }else if(strcmp(argv[2], "bin") == 0){
        binary_insertion_sort(csv, sizeof(Record), capacity, int_cmp);
        print_rec(csv, capacity); 
        binary_insertion_sort(csv, sizeof(Record), capacity, dbl_cmp);
        print_rec(csv, capacity);
        binary_insertion_sort(csv, sizeof(Record), capacity, str_cmp);
        print_rec(csv, capacity);
        
    }

    free_file(csv, capacity);
    fclose(fp);
    printf("execution ended\n");

    exit(EXIT_SUCCESS);
}