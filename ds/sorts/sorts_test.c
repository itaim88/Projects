

#include <stddef.h> /*size_t */ 
#include <stdio.h> /*size_t */ 
#include <stdlib.h> /*malloc */ 
#include <time.h> /*rand */ 

#include "sorts.h"

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
        size_t i = 0;
        int src[9] = {7,6,10,5,9,2,1,15,7};
        int dst[6] = {0,0,0,0,0,0};
        size_t size = 9;

        /*MergeSort(src, dst, size);*/

		QuickSort(src, 9, 4, &Compare);

        /*for (i = 0; i < size; ++i)
        {
            printf("%d\n", dst[i]);  
        }
*/
         for (i = 0; i < size; ++i)
        {
            printf("%d\n", src[i]);  
        }

        /*size_t i = 0;
        clock_t start, end;
        double time_use = 0;
        int *b = NULL;
        int count[10] = {0};
    
        int *arr = (int *) malloc(sizeof(int) * SIZE);
        if (NULL == arr)
        {
            return 1;
        }
        
        b = (int *) malloc(sizeof(int) * SIZE);
        if (NULL == b)
        {
            return 1;
        }
       
        for (i = 0; i < SIZE; ++i)
        {
            arr[i] = rand() % UB;
        }

		start = clock();
        BubbleSort(arr,SIZE);

        CountingSort(arr,SIZE,-5,UB,b);

		end = clock();
        time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
       
        for (i = 0; i < SIZE; ++i)
        {
            printf("%d\n", b[i]);
        }
		
		printf("time use = %f\n", time_use);
		
        free(arr);
        arr = NULL;
        free(b);
        b = NULL;*/

      
      
        return 0;
    }
    
