/*********************************/       
/*    sorts                      */       
/*    Author : itai              */
/*    Reviewed By:               */
/*                               */
/*********************************/

#include <stddef.h> /*size_t */ 
#include <stdlib.h> /*malloc*/
#include <stdio.h>
#include <assert.h> /*assert*/

#include "sorts.h"

#define YES 1
#define NO 0
#define NUM_OF_BIT_IN_INT 32
void BubbleSort(int arr[], size_t length)
{
    size_t i = 0;
    size_t j = 0;
    int is_sorted = YES;
    int temp = 0;

    for (i = 0; i < length - 1; ++i)
    {
        is_sorted = YES;

        for (j = 0; j < length - 1 - i; ++j)
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

int CountingSort(const int *arr, size_t size, int min, int max, int *res)
{
    int i = 0;
    int k = max - min + 1;

    int *new_count = (int *) calloc(k, sizeof(int));
    if (NULL == new_count)
    {
        return 1;
    }

    for (i = 0; (size_t)i < size ; ++i)
    {
        ++new_count[arr[i] - min];   
    }

    for (i = 1; i < k; ++i)
    {
        new_count[i] += new_count[i-1];
    }

    for (i = (size - 1); 0 <= i; --i)
    {
       res[new_count[arr[i] - min] -1] = arr[i];
       --new_count[arr[i] - min];  
    }

    free(new_count);
    new_count = NULL;

    return 0;
}


static int FindMax(const int arr[], size_t size)
{
    size_t i = 0;
    int max = arr[i];
    
    for(i = 0; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    
    return max;
}

static void RadixCountingSort(int *src, int *dest, size_t *hist, size_t size, int mask, int shift)
{   
    int i = 0;

    for (i = 0; i < (mask + 1); i++)
    {
        hist[i] = 0;
    }

    for (i = 0; (size_t)i < size; ++i)
    {
        ++hist[(src[i]>>shift) & mask];
    }

    for(i = 1; i < (mask + 1); i++)
    {
        hist[i] += hist[i - 1];
    }

    for(i = (size - 1);0 <= i; --i)
    {
        dest[hist[(src[i]>>shift) & mask] - 1] = src[i];
        --hist[(src[i]>>shift) & mask];
    }
    
}


int RadixSort(int *arr, size_t size, int num_of_bits)
{
    int mask = (1 << num_of_bits) - 1;
    int i = 0;
    int shift = 0;
    int *swap_ptr = NULL;
    size_t *hist = NULL;
    int *res = NULL;
    int run_var = (NUM_OF_BIT_IN_INT/num_of_bits);

    assert(NULL != arr);

    hist = (size_t *)malloc((mask + 1) * sizeof(size_t));
    if (NULL == hist)
    {
        return 1;
    }
    res = (int *)malloc(size * sizeof(int));
    if (NULL == res)
    {
        free(hist); hist = NULL;
        return 1;
    }

    for (i = 0; i < run_var; ++i)
    {
        shift = i * num_of_bits;

        RadixCountingSort(arr, res, hist, size, mask, shift);

        swap_ptr = arr;
        arr = res;
        res = swap_ptr;
    }

    free(hist); hist = NULL;
    free(res); res = NULL;

    return 0;
}