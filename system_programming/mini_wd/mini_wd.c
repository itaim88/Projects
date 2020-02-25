#include <stdio.h>		/* perror() */
#include <stdlib.h>		/* exit()   */
#include <sys/types.h>	/* fork()   */
#include <sys/wait.h>	/* wait()   */
#include <unistd.h>		/* exec()   */
#include <string.h>		/* strcat() */

void frk(int argc, char * const argv[]);
void sys(int argc, char * const argv[]);

int main(int argc, char * const argv[])
{
	if (0 == strcmp("fork", argv[1]))
	{
		frk(argc, argv);
	}

	else if (0 == strcmp("system", argv[1]))
	{
		sys(argc, argv);
	}

	else
	{
		return 1;
	}

	return 0;
} 

void frk(int argc, char * const argv[])
{
	pid_t pid = 0;

	while (1)
	{
		pid = fork();
		if (0 > pid)
		{
			perror("fork() failed");
			exit(EXIT_FAILURE);
		}

		else if (0 < pid)
		{
			if (0 > wait(NULL))
			{
				perror("wait() failed");
				exit(EXIT_FAILURE);
			}
		}

		else
		{
			if (0 != execvp(argv[2], &argv[3]))
			{
				perror("execpv() failed");
				exit(EXIT_FAILURE);
			}
		}
	}
}

void sys(int argc, char * const argv[])
{
	while(1)
	{
		system(argv[2]);	
	}
}
