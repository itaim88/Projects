/*******************************************************************************
-Ws Doubly linked list
-Itai Marienberg
-Dec 8 2019    
*******************************************************************************/

#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "double_linked_list.h" /* Doubly linked list header*/

#define FREE(ptr) {free(ptr); ptr = NULL;}

struct DLLNode
{
	void *data;
	struct DLLNode *next;
	struct DLLNode *prev;
};

typedef struct DLLNode dllnode_t;

struct DLL
{
	dllnode_t head;
	dllnode_t tail;
};

dll_t *DLLCreate()
{
	dll_t *new_dummy = (dll_t *)malloc(sizeof(dll_t));
	if (NULL == new_dummy)
	{
		return NULL;
	}

	new_dummy->head.next = &new_dummy->tail;
	new_dummy->head.prev = NULL;
	new_dummy->head.data = NULL;
	new_dummy->tail.prev = &new_dummy->head;
	new_dummy->tail.next = NULL;
	new_dummy->tail.data = NULL;

	return new_dummy;
}

void DLLDestroy(dll_t *dll)
{
    dllnode_t *runner = dll->head.next;    
    dllnode_t *current = NULL; 

    assert(NULL != dll);   
   
    while (runner != &dll->tail)
    {
    	current = runner;
        runner = runner->next;
        FREE(current);
    }

    FREE(dll);
}

iterator_t DLLBegin(dll_t *dll)
{
	assert(NULL != dll);

	return dll->head.next;
}

iterator_t DLLEnd(dll_t *dll)
{
	assert(NULL != dll);

	return &dll->tail;
}


int DLLIsEmpty(const dll_t *dll)
{
	assert(NULL != dll);

	return (dll->head.next == &dll->tail);
}

iterator_t DLLGetNext(iterator_t it)
{
    assert(NULL != it); 

    return it->next;
}

iterator_t DLLGetPrev(iterator_t it)
{
    assert(NULL != it);
    
    return it->prev;
}

size_t DLLSize(const dll_t *dll)
{
	dllnode_t *runner = dll->head.next;    
    size_t size = 0;   

    assert(NULL != dll);
   
    while (runner != &dll->tail)
    {
        runner = runner->next;
        ++size;
    }

    return size;
}

iterator_t DLLInsert(dll_t *dll, iterator_t it, void *data)
{
	dllnode_t *new_node = NULL;

	assert(NULL != dll); 

	new_node = (dllnode_t *)malloc(sizeof(dllnode_t));
	if (NULL == new_node)
	{
		it = &dll->tail;
		return it;
	}

	new_node->data = data;
	new_node->prev = it->prev; 
	new_node->next = it;
	it->prev->next = new_node;
	it->prev = new_node;
	it = new_node;

	return it;
}
void *DLLGetData(iterator_t it)
{
	assert(NULL != it); 

	return it->data;
}

int DLLIsSameIter(const iterator_t it1, const iterator_t it2)
{
	assert(NULL != it1); 
	assert(NULL != it2); 

	return (it1 == it2);
}

iterator_t DLLRemove(iterator_t it)
{
	dllnode_t *holder = NULL;

	assert(NULL != it); 
	
	holder = it;

	it->next->prev = it->prev;
	it->prev->next = it->next;

	it = it->next;
	FREE(holder);

	return it;
}

iterator_t DLLPushBack(dll_t *dll, void *data)
{
	assert(NULL != dll);
	assert(NULL != data);

	return DLLInsert(dll, DLLEnd(dll), data);
}

void *DLLPopBack(dll_t *dll)
{
	iterator_t iter = NULL;
	void *storage = NULL;

	assert(NULL != dll);

	iter = DLLGetPrev(DLLEnd(dll));
	storage = DLLGetData(iter);
	DLLRemove(iter);

	return storage; 
}

void *DLLPopFront(dll_t *dll)
{
	void *holder = NULL;
	iterator_t iter = NULL;

	assert(NULL != dll);

	iter = DLLBegin(dll);
	holder = DLLGetData(iter);
	DLLRemove(iter);

	return holder;
}

iterator_t DLLPushFront(dll_t *dll, void *data)
{
	assert(NULL != dll);
	assert(NULL != data);

	return DLLInsert(dll, DLLBegin(dll) , data);
}

/*int DLLForEach(iterator_t start, iterator_t end, action_func_ptr a_ptr, void *ap)
{
	iterator_t it_runner = NULL;

	assert(NULL != ap);
	assert(NULL != start);
	assert(NULL != end);

	it_runner = start;

	while (it_runner != end )
	{
		if (0 == a_ptr(DLLGetData(it_runner), ap))
		{
			it_runner = DLLGetNext(it_runner);
		}

		else
		{
			return 1;
		}
	}

	return 0;	
}*/

int DLLForEach(iterator_t start, iterator_t end, action_func_ptr a_ptr, void *ap)
{
    iterator_t i = NULL;
    int return_val = 0;
   
    assert(NULL != start);
    assert(NULL != end);
    assert(NULL != a_ptr);
   
    for (i = start; i != end; i = DLLGetNext(i))
    {
        if (0 != (return_val = a_ptr(i->data, ap)))
        {
            return return_val;
        }
    }
   
    return return_val;
}

iterator_t DLLFind(iterator_t start, iterator_t end, match_func_ptr m_ptr, void *ap)
{
    iterator_t i = NULL;
   
    assert(NULL != start);
    assert(NULL != end);
    assert(NULL != m_ptr);
   
    for (i = start; i != end; i = DLLGetNext(i))
    {
        if (1 == m_ptr(i->data, ap))
        {
            return i;
        }
    }
   
    return end;
}

/*iterator_t DLLFind(iterator_t start, iterator_t end, match_func_ptr m_ptr, void *ap)
{
	iterator_t it_runner = NULL;

	assert(NULL != ap);
	assert(NULL != start);
	assert(NULL != end);

	it_runner = start;

	while (it_runner != end)
	{
		if (1 == m_ptr(DLLGetData(it_runner), ap))
		{
			return it_runner;	
		}

		else
		{
			it_runner = DLLGetNext(it_runner);
			
		}
	}

	return it_runner;	
}*/


iterator_t DLLSplice(iterator_t start, iterator_t end, iterator_t where)
{
	iterator_t it_end_prev = NULL;

	assert(NULL != start);
	assert(NULL != end);
	assert(NULL != where);

 	it_end_prev = DLLGetPrev(end);
	start->prev->next = end;
	end->prev = start->prev; 
	start->prev = where;
	it_end_prev->next = where->next;
	where->next->prev = it_end_prev;
	where->next = start;

	return where;
}	

