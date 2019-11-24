/*******************************************************************************
-Ws9
-Itai Marienberg
-Mon 20 Nov 2019 14:50:59    
 -Reviewer:
*******************************************************************************/
#ifndef __WORD_H__
#define __WORD_H__

#include <stdio.h>	/* printf */
#include <string.h>	/* strlen */
#include <assert.h> /* assert pointers to NULL */
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define WORD 8
#define BYTE 8
#define MAX_INT 2147483647
#define DIGIT "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define IS_LITTLE_ENDIEN(a) ((1 == *(char*)(&a))?(printf("Little Endian\n"))\
												:(printf("Big Endian\n")))

size_t CharOfWord(char c);
void *Mymemset(void *str, int c, size_t n);
size_t StringOfWord(char *src);
void *Mymemcpy(void *destanation, const void *source, size_t n);

int Myatoi(const char *str);
char* Myitoa(int i, char buffer[],int base);
int val(char c);
int MyatoiBase(char *str, int base);
int LittleOrBigEndian();

#endif
