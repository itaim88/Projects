#ifndef __MYMEM_H__
#define __MYMEM_H__

#include<stdio.h>	/* For printf*/
#include <string.h> /* For strcpy*/
#include<assert.h>  /* For assert*/
#include<stdlib.h>	/* For strchr*/


void *MyMemset(void *str, int c, size_t n);
void *MyMemcpy(void *dest, const void *source, size_t n);
void *MyMemMoveReverse(void *dest, const void *source, size_t n);
void *MyMemMove(void *dest, const void *source, size_t n);
void *MyItoa(const int value, char *str, int base);
size_t MyAtoi(const char *str, int base);
void TowOrNathing(const char arr1[], const char arr2[], const char arr3[]);
void LittleOrBigEndian();

#endif
