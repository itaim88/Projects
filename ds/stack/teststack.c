/*******************************************************************************
-Ws2
-Itai Marienberg
-Mon 28 Nov 2019    
-Reviewer:
*******************************************************************************/
#include <stdlib.h> /* calloc usage*/
#include <string.h> /* strcmp usage */
#include <stdio.h>
#include "stack.h"

#define GREEN "\033[0;32m"
#define RED "\033[1;31m"
#define WHITE "\033[0m"

#define TEST(Test, msg) if (Test)\
                        {\
                            printf(GREEN);\
                            printf("SUCCESS\n");\
                        }\
                        else\
                        {\
                            printf(RED);\
                            printf("FAIL-%s\n", msg);\
                        }\
                        printf(WHITE);
struct Stack
{
    void* start;
    void* current;
    void* end;
    size_t element_size;
};

static int TestAllFunctions()
{
    size_t capasity = 5;
    size_t element_size = 4;
    int x = 7;
    stack_t *mytest1 = StackCreate(element_size, capasity);


    TEST(20 == ((char *)mytest1->end - (char *)mytest1->start), "pleaseeeee");
    printf("%ld\n", ((char *)mytest1->end - (char *)mytest1->start));
    TEST(NULL == StackPeek(mytest1), "the stack is empty");
    TEST(1 == StackPush(mytest1, &x),"2");
    TEST(7 == *(int *)StackPeek(mytest1), "the stack is empty");

    

    
    TEST(1 == StackPush(mytest1, &capasity),"3");
    TEST(1 == StackPush(mytest1, &capasity),"4");
    TEST(1 == StackPush(mytest1, &capasity),"5");
    TEST(1 == StackPush(mytest1, &capasity),"6");
    TEST(1 == StackPush(mytest1, &capasity),"7");
    TEST(1 == StackPush(mytest1, &capasity),"8");
    TEST(1 == StackPush(mytest1, &capasity),"9");
    TEST(1 == StackPush(mytest1, &capasity),"dfgfd");
    TEST(1 == StackPush(mytest1, &capasity),"dfgfd");
    TEST(1 == StackPush(mytest1, &capasity),"dfgfd");
    TEST(1 == StackPush(mytest1, &capasity),"dfgfd");
    TEST(1 == StackPush(mytest1, &capasity),"dfgfd");





    /*TEST();
    TEST();
    TEST();
    TEST();
    TEST();
    TEST();
    TEST();
    TEST();*/




/*
    StackPush(stack_t* mystack, const void* data);

    StackPop(stack_t* mystack);

    StackIsEmpty(const stack_t* mystack);

    StackSize(const stack_t* mystack);

    StackPeek(const stack_t* mystack);

*/
    StackDestroy(mytest1);

    return 0;
}

int main()
{
    TestAllFunctions();

    return 0; 
}
