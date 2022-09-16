#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

typedef struct _Record {
	int		id_rec;	        // id
	char	*str_rec;	    // string
	int 	int_rec;	    // integer
	double 	doub_rec;       // double
}Record;

static int int_cmp(void *r1, void *r2){
    Record *id1 = (Record *) r1;
    Record *id2 = (Record *) r2;
    /*if(id1->int_rec < 0 || id2->int_rec < 0){
        fprintf(stderr, "int_cmp -> int NULL\n");
        exit(EXIT_FAILURE);
    }else */if(id1->int_rec < id2->int_rec)
        return -1;
    else if(id1->int_rec == id2->int_rec)
        return 0;
    else 
        return 1;
}

static int dbl_cmp(void *r1, void *r2){
    Record *id1 = (Record *)r1;
    Record *id2 = (Record *)r2;
    /*if(id1->doub_rec < 0 || id2->doub_rec < 0){
        fprintf(stderr, "dbl_cmp -> double NULL\n");
        exit(EXIT_FAILURE);
    }*/
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
    /*if(id1->str_rec == NULL || id2->str_rec == NULL){
        fprintf(stderr, "str_cmp -> string is NULL\n");
        exit(EXIT_FAILURE);
    }*/
    return strcmp(id1->str_rec, id2->str_rec);  // return 0 if equal --- return -1 if str1 < str2 --- return 1 if str1 > str2
}

// - - - - - - - - - - - - - - - - - NULL TEST - - - - - - - - - - - - - - - - - - -

// QUICK SORT

static void null_quicksort_int_test(void){
    Record *a = NULL;
    high_quicksort((void*)a, sizeof(Record), 0, 0, int_cmp);
}
static void null_quicksort_dbl_test(void){
    Record *a = NULL;
    high_quicksort((void*)a, sizeof(Record), 0, 0, dbl_cmp);
}
static void null_quicksort_str_test(void){
    Record *a = NULL;
    high_quicksort((void*)a, sizeof(Record), 0, 0, str_cmp);
}

// BINARY INSERTION SORT

static void null_binsertion_int_test(void){
    Record *a = NULL;
    binary_insertion_sort((void *)a, sizeof(Record), 0, int_cmp);
}

static void null_binsertion_dbl_test(void){
    Record *a = NULL;
    binary_insertion_sort((void *)a, sizeof(Record), 0, dbl_cmp);
}

static void null_binsertion_str_test(void){
    Record *a = NULL;
    binary_insertion_sort((void *)a, sizeof(Record), 0, str_cmp);
}

// - - - - - - - - - - - - - - - - - EMPTY TEST - - - - - - - - - - - - - -

// QUICK SORT

static void empty_quicksort_int_test(void){
    Record a[2];

    a[0].id_rec = 0;
    a[0].str_rec = "";
    a[0].int_rec = -3;
    a[0].doub_rec = -2.5;
    a[1].id_rec = 1;
    a[1].str_rec = "";
    a[1].int_rec = -1;
    a[1].doub_rec = -1.5;

    high_quicksort((void*)&a, sizeof(Record), 0, sizeof(a)/(sizeof(Record)), int_cmp);
}
static void empty_quicksort_dbl_test(void){
    Record a[2];

    a[0].id_rec = 0;
    a[0].str_rec = "";
    a[0].int_rec = -3;
    a[0].doub_rec = -2.5;
    a[1].id_rec = 1;
    a[1].str_rec = "";
    a[1].int_rec = -1;
    a[1].doub_rec = -1.5;

    high_quicksort((void*)a, sizeof(Record), 0, sizeof(a)/(sizeof(Record)), dbl_cmp);
}
static void empty_quicksort_str_test(void){
    Record a[2];

    a[0].id_rec = 0;
    a[0].str_rec = "";
    a[0].int_rec = -3;
    a[0].doub_rec = -2.5;
    a[1].id_rec = 1;
    a[1].str_rec = "";
    a[1].int_rec = -1;
    a[1].doub_rec = -1.5;

    high_quicksort((void*)a, sizeof(Record), 0, sizeof(a)/(sizeof(Record)), str_cmp);
}

// BINARY INSERTION SORT

static void empty_binsertion_int_test(void){
    Record a[2];

    a[0].id_rec = 0;
    a[0].str_rec = "";
    a[0].int_rec = -3;
    a[0].doub_rec = -2.5;
    a[1].id_rec = 1;
    a[1].str_rec = "";
    a[1].int_rec = -1;
    a[1].doub_rec = -1.5;

    binary_insertion_sort((void*)a, sizeof(Record), sizeof(a)/(sizeof(Record)), int_cmp);
}

static void empty_binsertion_dbl_test(void){
    Record a[2];

    a[0].id_rec = 0;
    a[0].str_rec = "";
    a[0].int_rec = -3;
    a[0].doub_rec = -2.5;
    a[1].id_rec = 1;
    a[1].str_rec = "";
    a[1].int_rec = -1;
    a[1].doub_rec = -1.5;

    binary_insertion_sort((void*)a, sizeof(Record), sizeof(a)/(sizeof(Record)), dbl_cmp);}

