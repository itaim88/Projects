
/*******************************************************************************
-Ws Sorted linked list
-Itai Marienberg
-Dec 10 2019    
*******************************************************************************/

#include <stdio.h>  /*printf */

#include "priority_queue.h" /* sorted linked list functions */

#define NORMAL "\033[0m"
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

static void SortedListTest1()
{
    
}

int main()
{
    SortedListTest1();
    return 0;
}
