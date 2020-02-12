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

void Sigusr1Handler(int sig_num)
{
	/*struct sigaction sa_parent;
	sa_parent.sa_handler = Sigusr1Handler;*/
	/*sigaction(SIGUSR1, &sa_parent, NULL);*/
	write(1, "ping ", 6);
}

int main()
{
	pid_t pid = 0;

	struct sigaction sa_parent;
	char *const args[] = {"./a.out" ,NULL};

	sa_parent.sa_flags = 0;
	sa_parent.sa_handler = Sigusr1Handler;
	sigemptyset(&sa_parent.sa_mask);
	sigaction(SIGUSR1, &sa_parent, NULL);


		pid = fork();

		if (0 > pid)
		{
			perror("fork() failed");
			exit(EXIT_FAILURE);
		}
		
		else if (0 < pid)
		{
			printf("parent's pid: %d, child's pid: %d\n", getpid(), pid);
		}	
		if (0 == pid)
		{	

			if (0 != execvp("./a.out", args))
			{
				perror("execvp() failed");
				exit(EXIT_FAILURE);
			}
		}	

		while(1)
		{
			pause();
			/*sigsuspend(&sa_parent.sa_mask);*/
			kill(pid, SIGUSR1);	
		}

	return 0;
} 

