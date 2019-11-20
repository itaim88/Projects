

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "myprogram.h"

/***********************************/
void StructArrInt(addprint arr[])
{
	arr[0].print = &PrintInt;
	*(int*)(&arr[0].data) = 10;
	arr[0].add = &AddInt;
	arr[0].clean = &NoNeedCleaner;
	
	arr[1].print = &PrintFloat;
	*(float*)(&arr[1].data) = 2.6;
	arr[1].add = &AddFloat;
	arr[1].clean =&NoNeedCleaner;
	
	arr[2].data = malloc(6);
	strcpy(arr[2].data, "Hello");
	arr[2].print = &PrintString;
	arr[2].add = &AddString;
	arr[2].clean = &Cleaner;
	
}
/*****************************************************************************/
int Initialize(addprint arr[])
{
	int i = 0;
	
	for ( i = 0 ; i < NUM_ELEMENTS ; ++i)
	{
		arr[i].print(arr[i].data);
		arr[i].add(&arr[i].data);
		arr[i].print(arr[i].data);
	}
	return 0;
}
/*****************************************************************************/
int AddInt(void *data)
{
	*(int*)(data) = NUMBER_TO_ADD + (*(int*)(data));
	return 0;
}
/*****************************************************************************/
int AddFloat(void *data)
{
	*(float*)(data) = NUMBER_TO_ADD + (*(float*)(data));
	return 0;
}
/*****************************************************************************/
int AddString(void *data)
{	
	char buffer[BUFFER];
	int count = 0;
	int length = 0;
	int n = NUMBER_TO_ADD;
	int x = n;
	length = strlen(*(char**)data);
	
	while( 0 != x)
	{
		x = x / 10;
		++count;
	}
	
	*(char**)data = realloc(*(char**)data, length + 1 + count);
	sprintf(buffer,"%d", n);
	strcat(*(char**)data, buffer);

	return 0;
} 
/*****************************************************************************/

int PrintInt(const void *data)
{
	printf("int value is %d\n",*(int*)(&data));   
	return 0;
}
/*****************************************************************************/
int PrintFloat(const void *data)
{
	printf("float value is %f\n",*(float*)(&data)); 
	return 0;
}
/*****************************************************************************/
int PrintString(const void *data)
{
	printf("%s\n",(char*)(data)); 
	return 0;
}
/*****************************************************************************/
int Cleaner(void *data)
{
	free(data); 
	data = NULL;
	return 0;
}
/*****************************************************************************/
int NoNeedCleaner(void *data)
{
	return 0;
}
















