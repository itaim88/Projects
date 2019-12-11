
#include <stdio.h> /* printf */
#include <string.h> /* strcmp */

#include "sortedlist.h"

#define MAX_NAME 20
#define GREEN "\033[;032m"
#define RED   "\033[;031m"
#define RESET "\033[0m"
#define UNUSED(x) (void)(x)
#define RUN_TEST(test)\
{\
  if(test)\
  {\
    printf(GREEN);\
    printf("SUCCESS\n");\
    printf(RESET);\
  }\
  else\
  {\
    printf(RED);\
    printf("FAIL \n");\
    printf(RESET);\
  }\
}

int PrintIterator(void *data, void *ap)
{
    UNUSED(ap);
    
    printf("%d\n", *(int *)data); 
    
    return 0; 
}

int PrintNames(void *data, void *ap)
{
    UNUSED(ap);
    
    printf("%s\n", (char *)data); 
    
    return 0; 
}

int CompareNum(const void *data1, const void *data2, void *param)
{
    UNUSED(param);
    
    return (*(const int *)data1 > *(const int *)data2);
}

int CompareByName(const void *data1, const void *data2, void *param)
{
    UNUSED(param);
    
    return (0 < strcmp((const char*)data1, (const char*)data2));  
}

struct Person
{
    char name[MAX_NAME];
    int age;
    size_t id;
};

int IsMatchAge(void *data, void *ap)
{
    struct Person *p = (struct Person *)data;
    return ((p->age) == *(int *)ap);
}

static void TestCreateList()
{
    int x0 = 0, x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5, x6 = 6, x7 = 7, x8 = 22;
    sll_t *sll, *sll2;
    sll_iterator_t it1;
    struct Person p1 = {"Guy", 22, 318434099}
                , p2 = {"Yossi", 29, 123456789}
                , p3 = {"Mati", 13, 987654321}; 
    
    printf("Sorted List 1:\n");
    sll = SortLLCreate(&CompareNum, &x0);
    RUN_TEST(1 == SLLIsEmpty(sll));
    RUN_TEST(0 == SLLSize(sll));
    
    SortLLInsert(sll, &x3);
    SortLLInsert(sll, &x1);
    SortLLInsert(sll, &x2);
    
    RUN_TEST(3 == SLLSize(sll));
    
    it1 = SLLBegin(sll);
    RUN_TEST(1 == *(int *)SLLGetData(it1));
    it1 = SLLNext(it1);
    RUN_TEST(2 == *(int *)SLLGetData(it1));
    it1 = SLLNext(it1);
    RUN_TEST(3 == *(int *)SLLGetData(it1));
    SortLLRemove(it1);
    RUN_TEST(2 == SLLSize(sll));
    
    SortLLDestroy(sll);
    
    printf("\nSorted List 2:\n");
    sll = SortLLCreate(&CompareNum, &x0);

    RUN_TEST(1 == SLLIsEmpty(sll));
    RUN_TEST(0 == SLLSize(sll));
    
    SortLLInsert(sll, &x3);
    SortLLInsert(sll, &x1);
    
    it1 = SLLPrev(SLLEnd(sll));
    
    RUN_TEST(3 == *(int *)SLLGetData(it1));
    RUN_TEST(3 == *(int *)SLLPopBack(sll));
    RUN_TEST(1 == SLLSize(sll));
    RUN_TEST(1 == *(int *)SLLPopFront(sll));
    
    SortLLDestroy(sll);
    
    printf("\nSorted List 3:\n");
    sll = SortLLCreate(&CompareNum, &x0);

    RUN_TEST(1 == SLLIsEmpty(sll));
    RUN_TEST(0 == SLLSize(sll));
    
    SortLLInsert(sll, &x6);
    SortLLInsert(sll, &x2);
    SortLLInsert(sll, &x4);
    SortLLInsert(sll, &x5);
    SortLLInsert(sll, &x3);
    SortLLInsert(sll, &x1);
    
    SLLForEach(SLLBegin(sll), SLLEnd(sll), &PrintIterator, &x0);
    
    it1 = SLLFind(sll, &x4, SLLBegin(sll), SLLEnd(sll));
    RUN_TEST(4 == *(int *)SLLGetData(it1));
    
    it1 = SLLFind(sll, &x7, SLLBegin(sll), SLLEnd(sll));
    RUN_TEST(1 == SLLIsSameIter(SLLEnd(sll), it1));
    
    SortLLDestroy(sll);
    
    printf("\nSorted List 4: FindBy\n");
    sll = SortLLCreate(&CompareByName, NULL);

    RUN_TEST(1 == SLLIsEmpty(sll));
    RUN_TEST(0 == SLLSize(sll));
    
    SortLLInsert(sll, &p3);
    SortLLInsert(sll, &p1);
    SortLLInsert(sll, &p2);

    SLLForEach(SLLBegin(sll), SLLEnd(sll), &PrintNames, NULL);
    
    it1 = SLLFindBy(sll, SLLBegin(sll), SLLEnd(sll), &IsMatchAge, &x8);

    RUN_TEST(22 == ((struct Person *)SLLGetData(it1))->age);
    
    it1 = SLLFindBy(sll, SLLBegin(sll), SLLEnd(sll), &IsMatchAge, &x1);
    
    RUN_TEST(1 == SLLIsSameIter(SLLEnd(sll), it1));
    SortLLDestroy(sll); 
    
    printf("\nSorted List 5: Merge\n");
    sll = SortLLCreate(&CompareNum, NULL);
    sll2 = SortLLCreate(&CompareNum, NULL);
    
    SortLLInsert(sll, &x6);
    SortLLInsert(sll, &x1);
    SortLLInsert(sll2, &x4);
    SortLLInsert(sll2, &x5);
    SortLLInsert(sll2, &x3);
    SortLLInsert(sll2, &x2);
    
    SLLMerge(sll, sll2);
    
    SLLForEach(SLLBegin(sll), SLLEnd(sll), &PrintIterator, &x0);
    
    RUN_TEST(6 == SLLSize(sll));
    RUN_TEST(1 == *(int *)SLLGetData(SLLBegin(sll)));
    SortLLDestroy(sll2);
    SortLLDestroy(sll); 
}


