/*******************************************************************************
-Ws Sorted linked list
-Itai Marienberg
-Dec 10 2019    
*******************************************************************************/

#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "priority_queue.h" 
#include "sortedlist.h"

#define FREE(ptr) free(ptr); ptr = NULL;

#define UNUSED(x) (void)(x)

typedef struct data_struct
{
    void *param;
    compare_func_ptr cmp_func;

}data_struct_t;

struct PQueue
{
    sll_t *queue;
    compare_func_ptr func;
    void *param; 
    data_struct_t *data_wrapper; 
};

static int CmpForSll(const void *user_data, const void *node_data, void *data_struct)
{
    if (0 < (((data_struct_t *)data_struct)->cmp_func
            ((void *)node_data, (void *)user_data, ((data_struct_t *)data_struct)->param)))
    {
        return 1;
    }
    
    return 0;
}

pq_t *PQCreate(compare_func_ptr cmp_ptr, void *param)
{
    data_struct_t *ptr_struct = NULL;
    
    pq_t *pq = (pq_t *)malloc(sizeof(pq_t));
    if (NULL != pq)
    {
        ptr_struct = (data_struct_t *)malloc(sizeof(data_struct_t));
        if (NULL == ptr_struct)
        {   
            FREE(pq);
            return pq;
        }
        
        ptr_struct->param = param;
        ptr_struct->cmp_func = cmp_ptr;
         
        pq->queue = SortLLCreate(&CmpForSll, ptr_struct);
        pq->func = cmp_ptr;
        pq->param = param;
        pq->data_wrapper = ptr_struct;
        
      
    }
    
    return pq;
}

void PQDestroy(pq_t *pq)
{
    assert(NULL != pq);    
    
    SortLLDestroy(pq->queue);
    
    FREE(pq);
}



void *PQDequeue(pq_t *pq)
{
	assert(NULL != pq);   

    return SLLPopFront (pq->queue); 
}

int PQEnqueue(pq_t *pq, void *data)
{
    assert(NULL != pq);
    
    return (SLLIsSameIter(SortLLInsert(pq->queue, data), SLLEnd(pq->queue)));
}

   
void *PQPeek(const pq_t *pq)
{
	assert(NULL != pq);   

    return SLLGetData(SLLBegin(pq->queue)); 
}
   
size_t PQSize(const pq_t *pq)
{
	assert(NULL != pq);   

    return SLLSize(pq->queue); 	
}

int PQIsEmpty(const pq_t *pq)
{
	assert(NULL != pq);   

    return SLLIsEmpty(pq->queue); 	
}

void PQClear(pq_t *pq)
{
	assert(NULL != pq);  

	while (0 == PQIsEmpty(pq))
	{
		PQDequeue(pq);
	}
}

void *PQErase(pq_t *pq, match_func_ptr_pq m_ptr, void *param)
{
    void *holder = NULL;
    sll_iterator_t it;

    assert(NULL != pq);  

    it = SLLFindBy(pq->queue, SLLBegin(pq->queue), SLLEnd(pq->queue), m_ptr, param);
    holder = SLLGetData(it);

    if (!SLLIsSameIter(it, SLLEnd(pq->queue)))
    {
        
        it = SortLLRemove(it);
    }
    
    return holder;
}
