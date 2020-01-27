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

#include "vector.h" /* vector functions */
#include "priorityq.h" /* priority queue functions */
#include "heapify.h" /* heapify functions */

typedef struct Wrapper
{
    compare_func_ptr cmp_func;
    void *param;
} wrap_t;

struct PQueue
{
    vector_t *pqueue;
    wrap_t wrap;    
};

static void SwapIMP(void **ptr1, void **ptr2)
{
	void *tmp = NULL;

	assert(NULL != ptr1);
	assert(NULL != ptr2);

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

static void HeapifyUp(void *arr, size_t size, size_t index, size_t element_size,
                                              compare_func_ptr cmp, void *param)
{
	void **new_data = NULL;
	void **parent = NULL;

	assert(NULL != arr);

	while (0 < index )
	{
		new_data = VectorGetItemAddress(arr, index + 1);
		parent = VectorGetItemAddress(arr, (index + 1) / 2);

		if(0 <= (cmp(*new_data, *parent, param)))
		{
			SwapIMP(parent, new_data);
			index = (index - 1) / 2;
			new_data = parent;
			parent = VectorGetItemAddress(arr, ((index + 1) / 2));
		}

		else
		{
			break;
		}
	}
}

static void HeapifyDown(void *arr, size_t size, size_t index, size_t element_size,
                                                compare_func_ptr cmp, void *param)
{
	void **left_child = NULL;
	void **right_child = NULL;
	void **parent = NULL;
	void **bigger_ptr = NULL;
	size_t bigger = 0;

	size_t left_index = (((index + 1) * 2) - 1);
	size_t right_index = ((index + 1) * 2);

	assert(NULL != arr);

	while (1 < size && left_index < size)              
	{
		parent = VectorGetItemAddress(arr, index + 1);
		left_child = VectorGetItemAddress(arr, left_index + 1);
		right_child = VectorGetItemAddress(arr, right_index + 1);

		if (0 <= cmp(*left_child, *parent, param))
		{
			bigger = left_index;
		}

		else
		{
			bigger = index;
		}

		if (right_index < size)
		{
			if (0 <= cmp(*right_child, *left_child, param))
			{
				bigger = right_index;
			}
		}

		if (bigger != index)
		{
			bigger_ptr = VectorGetItemAddress(arr, bigger + 1);
			SwapIMP(bigger_ptr, parent);
			index = bigger;
			left_index = (((index + 1) * 2) - 1);
			right_index = ((index + 1) * 2);
		}

		else
		{
			break;
		}
	}
}

pq_t *PQCreate(compare_func_ptr cmp_ptr, void *param)
{
	pq_t *new_ptr = (pq_t *)malloc(sizeof(*new_ptr));
	if (NULL != new_ptr)
	{
		new_ptr->wrap.param = param;
	 	new_ptr->wrap.cmp_func = cmp_ptr;
	 	new_ptr->pqueue = VectorCreate(sizeof(void *),1);
	 	if (NULL == new_ptr->pqueue)
	 	{
	 		free(new_ptr);
	 		new_ptr = NULL;

	 		return new_ptr;
	 	}

	}

	return new_ptr;
}

void PQDestroy(pq_t *pq)
{
	assert(NULL != pq);

	VectorDestroy(pq->pqueue);
	free(pq);
	pq = NULL;
}

void *PQDequeue(pq_t *pq)
{
	void *removed = NULL;
	void **first_member = NULL;
	void **last_member = NULL;

	assert(NULL != pq);

    first_member = VectorGetItemAddress(pq->pqueue, 1);
    removed = *first_member;
    last_member = VectorGetItemAddress(pq->pqueue, PQSize(pq));

    SwapIMP(first_member, last_member);
    VectorPopBack(pq->pqueue);
    HeapifyDown(pq->pqueue, PQSize(pq), 0, sizeof(void *), pq->wrap.cmp_func, pq->wrap.param);

    return removed;
}

int PQEnqueue(pq_t *pq, void *data)
{
	size_t size = 0;

	assert(NULL != pq);

	if (0 == VectorPushBack(pq->pqueue, &data))
	{
		size = PQSize(pq);

		HeapifyUp(pq->pqueue, size, size - 1, sizeof(void *),
                     pq->wrap.cmp_func, pq->wrap.param);
		return 0;
	}

	return 1;
}

void *PQPeek(const pq_t *pq)
{
	void **result = NULL;

	assert(NULL != pq);

	result = VectorGetItemAddress(pq->pqueue, 1);	

	return *result; 
}

size_t PQSize(const pq_t *pq)
{
	assert(NULL != pq);

	return VectorSize(pq->pqueue);
}

int PQIsEmpty(const pq_t *pq)
{
	assert(NULL != pq);

	return (0 == PQSize(pq));
}

void PQClear(pq_t *pq)
{
	size_t size = PQSize(pq); 

	assert(NULL != pq);

	while (0 != size)
	{
		 VectorPopBack(pq->pqueue);
		--size;			
	}
}

void *PQErase(pq_t *pq, match_func_pq m_ptr, void *data)
{
	size_t size = 0;
	size_t i = 0;
	void **current = NULL, **last = NULL;
	void *ret_val = NULL;

	assert(NULL != pq);  

	size = PQSize(pq);
	last = VectorGetItemAddress(pq->pqueue, size);

	for (i = 0; i < size; ++i)
	{
		current = VectorGetItemAddress(pq->pqueue, i + 1);

		if (1 == m_ptr(data,*current))
		{
			ret_val = *current;
			if (current == last)
			{
				VectorPopBack(pq->pqueue);

				break;
			}

			SwapIMP(current, last);
 			VectorPopBack(pq->pqueue);
 			HeapifyDown(pq->pqueue, PQSize(pq), i, sizeof(void *),
 			 				   pq->wrap.cmp_func, pq->wrap.param);
 			HeapifyUp(pq->pqueue, PQSize(pq), i, sizeof(void *),
 							 pq->wrap.cmp_func, pq->wrap.param);

 			break;
		} 
	}

	return ret_val;	
}

