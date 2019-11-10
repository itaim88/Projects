/*******************************************************************************
				-Ws3
				-Itai Marienberg
				-Mon 04 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h> /*tolower*/
#include <assert.h>
#include "mycodes.h"


/* Exercise 1 this function print out the Environmental variables */

char *MyStrDup(const char* s)
{
	int flag = 0; /* change flag to 1 if you wish to test Mymalloc*/
    int str_size = strlen(s) + 1;
    const char *runner = s;
    char *temp;
    
    if( 0 == flag)
    	{
   		 temp = (char*)malloc(sizeof(char) * str_size);
   		 assert(NULL != s);
    	 assert(NULL != temp);
    	}
    
    else if( 1 == flag)
    	{	
		 temp = Mymalloc(flag);
		 return temp;
    	}
			
    Mystrcpy(temp, runner);

   
    return temp;
   
}

char *Mystrcpy(char *temp, const char *runner)
{
	char *ptr = temp;

	if (temp == NULL)
	return NULL;

	

	while ('\0' != *runner )
		{
			*temp = tolower(*runner);;
			++temp;
			++runner;
		}
		
			*temp = '\0';

	return ptr;
 }	

size_t EnvpLines(const char **envp)
{
	int count = 0;
	const char **runner;
	runner = envp;
	
	while (NULL != *runner)
	{
		++runner;
		++count;
	}
	
	return count;
}



void PrintEnv(char **env)
{ 
    while (NULL != *env)
    {
        printf("%s\n", *env); 
        ++env;
    } 
}
 
void CleanEnvCopy(char **envp_cpy)
{
	int i = 0;
	while (0 != *(envp_cpy + i))
	{
		free(*(envp_cpy +i));
		*(envp_cpy + i) = NULL;
		++i;
	}
	
	free (envp_cpy);
	envp_cpy = NULL;		
}
  

char **CpyEnv(const char **envp)

{
	
	int count = 0, i = 0;
	const char **runner;
	char **envp_cpy = NULL;
	char **head = envp_cpy;
	runner = envp;
	
	count = EnvpLines(envp);
	
	envp_cpy = (char**) calloc (count, sizeof(char *));
	
			if (NULL == envp_cpy)
				{
					printf("Error");
					return NULL;
				}
   
	head = envp_cpy;
	
	while (i < count)
	{ 
		*envp_cpy = MyStrDup(*runner);
		
				if (NULL == *envp_cpy)
					{
						CleanEnvCopy(head);						
						return NULL;
			
					}
		++runner;
		++envp_cpy;
		++i;
	}
	
	PrintEnv(head);
	
	CleanEnvCopy(head);
	
	return head;	
}

void *Mymalloc(int flag)
{
	void *ptr;
	ptr = NULL;
	
	if ( 1 == flag)
		{
			return ptr;
		}
				
} 




























	
