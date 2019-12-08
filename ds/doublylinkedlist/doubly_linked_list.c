/*******************************************************************************
-Ws Doubly linked list
-Itai Marienberg
-Dec 8 2019    
*******************************************************************************/

#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "double_linked_list.h" /* Doubly linked list header*/

#define FREE(ptr) free(ptr); ptr = NULL;


struct Iterator
{
	struct DLLNode *node;
};

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
	new_dummy->tail.next = &new_dummy->head;
	new_dummy->tail.next = NULL;
	new_dummy->tail.data = NULL;

	return new_dummy;
}

void DLLDestroy(dll_t *dll)
{
    dllnode_t *runner = dll->head.next;    
    dllnode_t *current = dll->head.next;    
   
    while (runner->next != &dll->tail)
    {
        runner = runner->next;
        FREE(current);
        current = runner; 
    }

    FREE(runner);
    FREE(dll);
}

iterator_t DLLBegin(dll_t *dll)
{
	iterator_t new_iterator;

	assert(NULL != dll);

	new_iterator.node = (dll->head.next);

	return new_iterator;
}

iterator_t DLLEnd(dll_t *dll)
{
	iterator_t new_iterator;

	assert(NULL != dll);

	new_iterator.node = &dll->tail;

	return new_iterator;
}


int DLLIsEmpty(const dll_t *dll)
{
	assert(NULL != dll);

	return (dll->head.next == &dll->tail);
}

iterator_t DLLGetNext(iterator_t it)
{
    iterator_t iter;
    iter.node = it.node->next;
    
    return iter;
}

iterator_t DLLGetPrev(iterator_t it)
{
    iterator_t iter;
    iter.node = it.node->prev;
    
    return iter;
}

size_t DLLSize(const dll_t *dll)
{
	dllnode_t *runner = dll->head.next;    
    size_t size = 1;    
   
    while (runner->next != &dll->tail)
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
		it.node = &dll->tail;
		return it;
	}

	new_node->data= (void *)data;
	new_node->prev= it.node->prev; 
	new_node->next= &dll->tail; 

	(it.node->prev)->next = new_node;
	it.node->prev = new_node;
	it.node = new_node;

	return it;
}
void *GetData(iterator_t it)
{
	return (it.node->data);
}

int DLLIsSameIter(const iterator_t it1, const iterator_t it2)
{
	return (it1.node == it2.node);
}

iterator_t DLLRemove(iterator_t it)
{
	dllnode_t *holder = it.node;

	(it.node->next)->prev = it.node->prev;
	(it.node->prev)->next = it.node->next;

	it.node = it.node->next;
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
	iterator_t iter;
	void *storage = NULL;

	assert(NULL != dll);

	iter = DLLGetPrev(DLLEnd(dll));
	storage = GetData(iter);
	DLLRemove(iter);

	return storage; 
}