/*******************************************************************************
-Ws Circular Buffer
-Itai Marienberg
-Dec 4 2019    
*******************************************************************************/
#include <stdio.h> /* printf */

#include "circularbuffer.h" /* API functions */

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

/*static void TestCbCreate();
{
    queue_t *q = NULL, *q1 = NULL;
    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5, count = 0;
    printf("Queue 1:\n");
    q = QCreate();
    RUN_TEST(0 == QSize(q));
    RUN_TEST(1 == QIsEmpty(q));
    RUN_TEST(0 == QEnqueue(q, &x1));
    RUN_TEST(0 == QIsEmpty(q));
    QDequeue(q);
    RUN_TEST(1 == QIsEmpty(q));
    QDestroy(q);    
    
    printf("\nQueue 2:\n");
    q = QCreate();
    RUN_TEST(0 == QSize(q));
    RUN_TEST(0 == QEnqueue(q, &x2));
    RUN_TEST(2 == *(int*)QPeek(q));
    RUN_TEST(1 == QSize(q));
    RUN_TEST(0 == QEnqueue(q, &x1));
    QDequeue(q);
    RUN_TEST(1 == *(int*)QPeek(q));
    RUN_TEST(1 == QSize(q));
    QDestroy(q);
    
    printf("\nQueue 3:\n");
    q = QCreate();
    RUN_TEST(0 == QEnqueue(q, &x1));
    RUN_TEST(0 == QEnqueue(q, &x2));
    RUN_TEST(0 == QEnqueue(q, &x3));
    
    q1 = QCreate();
    RUN_TEST(0 == QEnqueue(q, &x4));
    RUN_TEST(0 == QEnqueue(q, &x5));
    
    q = QAppend(q,q1);
    RUN_TEST(5 == QSize(q));

    for (count = 0; count < 5; ++count)
    {
        printf("%d\n", *(int*)QPeek(q));
        QDequeue(q);
    }
    QDestroy(q);
}*/

int main()
{
   /* TestCbCreate();*/
    return 0;
}