static void empty_binsertion_str_test(void){
    Record a[2];

    a[0].id_rec = 0;
    a[0].str_rec = "";
    a[0].int_rec = -3;
    a[0].doub_rec = -2.5;
    a[1].id_rec = 1;
    a[1].str_rec = "";
    a[1].int_rec = -1;
    a[1].doub_rec = -1.5;

    binary_insertion_sort((void*)a, sizeof(Record), sizeof(a)/(sizeof(Record)), str_cmp);
}

static void full_quicksort_test(void){
    Record a[3];
    Record b[3];

    a[0].id_rec = 0;
    a[0].str_rec = "mario";
    a[0].int_rec = 54;
    a[0].doub_rec = 9.34;
    a[1].id_rec = 1;
    a[1].str_rec = "alcio";
    a[1].int_rec = 540;
    a[1].doub_rec = 129.4;
    a[2].id_rec = 2;
    a[2].str_rec = "fratm";
    a[2].int_rec = 4;
    a[2].doub_rec = 91.34;

    b[0].id_rec = 0;
    b[0].str_rec = "alcio";
    b[0].int_rec = 4;
    b[0].doub_rec = 9.34;
    b[1].id_rec = 1;
    b[1].str_rec = "fratm";
    b[1].int_rec = 54;
    b[1].doub_rec = 91.34;
    b[2].id_rec = 2;
    b[2].str_rec = "mario";
    b[2].int_rec = 540;
    b[2].doub_rec = 129.4;

    high_quicksort((void*)&a, sizeof(Record), 0, sizeof(a)/(sizeof(Record)), int_cmp);
    for(long i = 0; i < (int)(sizeof(a)/(sizeof(Record))); i++) assert(a[i].int_rec == b[i].int_rec);
    
    high_quicksort((void*)&a, sizeof(Record), 0, sizeof(a)/(sizeof(Record)), dbl_cmp);
    for(long i = 0; i < (int)(sizeof(a)/(sizeof(Record))); i++) assert(a[i].doub_rec == b[i].doub_rec);

    high_quicksort((void*)&a, sizeof(Record), 0, sizeof(a)/(sizeof(Record)), str_cmp);
    for(long i = 0; i < (int)(sizeof(a)/(sizeof(Record))); i++) assert(a[i].str_rec == b[i].str_rec);
}

static void full_binsertion_test(void){
   Record a[3];
    Record b[3];

    a[0].id_rec = 0;
    a[0].str_rec = "mario";
    a[0].int_rec = 54;
    a[0].doub_rec = 9.34;
    a[1].id_rec = 1;
    a[1].str_rec = "alcio";
    a[1].int_rec = 540;
    a[1].doub_rec = 129.4;
    a[2].id_rec = 2;
    a[2].str_rec = "fratm";
    a[2].int_rec = 4;
    a[2].doub_rec = 91.34;

    b[0].id_rec = 0;
    b[0].str_rec = "alcio";
    b[0].int_rec = 4;
    b[0].doub_rec = 9.34;
    b[1].id_rec = 1;
    b[1].str_rec = "fratm";
    b[1].int_rec = 54;
    b[1].doub_rec = 91.34;
    b[2].id_rec = 2;
    b[2].str_rec = "mario";
    b[2].int_rec = 540;
    b[2].doub_rec = 129.4;

    binary_insertion_sort((void*)&a, sizeof(Record), sizeof(a)/(sizeof(Record)), int_cmp);
    for(long i = 0; i < (int)(sizeof(a)/(sizeof(Record))); i++) assert(a[i].int_rec == b[i].int_rec);
    
    binary_insertion_sort((void*)&a, sizeof(Record), sizeof(a)/(sizeof(Record)), dbl_cmp);
    for(long i = 0; i < (int)(sizeof(a)/(sizeof(Record))); i++) assert(a[i].doub_rec == b[i].doub_rec);

    binary_insertion_sort((void*)&a, sizeof(Record), sizeof(a)/(sizeof(Record)), str_cmp);
    for(long i = 0; i < (int)(sizeof(a)/(sizeof(Record))); i++) assert(a[i].str_rec == b[i].str_rec);
}

int main(){
    // NULL RECORD

    null_quicksort_int_test();
    null_quicksort_dbl_test();
    null_quicksort_str_test();

    null_binsertion_int_test();
    null_binsertion_dbl_test();
    null_binsertion_str_test();

    // EMPTY RECORD

    empty_quicksort_int_test();
    empty_quicksort_dbl_test();
    empty_quicksort_str_test();

    empty_binsertion_int_test();
    empty_binsertion_dbl_test();
    empty_binsertion_str_test();

    // FULL RECORD 
    
    full_quicksort_test();

    full_binsertion_test();
    
}