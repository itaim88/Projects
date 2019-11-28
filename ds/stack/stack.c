/*******************************************************************************
-Ws2
-Itai Marienberg
-Mon 28 Nov 2019    
-Reviewer:
*******************************************************************************/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/
#include <stdio.h> /*printf*/
#include <string.h> /* memcpy*/

#include "stack.h"

struct Stack
{
	void* start;
	void* current;
	void* end;
	size_t element_size;
};

/* This function creates new Stack */
stack_t* StackCreate(size_t element_size, size_t capacity)
{
	stack_t *newstack = (stack_t *) malloc(sizeof(stack_t));
	if (NULL == newstack)
	{
		return NULL;
	}

	newstack->start = (void *) malloc(capacity*element_size);
	if (NULL == newstack->start)
	{
		return NULL;
	}

	newstack -> current = newstack->start;
	newstack -> end = (char *)newstack->start + (capacity * element_size);
	newstack -> element_size = element_size;

	return newstack;
}

/* This function destroy the Stack */
void StackDestroy(stack_t* mystack)
{
	assert(NULL != mystack);

	free(mystack->start); mystack->start = NULL;
	free(mystack); mystack = NULL; 
}

/* This function push given element to the top of the Stack */
int StackPush(stack_t* mystack, const void* data)
{
	assert(NULL != mystack);
	assert(NULL != data);

	if (mystack->current == mystack->end)
	{
		printf("the stack is full, didnt add.\n");

		return 0;
	}

	memcpy(mystack->current, data, mystack->element_size);
	mystack->current = (char *)mystack->current + mystack->element_size;

	return 1;
}

/* This function pop the element that is on the top of the Stack and remove it */
void StackPop(stack_t* mystack)
{
	assert(NULL != mystack);

	if (mystack->current != mystack->start)
	{
		mystack->current = (char *)mystack->current - mystack->element_size;
	}
	else
	{
		printf("the stack is empty, cant pop");
	}		
}

/* This function checkes if the Stack is empty */
int StackIsEmpty(const stack_t* mystack)
{
	assert(NULL != mystack);

	if (mystack -> current == mystack -> start)
	{
		return 1;
	}

	return 0;
}

/* This function return the number of elements in the stack */
size_t StackSize(const stack_t* mystack)
{
	assert(NULL != mystack);

	return (((char *)mystack -> current - (char *)mystack -> start)/(mystack -> element_size));                 /* check if its current -1 */
}

/* This function returns the top most elemet on the Stack */
void* StackPeek(const stack_t* mystack)
{
	assert(NULL != mystack);

	if (mystack->current == mystack->start)
	{
		printf("the stack is empty, cant see anything\n");

		return NULL;
	}

	return ((char *)mystack->current - mystack->element_size);
}
