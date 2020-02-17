#include <stdio.h>		/* perror() */
#include <stdlib.h>		/* exit()   */
#include <pthread.h>	
#include <unistd.h>	

#define SIZE 32000

int arr[SIZE] = {0};

void *Ones_func(void *param)
{
	arr[*(int *)param] = 1;

	return NULL;
}

int main()
{
	int i = 0;
	int status = 0;
	int res = 0;
	int index[SIZE] = {0};

	pthread_t thread[SIZE];

	for (i = 0; i < SIZE; ++i) 
	{
		index[i] = i;
	}

	for (i = 0; i < SIZE; ++i)
	{
		status = pthread_create(&thread[i], NULL, Ones_func, &index[i]);
		pthread_detach(thread[i]);

		if(0 != status)
		{
			printf("FAIL %d\n", i);
			exit(EXIT_FAILURE);
		}
	}

	sleep(1);

	for (i = 0; i < SIZE; ++i)
	{	
		res += arr[i];
	}

	printf("%d\n", res);

	return 0;
}	

