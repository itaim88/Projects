/*******************************************************************************
				-Ws5
				-Itai Marienberg
				-Mon 13 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/

#ifndef __FILES_H__
#define __FILES_H__

#include <stdio.h>
#include <stdlib.h>
#define UNUSED(str) (void)(str) , (void)(file_name)

typedef struct general
{
	char *str;
    int (*p_cmp)(const char *s1, const char *s2);
    enum STATUS (*p_opr)(const char *file_name, char *str);
} general;

void Structs(general gen_arr[]);
int Compare(const char *s1, const char *s2);
int Compare_always(const char *s1, const char *s2);
enum STATUS RemoveFile(const char *file_name, char *str);
enum STATUS ExitProg(const char *file_name,char *str);
enum STATUS CountLines(const char *filename,char *str); 
enum STATUS AddString(const char *file_name, char *str);
enum STATUS AddStringTop(const char *file_name, char *str);
int StartProg(const char *file_name, general gen_arr[]);
int CharCompare(const char *s1, const char *s2);

#endif
