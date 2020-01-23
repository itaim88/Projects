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

#include "avl.h"

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
/*
static int CompareFunc(const void *user_data, const void *tree_data)
{
   
    return (*(int *)user_data - *(int *)tree_data); 
}
*/
/*
static int ActionFunc(void *param, void *tree_data)
{
    UNUSED(param);
  
    printf("%d \n", *(int*)tree_data);
    
    return 0;  
}
*/
/*
static void AVLTest1()
{
    void *param = NULL;
    avl_t *tree = AVLCreate(&CompareFunc);
    int x1 = 20, x2 = 10, x3 = 30, x4 = 3, x5 = 15, x6 = 25, x7 = 35, x8 = 22, 
    x9 = 31, x10 = 37, x11 = 28, x12 = 27;

    printf("AVLTTest 1:\n");
    RUN_TEST(1 == AVLIsEmpty(tree), "is empty1");
    
    RUN_TEST(0 == AVLInsert(tree, &x1), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x2), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x3), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x4), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x5), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x6), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x7), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x8), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x9), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x10), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x11), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x12), "insert1");

    RUN_TEST(12 == AVLSize(tree), "size1");
    RUN_TEST(3 == AVLGetHeight(tree), "Height");
   
    AVLForeach(tree, &ActionFunc, param);
    
    RUN_TEST(30 == *(int*) AVLFind(tree, &x3), "Find");

    AVLRemove(tree, &x3);
    AVLForeach(tree, &ActionFunc, param);
    RUN_TEST(11 == AVLSize(tree), "size2");
    printf("\n");

    AVLRemove(tree, &x4);
    AVLForeach(tree, &ActionFunc, param);
    RUN_TEST(10 == AVLSize(tree), "size3");
    printf("\n");

    AVLRemove(tree, &x2);
    AVLForeach(tree, &ActionFunc, param);
    printf("\n");
    RUN_TEST(9 == AVLSize(tree), "size4");

    AVLRemove(tree, &x1);
    AVLForeach(tree, &ActionFunc, param);
    RUN_TEST(8 == AVLSize(tree), "size5");
    printf("\n");

    AVLDestroy(tree);
    
    printf("\n\n");
}*/


/*static void AVLTest2()
{
    void *param = NULL;
    avl_t *tree = AVLCreate(&CompareFunc);
    int x1 = 20, x2 = 15, x3 = 30, x4 = 10, x5 = 32, x6 = 8;

    RUN_TEST(0 == AVLInsert(tree, &x1), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x2), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x3), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x4), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x5), "insert1");
    RUN_TEST(0 == AVLInsert(tree, &x6), "insert1");

    AVLDestroy(tree);

    printf("\n\n");  
}*/


int main()
{
    AVLTest1();
    AVLTest2();
 
    return 0;
}