int main()
{
    TestCreateList();
    return 0;
}


/*******************************************************************************
-Ws Sorted linked list
-Itai Marienberg
-Dec 10 2019    
*******************************************************************************/

/*#include <stdio.h> */ /*printf */

/*#include "sortedlist.h" *//* sorted linked list functions */
/*#include "double_linked_list.h" *//* doubley linked list functions*/ 

/*#define NORMAL "\033[0m"
#define RED "\033[;031m"
#define GREEN "\033[;032m"

#define RUN_TEST(test, error_message){\
    if (test)\
    {\
        printf(GREEN);\
        printf("SUCCESS\n");\
        printf(NORMAL);\
    }\
    else\
    {\
        printf(RED);\
        printf("FAIL %s\n", error_message);\
        printf(NORMAL);\
    }\
}*/

/*static int IsBefore(const void *node_data,const void *user_data, void *param)
{
    return (*(int*)user_data < *(int*)node_data);
}

static int MatchFunc(void* node_data, void* user_data)
{
    void *n = node_data;
    
    return (*(int*)n == *(int*)user_data);
}

static int AdditionFunc(void* node, void* ap)
{
    void* n = node;
    
    *(int*)n += *(int*)ap;
    
    return 0;
}*/

/*static void SortedListTest1()
{
    
    int data = 77;
    int data2 = 22;
    int data3 = 66;
    int data4 = 99;
    int data5 = 44;
    int ap = 66;
    int ap2 = 75;*/
    
    /*sll_iterator_t it1;
    sll_iterator_t it2;
    sll_iterator_t it3;
    sll_iterator_t it4;
    sll_iterator_t it5;
    sll_t *sll1 = NULL;
    
    printf("Sorted list test1:\n");
    
    sll1 = SortLLCreate(&IsBefore, NULL);
    RUN_TEST(1 == SLLIsEmpty(sll1), "is empty test1");
    it1 = SortLLInsert(sll1, &data);
    RUN_TEST(1 == SLLSize(sll1), "size tes1");
    RUN_TEST(77 == *(int*)SLLGetData(it1), "get data test1");
    RUN_TEST(1 == SLLIsSameIter(it1, it1), "same iter test1");
    
    SortLLDestroy(sll1);
    
    printf("\nSorted list test2:\n");*/
    /* test SLLInsert */
   /* sll1 = SortLLCreate(&IsBefore, NULL);
    RUN_TEST(1 == SLLIsEmpty(sll1), "is empty test2");
    it1 = SortLLInsert(sll1, &data);
    it2 = SortLLInsert(sll1, &data2);
    it3 = SortLLInsert(sll1, &data3);
    RUN_TEST(3 == SLLSize(sll1), "size tes2");
    RUN_TEST(77 == *(int*)SLLGetData(it1), "get data test2");
    RUN_TEST(22 == *(int*)SLLGetData(it2), "get data test2");
    RUN_TEST(66 == *(int*)SLLGetData(it3), "get data test2");
    
    SortLLDestroy(sll1);
    
    printf("\nSorted list test3:\n");*/
    /* test SLLFind */
   /* sll1 = SortLLCreate(&IsBefore, NULL);
    RUN_TEST(1 == SLLIsEmpty(sll1), "is empty test3");
    it1 = SortLLInsert(sll1, &data);
    it2 = SortLLInsert(sll1, &data2);
    it3 = SortLLInsert(sll1, &data3);
    it4 = SortLLInsert(sll1, &data4);
    RUN_TEST(4 == SLLSize(sll1), "size tes3");
    
    it1 = SLLFind(sll1, &ap, SLLBegin(sll1), SLLEnd(sll1));
    RUN_TEST(66 == *(int*)SLLGetData(it1), "get data test3");
    it1 = SLLFind(sll1, &ap2, SLLBegin(sll1), SLLEnd(sll1));
    RUN_TEST(1 == SLLIsSameIter(it1, SLLEnd(sll1)), "is same iter");
    it1 = SLLFindBy(sll1, SLLBegin(sll1), SLLEnd(sll1), &MatchFunc, &ap);
    RUN_TEST(66 == *(int*)SLLGetData(it1), "get data test3");*/
    
    /* test Pop */
   /* RUN_TEST(99 == *(int*)SLLPopBack(sll1), "pop back test3");
    RUN_TEST(77 == *(int*)SLLPopBack(sll1), "pop back test3");
    RUN_TEST(66 == *(int*)SLLPopBack(sll1), "pop back test3");
    RUN_TEST(22 == *(int*)SLLPopBack(sll1), "pop back test3");
    
    it2 = SortLLInsert(sll1, &data2);
    it1 = SortLLInsert(sll1, &data);
    it4 = SortLLInsert(sll1, &data4);
    it5 = SortLLInsert(sll1, &data5);
    it3 = SortLLInsert(sll1, &data3);
    
    RUN_TEST(22 == *(int*)SLLPopFront(sll1), "pop front test3");
    RUN_TEST(44 == *(int*)SLLPopFront(sll1), "pop front test3");
    RUN_TEST(66 == *(int*)SLLPopFront(sll1), "pop front test3");
    RUN_TEST(77 == *(int*)SLLPopFront(sll1), "pop front test3");    
    RUN_TEST(99 == *(int*)SLLPopFront(sll1), "pop front test3");
            
    SortLLDestroy(sll1);
    
    printf("\nSorted list test4:\n");*/
    
    /* for each test */
 /*   sll1 = SortLLCreate(&IsBefore, NULL);
    RUN_TEST(1 == SLLIsEmpty(sll1), "is empty test4");
    it2 = SortLLInsert(sll1, &data2);
    it1 = SortLLInsert(sll1, &data);
    it4 = SortLLInsert(sll1, &data4);
    it5 = SortLLInsert(sll1, &data5);
    it3 = SortLLInsert(sll1, &data3);
    RUN_TEST(5 == SLLSize(sll1), "size tes4");
    
    SLLForEach(SLLBegin(sll1), SLLEnd(sll1), &AdditionFunc, &ap);
    
    printf("after addition: %d\n", *(int*)SLLGetData(it2));
    printf("after addition: %d\n", *(int*)SLLGetData(it5));
    printf("after addition: %d\n", *(int*)SLLGetData(it3));
    printf("after addition: %d\n", *(int*)SLLGetData(it1));
    printf("after addition: %d\n", *(int*)SLLGetData(it4));    
    
    SortLLDestroy(sll1);
    
    printf("\n");
}*/

/*int main()
{
    SortedListTest1();
    return 0;
}*/
