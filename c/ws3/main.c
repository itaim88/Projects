/*******************************************************************************
				-Ws3
				-Itai Marienberg
				-Mon 04 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mycodes.h"

int main(int argc, const char **argv, const char **envp)
{
	char **x;

	x = CpyEnv(envp);
	
	if( NULL == x)
		{
		printf("malloc Error-Not enough memory\n");
		}
	
	return 0;

}






