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

#include "./../include/vector.h" /* sorted list functions */
#include "./../include/priorityq.h" /* priority list functions */
#include "./../include/heapify.h" /* priority list functions */

#define FREE(ptr) {free(ptr); ptr = NULL;}

typedef struct Wrapper
{
    compare_func_ptr cmp_func;
    void *param;
}wrap_t;

struct PQueue
{
    vector_t *pqueue;
    wrap_t wrap;    
};

/*int MyCompare(const void *node_data, const void *user_data, void *param)
{

 
} 
*/
pq_t *PQCreate(compare_func_ptr cmp_ptr, void *param)
{
	pq_t *new_ptr = (pq_t *) malloc(sizeof(*new_ptr));
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

}

int PQEnqueue(pq_t *pq, void *data)
{
	size_t size = 0;

	assert(NULL != pq);

	if (0 == VectorPushBack(pq->pqueue, data))
	{
		size = PQSize(pq);

		HeapifyUp(pq->pqueue, size, VectorGetItemAddress(pq->pqueue, size), sizeof(void *),
                                                       pq->wrap.cmp_func,  pq->wrap.param);
		return 0;
	}

	return 1;
}

void *PQPeek(const pq_t *pq)
{
	assert(NULL != pq);

	return VectorGetItemAddress(pq->pqueue, 1);	
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
	assert(NULL != pq);

	size_t size = PQSize(pq); 

	while (0 != size)
	{
		VectorPopBack(pq->pqueue);
		--size;			
	}
}

void *PQErase(pq_t *pq, match_func_pq m_ptr, void *data)
{   
 	 
}

void HeapifyUp(void *arr, size_t size, size_t index, size_t element_size,
                                             cmp_func cmp, void *param);

void HeapifyDown(void *arr, size_t size, size_t index, size_t element_size,
                                               cmp_func cmp, void *param);
