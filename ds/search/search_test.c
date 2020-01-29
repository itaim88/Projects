

#include <stddef.h> /*size_t */ 
#include <stdio.h> /*size_t */ 
#include <stdlib.h> /*malloc */ 
#include <time.h> /*rand */ 

#include "search.h"

#define SIZE 20
#define UB 11


#define RED "\x1b[31m"
#define GREEN "\x1b[32m"


#define RUN_TEST(test,mssg)\
            if (test)\
            {\
                printf(GREEN "SUCCESS: %s\n",mssg);\
            }\
            else\
            {\
                printf(RED "FAIL: %s\n",mssg);\
            }\


static int Compare(const void *data1, const void *data2)   
{
	return (*(int*) data1 - *(int*)data2);
}
	
int main()
{
    int src[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    void *res = NULL;
    int x1 = 6;
    int x2 = 14;

   

    printf("BinarySearchTest\n\n");

    res = BinarySearch(src, 4, 13, Compare, &x1, NULL);
    printf("yes 6 is here, res = %d\n", *(int*)res);
    res = BinarySearch(src, 4, 13, Compare, &x2, NULL);
    printf("NOT found, NULL is return  = %d\n",  NULL == res);

    printf("\n\n");  

    printf("JumpSearchTest\n\n");

    res = JumpSearch(src, 4, 13, Compare, &x1, NULL);
    printf("yes 6 is here, res = %d\n", *(int*)res);

    res = JumpSearch(src, 4, 13, Compare, &x2, NULL);
    printf("NOT found, NULL is return = %d\n",  NULL == res);
 
   


	return 0;
}
    
