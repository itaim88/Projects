

#include <stddef.h> /*size_t */ 
#include <stdio.h> /*printf */ 
#include <stdlib.h> /*malloc */ 
#include <time.h> /*rand */ 

/*#include "insertion.h"*/

#define SIZE 100


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

void SelectionSort(int arr[], size_t length)
{
    size_t i = 0;
    size_t j = 0;
	int temp = 0;
    size_t min = 0;

    for (i = 0; i < length -1; ++i)
    {
    	min = i;
    	
	for (j = i + 1; j < length; ++j)
	{
		if (arr[j] < arr[min])
		{
			min = j;
		}
	}
    
	if (min != i)
	{
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
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
		arr[i] = rand() % 100;
	}

	SelectionSort(arr,SIZE);
				 
	for (i = 0; i < SIZE; ++i)
	{
		printf("%d\n", arr[i]);
	}

	free(arr);
	arr = NULL;

	return 0;       
}
    
