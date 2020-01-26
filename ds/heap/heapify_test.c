/*********************************/
/*   			             	 */
/*   Data Structures             */
/*   heapify                     */
/*   Author: Itai Marienberg     */
/*   Last Updated 20/1/20        */
/*   Reviewed by:                */   
/*			                   	 */
/*********************************/

#include <stdio.h> /* printf */
#include <assert.h> /* assert */

#include "./../include/heapify.h"

#define UNUSED(x) (void)(x)

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
}
int MatchFunc(void *data, void *additional)
{   
    return (*(int*)data == *(int*)additional);
}

int CmpFunc(const void *node_data, const void *user_data, void *param)
{
    return (*(int *)node_data - *(int *)user_data);
}

static void Test()
{
    pq_t *pq = NULL;

    int x1 = 1;
    int x2 = 2;
    int x3 = 3;
    int x4 = 4;
    int x10 = 10;
    int *data = NULL;
    
    printf("PQ Test 1:\n");  
    pq = PQCreate(&CmpFunc, NULL);
    RUN_TEST(0 == PQEnqueue(pq, &x1), "enqueue");
    RUN_TEST(0 == PQEnqueue(pq, &x3), "enqueue");
    RUN_TEST(0 == PQEnqueue(pq, &x2), "enqueue");
    RUN_TEST(0 == PQEnqueue(pq, &x2), "enqueue");
    RUN_TEST(3 == *(int *)PQPeek(pq), "peek");
    RUN_TEST(3 == *(int *)PQDequeue(pq), "Dequeue");
    RUN_TEST(2 == *(int *)PQDequeue(pq), "Dequeue");
    RUN_TEST(2 == *(int *)PQDequeue(pq), "Dequeue");
    RUN_TEST(1 == *(int *)PQDequeue(pq), "Dequeue");
    PQDestroy(pq);
    
    printf("PQ Test 2:\n");  
    pq = PQCreate(&CmpFunc, NULL);
    RUN_TEST(0 == PQSize(pq), "size");
    RUN_TEST(1 == PQIsEmpty(pq), "size");
    RUN_TEST(0 == PQEnqueue(pq, &x1), "enqueue");
    RUN_TEST(1 == PQSize(pq), "size");

    PQDestroy(pq); 
    
    printf("PQ Test 3:\n");  
    pq = PQCreate(&CmpFunc, NULL);
    RUN_TEST(0 == PQEnqueue(pq, &x1), "enqueue");
    RUN_TEST(0 == PQEnqueue(pq, &x3), "enqueue");
    RUN_TEST(0 == PQEnqueue(pq, &x2), "enqueue");
    RUN_TEST(0 == PQEnqueue(pq, &x2), "enqueue");
    RUN_TEST(2 == *(int*)PQErase(pq, &MatchFunc, &x2), "erase");
    RUN_TEST(3 == PQSize(pq), "size");
    RUN_TEST(NULL == PQErase(pq, &MatchFunc, &x4), "erase");
 
    PQDestroy(pq); 
    
    printf("PQ Test 4:\n");  
    pq = PQCreate(&CmpFunc, NULL);
    RUN_TEST(0 == PQEnqueue(pq, &x1), "enqueue");
    RUN_TEST(0 == PQEnqueue(pq, &x3), "enqueue");
    RUN_TEST(0 == PQEnqueue(pq, &x2), "enqueue");
    RUN_TEST(0 == PQEnqueue(pq, &x2), "enqueue");
    PQClear(pq);
    RUN_TEST(0 == PQSize(pq), "size");
 
    PQDestroy(pq); 
}

int main()
{   
    Test();
    return 0;
}
