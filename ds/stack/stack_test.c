/*******************************************************************************
-Ws2
-Itai Marienberg
-Mon 28 Nov 2019    
-Reviewer:
*******************************************************************************/
#include <stdio.h>

#include "stack.h"

#define GREEN "\033[;032m"
#define RED   "\033[;031m"
#define RESET "\033[0m"
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

struct Stack
{
    void *start;
    void *current;
    void *end;
    size_t element_size; 
}; 

static void TestStackCreate()
{
    int x = 7, y = 12;
    stack_t *mystack = StackCreate(4, 25);
    
    printf("Stack 1:\n");
    RUN_TEST(100 == (char*)(mystack -> end) - (char*)(mystack -> start));
    RUN_TEST(32 == sizeof(*mystack));
    RUN_TEST(1 == StackPush(mystack, &x));
    RUN_TEST(4 == (char*)(mystack -> current) - (char*)(mystack -> start));
    RUN_TEST(7 == *(int*)StackPeek(mystack));
    StackPop(mystack);
    RUN_TEST((char*)(mystack -> current) == (char*)(mystack -> start));
    
    StackDestroy(mystack);
    
    printf("\nStack 2:\n");
    mystack = StackCreate(4, 100);
    RUN_TEST(400 == (char*)(mystack -> end) - (char*)(mystack -> start));
    RUN_TEST(32 == sizeof(*mystack));
    RUN_TEST(1 == StackPush(mystack, &y));
    RUN_TEST(1 == StackPush(mystack, &x));
    RUN_TEST(8 == (char*)(mystack -> current) - (char*)(mystack -> start));
    RUN_TEST(7 == *(int*)StackPeek(mystack));
    
    StackDestroy(mystack);
    
    printf("\nStack 3:\n");
    mystack = StackCreate(4, 100);
    RUN_TEST(400 == (char*)(mystack -> end) - (char*)(mystack -> start));
    RUN_TEST(32 == sizeof(*mystack));
    for(x = 7; x < 10; ++x)
    {
        RUN_TEST(1 == StackPush(mystack, &x));
    }
    RUN_TEST(9 == *(int*)StackPeek(mystack));
    StackDestroy(mystack);

/*    printf("Stack 4:\n");
    mystack = StackCreate(4, 100);
    RUN_TEST(100 == (char*)(mystack -> end) - (char*)(mystack -> start));
    RUN_TEST(32 == sizeof(*mystack));
    RUN_TEST(1 == StackPush(mystack, &x));
    RUN_TEST(4 == (char*)(mystack -> current) - (char*)(mystack -> start));
    RUN_TEST(7 == *(int*)StackPeek(mystack));
    StackPop(mystack);
    RUN_TEST((char*)(mystack -> current) == (char*)(mystack -> start));
    
    StackDestroy(mystack); */
    
/*    printf("\nStack 5:\n");
    mystack = StackCreate(4, 100);
    RUN_TEST(400 == (char*)(mystack -> end) - (char*)(mystack -> start));
    RUN_TEST(32 == sizeof(*mystack));
    RUN_TEST(1 == StackPush(mystack, &y));
    RUN_TEST(1 == StackPush(mystack, &x));
    RUN_TEST(8 == (char*)(mystack -> current) - (char*)(mystack -> start));
    RUN_TEST(7 == *(int*)StackPeek(mystack));
    
    StackDestroy(mystack);  */
}


int main()
{
    TestStackCreate();
    
    return 0;
}
