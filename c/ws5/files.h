/*******************************************************************************
				-Ws5
				-Itai Marienberg
				-Mon 11 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/

#ifndef __FILES_H__
#define __FILES_H__

#include <stdio.h>
#include <stdlib.h>

struct general
{
	char *str;
    int (*p_cmp)(const char *, const char *);
    enum STATUS(*p_opr)(const char *);
} ;

void Structs(struct general gen_arr[]);
int Compare(const char *s1, const char *s2);
int Compare_always(const char *s1, const char *s2);
enum STATUS RemoveFile(const char *file_name);
enum STATUS ExitProg(const char *file_name);
enum STATUS CountLines(const char *filename); 
enum STATUS AddString(const char *file_name, char *user_str);
enum STATUS AddStringTop(const char *file_name, char *user_str);
int StartProg (const char *file_name, struct general gen_arr[]);



#endif
