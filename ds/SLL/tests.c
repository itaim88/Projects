#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

#define FREE(ptr){\
					free(ptr);\
					ptr = NULL;\
				}

#define NRM "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"

#define RUN_TEST(test,err_msg) {\
							if (test)\
							{\
								printf(GREEN"SUCCESS\n"NRM);\
							} \
							else\
							{\
								printf(RED"FAIL: %s\n",err_msg);\
							}\
						}

int Action(void *node, void *additional)
{
	node_t *node_holder = (node_t*)node;
	int data_holder = *(int*)(node_holder->data);

	data_holder += *(int*)additional;
	*(int*)node_holder->data = data_holder;

	return 1;
}

int Match(void *node, void *additional)
{
	node_t *node_holder = (node_t*)node;
	int data_holder = *(int*)(node_holder->data);

	return (data_holder == *(int*)additional);
}

void Tests()
{
	int j=4, i=2, k =1, f = 3;
	int counter = 0;
	node_t *new_node1 = NULL;
	node_t *new_node2 = NULL;
	node_t *new_node3 = NULL;
	node_t *new_node4 = NULL;
	node_t *runner = NULL;
	node_t *head = NULL;

	new_node4 = SLLCreateNode(NULL, &j);
	new_node3 = SLLCreateNode(new_node4, &f);
	new_node2 = SLLCreateNode(new_node3, &i);
	new_node1 = SLLCreateNode(new_node2, &k);

	head = new_node1;
	SLLFlip(head);
	runner = new_node4;
	while(NULL != runner)
	{
		RUN_TEST(((*(int*)runner->data) == 4-counter), "wrong value for loop ");
		++counter;
		runner = runner->next;
	}
	RUN_TEST((counter == 4),"unexpected count result");
	RUN_TEST((SLLSize(new_node4) == 4),"unexpected size after flip");

	SLLRemove(new_node3);

	RUN_TEST((SLLSize(new_node4) == 3),"unexpected size after remove");

	runner = new_node4;
	
	RUN_TEST(((*(int*)runner->data) == counter), "wrong value for loop after remove ");
	runner = runner->next;
	RUN_TEST(((*(int*)runner->data) == counter-2), "wrong value for loop after remove ");
	runner = runner->next;
	RUN_TEST(((*(int*)runner->data) == counter-3), "wrong value for loop after remove ");
	runner = runner->next;

	RUN_TEST((SLLSize(new_node4)==3),"wrong size after remove curr");

	SLLDestroy(new_node4);
	FREE(new_node4);

	new_node4 = SLLCreateNode(NULL, &j);
	new_node3 = SLLCreateNode(new_node4, &f);
	new_node2 = SLLCreateNode(new_node3, &i);
	new_node1 = SLLCreateNode(new_node2, &k);

	SLLRemoveAfter(new_node2);
	RUN_TEST((SLLSize(new_node1)==3),"wrong size after remove curr");

	SLLDestroy(new_node1);
	FREE(new_node1);

	new_node4 = SLLCreateNode(NULL, &j);
	new_node3 = SLLCreateNode(NULL, &f);
	new_node2 = SLLCreateNode(NULL, &i);
	new_node1 = SLLCreateNode(NULL, &k); 

	SLLInsert(new_node2, new_node1);
	SLLInsert(new_node3, new_node1);
	SLLInsert(new_node4, new_node1);
	
	runner = new_node1;
	counter = 0;

	RUN_TEST((SLLSize(new_node1) == 4),"unexpected size after insert");
	SLLDestroy(new_node1);
	FREE(new_node1);

	new_node4 = SLLCreateNode(NULL, &j);
	new_node3 = SLLCreateNode(NULL, &f);
	new_node2 = SLLCreateNode(NULL, &i);
	new_node1 = SLLCreateNode(NULL, &k);

	SLLInsertAfter(new_node2, new_node1);
	SLLInsertAfter(new_node3, new_node2);
	SLLInsertAfter(new_node4, new_node3);

	runner = new_node1;
	head = new_node1;
	counter = 1;

	while(NULL != runner)
	{
		RUN_TEST(((*(int*)runner->data) == counter), "wrong value for loop ");
		++counter;
		runner = runner->next;
	}

	RUN_TEST((SLLGetNode(head, &Match, &k) == new_node1), "unexpected node1");
	RUN_TEST((SLLGetNode(head, &Match, &i) == new_node2), "unexpected node2");
	RUN_TEST((SLLGetNode(head, &Match, &f) == new_node3), "unexpected node3");
	RUN_TEST((SLLGetNode(head, &Match, &j) == new_node4), "unexpected node4");
	RUN_TEST((SLLGetNode(head, &Match, &counter) == NULL), "unexpected node5");

	counter = 5;
	head = new_node1;
	RUN_TEST((SLLForEach(head, &Action, &counter) == 1), "unexpected value1");

	counter = 1;
	runner = new_node1;
	
	while (NULL != runner->next)
	{
		printf("%d\n",*(int*)runner->data);
		RUN_TEST(((*(int*)runner->data) == counter + 5), "wrong value for loop ");
		runner = runner->next;
		++counter;
	}

	SLLDestroy(new_node1);
	FREE(new_node1);
/*
	new_node4 = SLLCreateNode(new_node2, &j);
	new_node3 = SLLCreateNode(new_node4, &f);
	new_node2 = SLLCreateNode(new_node3, &i);
	new_node1 = SLLCreateNode(new_node2, &k);

	RUN_TEST((SLLHasLoop(new_node1) == 1), "failed to detect loop");
	printf("sgfakjg\n");

	SLLDestroy(new_node1);
	FREE(new_node1);	*/



}

int main()
{
	Tests();

	return 0;
}