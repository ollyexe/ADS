#include <stdio.h>
#include "library.h"

#include "../../Resources/C/Unity/unity.h"

static int i1, i2, i3;
static SkipList* list;

int ucompare(void* e1, void* e2){
    if(e1 == NULL){
        fprintf(stderr, "compare unity -> e1 NULL\n");
        exit(EXIT_FAILURE);
    }
    if(e2 == NULL){
        fprintf(stderr, "compare unity -> e2 NULL\n");
        exit(EXIT_FAILURE);
    }
    int i1 = *((int*)e1);
    int i2 = *((int*)e2);
    return (i1 - i2);   // return > 0 if i1 greater, 
}

void setUp(void){
    i1 = 34;
    i2 = 9;
    i3 = 12;
    list = createSkipList(ucompare);
}

static void test_one_insert(void){
    TEST_ASSERT_EQUAL_INT(1, insertSkipList(list, &i1));
}

static void test_two_insert(void){
    int res = insertSkipList(list, &i1);
    res += insertSkipList(list, &i2);
    TEST_ASSERT_EQUAL_INT(2, res);
}

static void test_three_insert(void){
    int res = insertSkipList(list, &i1);
    res += insertSkipList(list, &i2);
    res += insertSkipList(list, &i3);
    TEST_ASSERT_EQUAL_INT(3, res);
}

static void test_true_search(void){
    insertSkipList(list, &i1);
    TEST_ASSERT_EQUAL_INT(1, searchSkipList(list, &i1));
}
/*
static void test_false_search(){
    insertSkipList(list, &i2);
    TEST_ASSERT_EQUAL_INT(1, searchSkipList(list, &i1));
}*/

void tearDown(){
    freeSkipList(list);
}

int main(){
    UNITY_BEGIN();

    RUN_TEST(test_one_insert);
    RUN_TEST(test_two_insert);
    RUN_TEST(test_three_insert);
    RUN_TEST(test_true_search);
    //RUN_TEST(test_false_search);

    return UNITY_END();
}