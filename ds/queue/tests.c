#include <stdio.h> /*size_t*/
#include <stdlib.h> /*malloc*/

#include "linkedlist.h"
#include "queue.h"

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

struct Queue
{
	node_t *front;
	node_t *rear;
};

int main()
{
	int x1=1, x2=2, x3=3 ,x4=4 ,x5=5 ,y1=1 ,y2=2, y3=3 ,y4=4 ,y5=5;
	queue_t *new = QCreate();
	queue_t *to_append = QCreate();

	printf(NRM"Create & Peek & SIZE & Enqueue\n");
	RUN_TEST((QSize(new) == 0),"unexpected size");
	RUN_TEST((QEnqueue(new,&x1) == 0),"cant Enqueue");
	RUN_TEST((QPeek(new) == &x1),"Peek returned unexpected adress");
	RUN_TEST((QSize(new) == 1),"unexpected size");
	RUN_TEST((QEnqueue(new,&x2) == 0),"cant Enqueue");
	RUN_TEST((QSize(new) == 2),"unexpected size");
	RUN_TEST((QEnqueue(new,&x3) == 0),"cant Enqueue");
	RUN_TEST((QSize(new) == 3),"unexpected size");
	RUN_TEST((QEnqueue(new,&x4) == 0),"cant Enqueue");
	RUN_TEST((QSize(new) == 4),"unexpected size");
	RUN_TEST((QEnqueue(new,&x5) == 0),"cant Enqueue");
	RUN_TEST((QSize(new) == 5),"unexpected size");

	printf(NRM"IsEmpty & Peek & SIZE & Dequeue\n");
	QDequeue(new);
	RUN_TEST((*(int*)QPeek(new) == x2),"wrong adress 1");
	RUN_TEST((QSize(new) == 4),"unexpected size 1");
	RUN_TEST((QIsEmpty(new) == 0),"false emptyness");
	QDequeue(new);
	RUN_TEST((*(int*)QPeek(new) == x3),"wrong adress 2");
	RUN_TEST((QSize(new) == 3),"unexpected size 2");
	RUN_TEST((QIsEmpty(new) == 0),"false emptyness");
	QDequeue(new);
	RUN_TEST((*(int*)QPeek(new) == x4),"wrong adress 3");
	RUN_TEST((QSize(new) == 2),"unexpected size 3");
	RUN_TEST((QIsEmpty(new) == 0),"false emptyness");
	QDequeue(new);
	RUN_TEST((*(int*)QPeek(new) == x5),"wrong adress 4");
	RUN_TEST((QSize(new) == 1),"unexpected size 4");
	RUN_TEST((QIsEmpty(new) == 0),"false emptyness");
	
	printf(NRM"Append & Destroy\n");
	RUN_TEST((QEnqueue(to_append,&y1) == 0),"cant Enqueue 1");
	RUN_TEST((QEnqueue(to_append,&y2) == 0),"cant Enqueue 2");
	RUN_TEST((QEnqueue(to_append,&y3) == 0),"cant Enqueue 3");
	RUN_TEST((QEnqueue(to_append,&y4) == 0),"cant Enqueue 4");
	RUN_TEST((QEnqueue(to_append,&y5) == 0),"cant Enqueue 5");
	RUN_TEST((QSize(QAppend(new, to_append)) == 6), "unexpected size after Append");

	printf(NRM"Peek after Append\n");
	RUN_TEST((*(int*)QPeek(to_append) == x1),"wrong adress 1");
	RUN_TEST((QSize(to_append) == 6),"unexpected size 1");
	RUN_TEST((QIsEmpty(to_append) == 0),"false emptyness");
	QDequeue(to_append);
	RUN_TEST((*(int*)QPeek(to_append) == x2),"wrong adress 2");
	RUN_TEST((QSize(to_append) == 5),"unexpected size 2");
	RUN_TEST((QIsEmpty(to_append) == 0),"false emptyness");
	QDequeue(to_append);
	RUN_TEST((*(int*)QPeek(to_append) == x3),"wrong adress 3");
	RUN_TEST((QSize(to_append) == 4),"unexpected size 3");
	RUN_TEST((QIsEmpty(to_append) == 0),"false emptyness");
	QDequeue(to_append);
	RUN_TEST((*(int*)QPeek(to_append) == x4),"wrong adress 4");
	RUN_TEST((QSize(to_append) == 3),"unexpected size 4");
	RUN_TEST((QIsEmpty(to_append) == 0),"false emptyness");

	QDestroy(to_append);


	return 0;
}
