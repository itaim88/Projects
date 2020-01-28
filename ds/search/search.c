/*********************************/       
/*    search                      */       
/*    Author : itai              */
/*    Reviewed By:               */
/*                               */
/*********************************/

#include <stddef.h> /*size_t */ 
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <string.h> /*assert*/
#include <math.h> /*assert*/



#include "./../include/search.h"

#define YES 1
#define NO 0
#define NUM_OF_BIT_IN_INT 32

void *JumpSearch(void *arr, size_t elm_size, size_t num_of_elm, cmp_func cmp, const void *data, const void *param)
{
	size_t jump = sqrt(num_of_elm);
	size_t start = 0;
	size_t end = start + jump;
	size_t i = 0;

	assert(NULL != arr);	

    while (end < num_of_elm && (0 >= cmp((char *)arr + (end * elm_size), data))) 
    {
   		start = end; 
      	end += jump;

      	if(end > num_of_elm - 1)
      	{
       		end = num_of_elm; 
      	}
    }

    for(i = start; i < end; ++i) 
    { 
    	if(0 == cmp((char *)arr + (i * elm_size), data))
     	{
     		return (char *)arr + (i * elm_size);
    	}
    }

    return NULL;
    
}


void *BinarySearch(void *arr, size_t elm_size, size_t num_of_elm, cmp_func cmp, const void *data, const void *param)
{
	size_t left = 0;
	size_t right = num_of_elm - 1;
	size_t mid = 0;

	assert(NULL != arr);	

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (0 == cmp(data, (char *)arr + (mid * elm_size)))
		{
			return ((char *)arr + (mid * elm_size));	
		}

		else if (0 > cmp(data, (char *)arr + (mid * elm_size)))
		{
			right = mid -1;
		}

		else
		{
			left = mid + 1;	
		}
	}

	return NULL;
}

