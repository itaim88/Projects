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


void SigusrHandler(int sig_num)
{
	/*struct sigaction sa;
	sa.sa_handler = SigusrHandler;*/
	/*sigaction(SIGUSR1, &sa, NULL);*/
	write(1, "pong\n", 6);
}

int main(int argc, char *const argv[])
{
	struct sigaction sa;

	sa.sa_handler = SigusrHandler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);

	while(1)
	{
		sleep(1);
		kill(agrv[1], SIGUSR1);
		pause();
	}

	return 0;
} 
