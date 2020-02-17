#include <stdio.h>		/* perror() */
#include <stdlib.h>		/* exit()   */
#include <pthread.h>	
#include <unistd.h>	

#define NUM_TO_TEST 10000
#define NUM_OF_THREADS 2

size_t res_arr[NUM_OF_THREADS] = {0};
size_t times_to_run = NUM_TO_TEST / NUM_OF_THREADS;

void *DivSUM(void *param)
{
	static size_t div = NUM_TO_TEST;
	size_t res = 0;
	size_t i = times_to_run;

	while (0 < i)
	{
		if (0 ==  NUM_TO_TEST % div)
		{
			res += div;
		}

		--div;
		--i;
	}

	res_arr[*(size_t*)param] = res;

	return NULL;
}

int main()
{
	size_t i = 0;
	int status = 0;
	size_t res = 0;
	size_t index[NUM_OF_THREADS] = {0};

	pthread_t thread[NUM_OF_THREADS];

	for (i = 0; i < NUM_OF_THREADS; ++i) 
	{
		index[i] = i;
	}

	for (i = 0; i < NUM_OF_THREADS; ++i)
	{
		status = pthread_create(&thread[i], NULL, DivSUM, &index[i]);
		sleep(1);
		if(0 != status)
		{
			printf("FAIL %ld\n", i);
			exit(EXIT_FAILURE);
		}
	}

	for (i = 0; i < NUM_OF_THREADS; ++i)
	{	
		pthread_join(thread[i], NULL);
		res += res_arr[i];
	}

	printf("%ld\n", res);

	return 0;
}	

