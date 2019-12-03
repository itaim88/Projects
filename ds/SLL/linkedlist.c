/*******************************************************************************
-Ws4
-Itai Marienberg
-Dec 1 2019    
*******************************************************************************/

#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/
#include <string.h> /* memcpy*/

#include "linkedlist.h"

/* Creates a new node */
/* WARNING: Doesnt get NULL pointer */
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
    node_t *next_runner = current_node->next;
    node_t *temp = NULL;

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

/* Removes the node after the node sent to the function */
/* WARNING: Doesnt get NULL pointer */
void SLLRemoveAfter(node_t *node)
{
	node_t *runner = node;

	assert(NULL != node);

	runner = node->next;
	node->next = runner->next;
	free(runner);
	runner = NULL;
}

 /*Returns a node according to a condition specified by the user */
/* WARNING: Doesnt get NULL pointer */
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

	return runner;
}

/* Performs a generic operation on all nodes in the data structure */
/* WARNING: Doesnt get NULL pointer */
int SLLForEach(node_t *head, action_func_ptr usr_func, void *additional)
{
	node_t *runner = (node_t *)head;

	while ((0 == usr_func(runner, additional)) && (NULL != runner->next))
	{
		runner = runner->next;
	}

	return !(NULL == runner ->next);
}

/* Returns the number of nodes */
/* WARNING: Doesnt get NULL pointer */
size_t SLLSize(const node_t *head)
{
	node_t const *runner = head;
	size_t count = 0;

	assert(NULL != head);

	while (NULL != runner)
	{
		runner = runner->next;
		++count;
	}

	return count;
}

/* Flips the direciton of pointing from last to first */
/* WARNING: Doesnt get NULL pointer */
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

	head = prev_node;

	return head;
}

/* Checks if a loop occurs in the structure */
/* Returns 0 - loop occurs, 1 - loop doesnt occur */
/* WARNING: Doesnt get NULL pointer */
int SLLHasLoop(const node_t *head)
{
	const node_t *fast = head->next;
	const node_t *slow = head;

	assert(NULL != head);

	while((fast != slow) && fast->next)
	{
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
	}

	return(fast == slow);
}

/* Returns a pointer to the node the create an  */
/* WARNING: Doesnt get NULL pointer */
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
	

	while (SLLSize(runner1) != SLLSize(runner2))
	{
		if (size1 > size2)
		{
			runner1 = runner1->next;
			--size1;
		}
		else if (size2 > size1)
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

	




