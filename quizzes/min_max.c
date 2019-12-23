#include <stdio.h>
#include <string.h>
#include <assert.h>

#define HALF_LENGTH length/2
#define NEXT_PAIR 2

/* this function works only for even length */

void MinAndMax(const int *arr, size_t length)
{
	int min = 0;
	int max = 0;
	int *arr_runner = NULL;
	int tmp_min = 0;
	int	tmp_max = 0;
	size_t counter = 1;
	
	assert(NULL != arr);
	
	arr_runner = (int *)arr;
	
	if (*arr_runner > *(arr_runner + 1))
	{
		max = *arr_runner;
		min = *(arr_runner + 1);
	}
	
	else
	{
		min = *arr_runner;
		max = *(arr_runner + 1);
	}
	
	for (arr_runner = arr_runner + NEXT_PAIR; counter < (HALF_LENGTH); 
								 arr_runner = arr_runner + NEXT_PAIR)
	{
		if (*(arr_runner )  > *(arr_runner + 1))
		{
			tmp_max = *(arr_runner );
			tmp_min = *(arr_runner + 1);
		}
		
		else
		{
			tmp_min= *(arr_runner);
			tmp_max = *(arr_runner + 1);
		}
	
		if (tmp_max > max)
		{
			max = tmp_max;
		}
		
		if (tmp_min < min)
		{
			min = tmp_min;
		}
		++counter;
	} 
	printf("MIN is %d, MAX is %d \n" , min, max);
}

int main()
{
	int arr[] = {6, -1234, 3, 5, 1, 4, 9, 2, 0, 1000, -1, 999, -987, 20};
	size_t length = sizeof(arr)/sizeof(int);
	
	MinAndMax(arr, length);
	
	return 0;
} 
