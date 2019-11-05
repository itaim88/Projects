/*******************************************************************************
				-Ws2
				-Itai Marienberg
				-Mon 04 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/


/* Exercise 1 this function calculate the length of a string without the '\0' */
#ifndef __MYSTRLEN_H__
#define __MYSTRLEN_H__

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>


size_t Mystrlen(const char *str);


size_t Mystrcmp(const char *str1, const char *str2);


char *Mystrcpy(char *destination, const char *source);
 

char *Mystrncpy(char *dest, const char *src, size_t n);


size_t Mystcasecmp(const char *string1, const char *string2);

char *Mystrchr(const char *s, int c);

#endif
  
   
























