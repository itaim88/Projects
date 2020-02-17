#include <stdio.h>			/* printf()	*/
#include <unistd.h>	
#include <pthread.h>		/* threads	*/
#include <stdatomic.h>		/* atomic 	*/

#define NUM 10000000
#define SIZE 10
#define UNUSED(x) (void)(x)

enum lock
{
	FREE,
	LOCKED
};

int can_produce = FREE;
int can_consume = LOCKED;

size_t arr[NUM] = {0};

void *Producer(void *param)
{
	size_t i = 0;
	size_t j = 0;

	UNUSED(param);

	for (j = 0; j < NUM; ++j)
	{
		while (__sync_lock_test_and_set(&can_produce, LOCKED));

		for (i = 0; i < SIZE; ++i)
		{
			++arr[i];
		}

		__sync_lock_release(&can_consume);
	}

	return NULL;
}

void *Consumer(void *param)
{
	size_t i = 0;
	size_t j = 0;
	size_t sum = 0;
	size_t curr_num = 0;

	UNUSED(param);

	for (j = 0; j < NUM; ++j)
	{
		while (__sync_lock_test_and_set(&can_consume, LOCKED));
		
		for (i = 0; i < SIZE; ++i)
		{
			sum += arr[i];
		}

		curr_num = arr[0];
		if (sum / SIZE == curr_num)
		{
			printf("SUCSSES %ld\n", curr_num);
		}

		else
		{
			printf("FAIL %ld\n", curr_num);
		}
		
		sum = 0;

		__sync_lock_release(&can_produce);
	}

	return NULL;
}

int main()
{
	int status = 0;
	pthread_t thread1 = 0;
	pthread_t thread2 = 0;

	status = pthread_create(&thread1, NULL, Producer, NULL);
	if (0 != status)
	{
		printf("pthread1 create error \n");
		return 1;
	}

	status = pthread_create(&thread2, NULL, Consumer, NULL);
	if (0 != status)
	{
		printf("pthread2 create error \n");
		return 1;
	}

	status = pthread_join(thread1, NULL);
	if (0 != status)
	{
		printf("pthread1 join error \n");
		return 1;
	}

	pthread_join(thread2, NULL);
	if (0 != status)
	{
		printf("pthread2 join error \n");
		return 1;
	}

	return 0;
}


