/*******************************************************************************
-Ws8
-Itai Marienberg
-Mon 20 Nov 2019 14:50:59    
 -Reviewer:
*******************************************************************************/

#ifndef __MYPROGRAM_H__
#define __MYPROGRAM_H__

#include <stdio.h>	/* printf */
#include <string.h>	/* strlen */
#include <stdlib.h>	/* malloc */
#include <assert.h> /* assert pointers to NULL */

#define NUM_ELEMENTS 3 
#define NUMBER_TO_ADD 10
#define BUFFER 8 
#define STRING_LENGTH 6 

typedef struct basic
{
	int (*print) (const void *data);	
	int (*add) (void *data);	
	void *data;
	int (*clean) (void *data);

}addprint;

int StructArrInt(addprint arr[]);
int Initialize(addprint arr[]);
int PrintInt(const void *data);
int AddInt(void *data);
int PrintFloat(const void *data);
int AddFloat(void *data);
int PrintString(const void *data);
int AddString(void *data);
int Cleaner(void *data);
int NoNeedCleaner(void *data);

#endif
