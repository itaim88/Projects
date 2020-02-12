/*********************************/
/*   			             	 */
/*   System Programming          */
/*   signals               		 */
/*   Itai Marienberg			 */
/*********************************/

#include <stdio.h>		/* perror() 	*/
#include <stdlib.h>		/* exit()   	*/
#include <sys/types.h>	/* fork()   	*/
#include <sys/wait.h>	/* wait()   	*/
#include <unistd.h>		/* exec()  		*/
#include <string.h>		/* strcat() 	*/
#include <signal.h>		/* sigaction()	*/

void DoParent(pid_t child_id);

void DoChild();

void Sigusr1Handler(int sig_num)
{
	write(1, "ping ", 6);
}

void Sigusr2Handler(int sig_num)
{
	write(1, "pong\n", 6);
}

int main()
{
	pid_t pid = 0;
	pid_t pid2 = 0;
	struct sigaction sa;
	struct sigaction sa_parent;
	char *const args[] = {"./a.out" ,NULL};

	sa.sa_handler = Sigusr2Handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);

	sa_parent.sa_flags = 0;
	sa_parent.sa_handler = Sigusr1Handler;
	sigemptyset(&sa_parent.sa_mask);
	sigaction(SIGUSR1, &sa_parent, NULL);


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
			printf("parent's pid: %d, child's pid: %d\n", getpid(), pid);

			while(1)
			{	
				sleep(1);	
				kill(pid, SIGUSR1);
				sigsuspend(&sa_parent.sa_mask);
			}
		}

		else
		{
			while(1)
			{
				sigsuspend(&sa.sa_mask);
				sleep(1);	
				kill(getppid(), SIGUSR2);	
			}
		}
	}

	return 0;
} 
