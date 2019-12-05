/*******************************************************************************
-Ws5
-Itai Marienberg
-Dec 4 2019    
*******************************************************************************/

#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "queue.h" /*queue header*/
#include "linkedlist.h" /* linked list implementation */

#define DUMMYS 2
#define FREE(ptr) free(ptr); ptr = NULL;

struct Queue
{
	node_t *front;
	node_t *rear;
}; 

queue_t *QCreate()
{
	queue_t *queue = (queue_t*)malloc(sizeof(queue_t));
	if (NULL == queue)	
	{
		return NULL;
	}

	queue->rear = SLLCreateNode(NULL, NULL);
	if (NULL == queue->rear)
	{
		FREE(queue)
		
		return NULL;
	}	

	queue->front = SLLCreateNode(queue->rear, NULL);
	if (NULL == queue->front)
	{
		free(queue->rear);
		queue->rear = NULL;
		FREE(queue)
		
		return NULL;

	}	
    return queue; 
}

void QDestroy(queue_t *queue)
{
	assert(NULL != queue);

	SLLDestroy(queue->front);
	FREE(queue)
}

int QEnqueue(queue_t *queue, void *data)
{
	node_t *new_node = NULL;

	assert(NULL != queue);

	new_node = SLLCreateNode(NULL, data);
	if (NULL == new_node)
	{
		return 1;
	}

	SLLInsert(new_node, queue->rear);
	queue->rear = new_node;

	return 0;
}

void QDequeue(queue_t *queue)
{
	assert(NULL != queue);

	SLLRemoveAfter(queue->front);
}

int QIsEmpty(const queue_t *queue)
{
	return ((queue->front->next) == queue->rear);
}

void *QPeek(const queue_t *queue)
{
	assert(NULL != queue);

	return (queue->front->next->data);
}

size_t QSize(const queue_t *queue)
{	
	assert(NULL != queue);	

	return (SLLSize(queue->front) - DUMMYS);
}

queue_t *QAppend(queue_t *queue1, queue_t *queue2)
{
	
	assert(NULL != queue1);	
	assert(NULL != queue2);	

	queue1->rear->next = queue2->front;
	SLLRemove(queue1->rear);
	SLLRemove(queue1->rear);

	queue1->rear = queue2->rear;
	FREE(queue2)
	
	return queue1;
}	
