/*********************************/
/*   			             	 */
/*   Heap                        */
/*   Itai Marienberg	         */
/*   Last Updated                */
/*   Reviewed by                 */   
/*			                   	 */
/*********************************/

#include <stddef.h>    /* size_t */
#include <stdlib.h>    /* malloc */
#include <assert.h>    /* assert */

#include "./../include/heapify.h" /* priority list functions */

void SwapData(void **ptr1, void **ptr2)
{
	void *tmp = NULL;

	assert(NULL != ptr1);
	assert(NULL != ptr2);

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;

}

void HeapifyUp(void *arr, size_t size, size_t index, size_t element_size,
                                              compare_func_ptr cmp, void *param)
{
	void **new_data =  

	assert(NULL != arr);

	while (index > 0 && (cmp(arr + index, arr + ((index - 1) / 2), param) > 0))
	{
		SwapData(&(arr + index), &(arr + (index - 1) / 2));
		index = (index - 1) / 2;
	}
}

void HeapifyDown(void *arr, size_t size, size_t index, size_t element_size,
                                                compare_func_ptr cmp, void *param)
{
	void *left = (char *)arr + ((((index + 1) * 2) - 1) * element_size);
	void *right = (char *)arr + ((index + 1) * 2 * element_size);
	void *parent = (char *) arr + (index * element_size);

	size_t left_index = (((index + 1) * 2) - 1) ;
	size_t right_index = ((index + 1) * 2);

	assert(NULL != arr);

	while (NULL != left)
	{
		if (NULL != right && (0 < cmp(right, left, param)))
		{
			if (0 < cmp(right, parent, param))
			{
				SwapData(&right, &parent);
				parent = right;
				index = right_index;
			}
			
		}

		else if (0 < cmp(left, parent, param))
		{
			SwapData(&left, &parent);
			parent = left;
			index = left_index;
		}
	
		left_index = (((index + 1) * 2) - 1) * element_size; 
		right_index = ((index + 1) * 2 * element_size);

		/*left = (char *)parent + (* element_size);
		right = (char *)parent + (* element_size);*/
		
	}

}
