/*******************************************************************************
				-Ws3
				-Itai Marienberg
				-Mon 04 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/



#ifndef __MYCODES_H__
#define __MYCODES_H__

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void PrintEnv(char **env);

size_t EnvpLines(const char **envp);

char **CpyEnv(const char **envp);

void ToLower(char *str);

void Kill(int *soldiers);

#endif
  