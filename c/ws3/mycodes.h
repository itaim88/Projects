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
char *Mystrcpy(char *temp, const char *runner);
void *Mymalloc(int flag);
void MoveToNextAlive(int *sword, int *end, int *start );

void init_arr();
void kill();
void reorder_arr();
void print_winner();

#endif
  
