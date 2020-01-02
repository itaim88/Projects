

#include <stddef.h> /*size_t */ 
#include <stdio.h> /*printf */ 
#include <stdlib.h> /*malloc */ 
#include <time.h> /*rand */ 

/*#include "insertion.h"*/

#define SIZE 10000


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

void InsertionSort(int arr[], size_t length)
    {
        size_t i = 0;
        int j = 0;
        int temp = 0;

        for (i = 1 ; i < length; ++i)
        {
     		temp = arr[i];
     		j = i - 1;
    
		 	while ( 0 <= j && temp < arr[j])
		 	{
		 		arr[j+1] = arr[j];
		 		--j;
		 	}
     		
     		arr[j+1] = temp;
     	}   	
    }
  
int main()
    {
        size_t i = 0;
        int *arr = (int *) malloc(sizeof(int) * SIZE);
        if (NULL == arr)
        {
            return 1;
        }
       
        for (i = 0; i < SIZE; ++i)
        {
            arr[i] = rand() % 10000;
        }

        InsertionSort(arr,SIZE);
         
        for (i = 0; i < SIZE; ++i)
        {
            printf("%d\n", arr[i]);
        }

        free(arr);
        arr = NULL;

        return 0;
    }
    
