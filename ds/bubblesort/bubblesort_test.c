

#include <stddef.h> /*size_t */ 
#include <stdio.h> /*size_t */ 
#include <stdlib.h> /*malloc */ 
#include <time.h> /*rand */ 

/*#include "sort.h"*/

#define SIZE 10000
#define NO 0
#define YES 1

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

void BubbleSort(int arr[], size_t length)
    {
        size_t i = 0;
        size_t j = 0;
        int is_sorted = YES;
        int temp = 0;

        for (i = 0; i < length - 1; ++i)
        {
            is_sorted = YES;

            for (j = 0; j < length - 1 -i; ++j)
            {
                if (arr[j] > arr[j+1])
                {   
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    is_sorted = NO; 
                }
            }

            if (YES == is_sorted)
            {
                break;  
            }   
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

        BubbleSort(arr,SIZE);
         
        for (i = 0; i < SIZE; ++i)
        {
            printf("%d\n", arr[i]);
        }

        free(arr);
        arr = NULL;

        return 0;
    }
    
