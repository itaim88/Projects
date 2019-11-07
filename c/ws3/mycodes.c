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
    int str_size = strlen(s) + 1;
   
    char *temp = (char*)malloc(sizeof(char) * str_size);
   
    const char *runner = s;
    assert(NULL != s);
    assert(NULL != temp);
   
    if(NULL == temp)
    {
        return NULL;
    }
   
    strcpy(temp, runner);
       
    return temp;
   
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

void ToLower(char *str)
{ 
	char *runner = str;
	while('\0' != *runner)
	{
		*runner = tolower(*runner);
		++runner;
	}
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
	head = envp_cpy;
	
	while (i < count)
	{ 
		*envp_cpy = MyStrDup(*runner);
		ToLower(*envp_cpy);
		++runner;
		++envp_cpy;
		++i;
	}
	PrintEnv(head);
	
	CleanEnvCopy(head);
	
	return head;
	
}

/* Exercise 2 this function solve Josephus problem */


































	
