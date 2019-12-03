/*******************************************************************************
-Ws4
-Itai Marienberg
-Dec 1 2019    
*******************************************************************************/

#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "linkedlist.h"

node_t *SLLCreateNode(node_t *next, const void *data)
{
	node_t *new_node = NULL;
	new_node = (node_t *)malloc(sizeof(node_t));
	if (NULL == new_node)
	{
		return NULL;
	}
	new_node->next = next;
	new_node->data = (void *)data;

	return new_node;
}

void SLLDestroy(node_t *current_node)
{        
    node_t *next_runner = NULL;
    node_t *temp = NULL;

    assert(NULL != current_node);
    
    next_runner = current_node->next;

    while (NULL != next_runner)
    {        
        temp = next_runner;
        next_runner = next_runner->next;
        free(temp);
        temp = NULL;
    }

    current_node->next = NULL;
    free(current_node);
    current_node = NULL;
}

int SLLInsert(node_t *node, node_t *next_node)
{                    
	void *tmp = NULL;

	assert(NULL != node);
	assert(NULL != next_node);

	node->next = next_node->next;
	next_node->next = node;
	tmp = node->data;
	node->data = next_node->data;
	next_node->data = tmp;

	return 0;
}

int SLLInsertAfter(node_t *new_node, node_t *previous_node)
{
	assert(NULL != new_node);
	assert(NULL != previous_node);

	new_node->next = previous_node->next;
	previous_node->next = new_node;

	return 0;
}

void SLLRemove(node_t *node)
{
	node_t *runner = NULL;

	assert(NULL != node->next);

	runner = node->next;

	node->data = runner->data;
	node->next = runner->next;
	runner->next = NULL;
	free(runner);
	runner = NULL;
}

void SLLRemoveAfter(node_t *node)
{
	node_t *runner = node;

	assert(NULL != node);

	runner = node->next;
	node->next = runner->next;
	free(runner);
	runner = NULL;
}

node_t *SLLGetNode(const node_t *head, match_func_ptr usr_func, void *additional)
{
	node_t *runner = (node_t *)head;

	while (NULL != runner)
	{
		if (0 == usr_func(runner, additional))
		{
			runner = runner->next;
		}
		else
		{
			return runner;
		}
	}

	return NULL;
}

int SLLForEach(node_t *head, action_func_ptr usr_func, void *additional)
{
	node_t *runner = NULL;

	assert(NULL != head);
	
	runner = head;

	while ((0 == usr_func(runner, additional)) && (NULL != runner->next))
	{
		runner = runner->next;
	}

	return !(NULL == runner->next);
}

size_t SLLSize(const node_t *head)
{
	const node_t *runner = NULL;
	size_t count = 0;

	assert(NULL != head);
	
	runner = head;

	while (NULL != runner)
	{
		runner = runner->next;
		++count;
	}

	return count;
}

node_t *SLLFlip(node_t *head)
{
	node_t *prev_node = NULL;
	node_t *current_node = NULL;
	node_t *next_node = NULL;

	assert(NULL != head);

	current_node = next_node = head;

	while (NULL != next_node)
	{
		next_node = next_node->next;
		current_node->next = prev_node;
		prev_node = current_node;
		current_node = next_node;
	}

	return prev_node;
}

int SLLHasLoop(const node_t *head)
{
	node_t *fast_runner = NULL, *slow_runner = NULL;

	assert(NULL != head);

	fast_runner = (node_t *)head->next;
	slow_runner = (node_t *)head;

	while (fast_runner->next != NULL && fast_runner != slow_runner)
	{
		slow_runner = slow_runner->next;
		fast_runner = fast_runner->next;

		if (fast_runner->next == NULL)
		{
			break;
		}
		fast_runner = fast_runner->next;
	}

	return (slow_runner == fast_runner);
}

node_t *SLLFindIntersection(const node_t *head1, const node_t *head2)
{
	size_t size1 = 0, size2 = 0;
	node_t *runner1 = NULL, *runner2 = NULL;

	assert(NULL != head1);
	assert(NULL != head2);

	runner1 = (node_t *)head1;
	runner2 = (node_t *)head2;
	size1 = SLLSize(runner1);
	size2 = SLLSize(runner2);
	
	if (size1 > size2)
	{
		while (size1 - size2 > 0)
		{
			runner1 = runner1->next;
			--size1;
		}
	}
	else  
	{
		while (size2 - size1 > 0)
		{
			runner2 = runner2->next;
			--size2;
		}
	}
	
	while (NULL != runner1)
	{
		if (runner1 == runner2)
		{	
			return runner1;
		}
		runner1 = runner1->next;
		runner2 = runner2->next;
	}

	return runner1;
}
