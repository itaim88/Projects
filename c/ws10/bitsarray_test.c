/*******************************************************************************
-Ws10
-Itai Marienberg
-Mon 24 Nov 2019   
 -Reviewer: 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "bitsarray.h"
#define TOTAL_BITS 64

int main()
{
	char *string_buffer = (char *)calloc(TOTAL_BITS + 1, sizeof(char));
	
	printf("BArrSetAllBits %lu\n",BArrSetAllBits(1));
	printf("BArrResetAllBits %ld\n",BArrResetAllBits(1));
	printf("BArrIsOn %d\n",BArrIsOn(8, 3));
	printf("BArrIsOff %d\n",BArrIsOff(8, 3));
	printf("BArrCountOn %ld\n", BArrCountOn(7));
	printf("BArrCountOff %ld\n", BArrCountOff(7));
	printf("BArrSetBit %ld\n", BArrSetBit(0,1,1));;
	printf("BArrSetOnt %ld\n", BArrSetOn(7,4));
	printf("BArrSetOff %ld\n", BArrSetOff(7,3));
	printf("BArrFlipBit %ld\n", BArrFlipBit(8,1));
	printf("BArrRotateLeft %lu\n",BArrRotateLeft(~0,1));
	printf("BArrRotateLeft %lu\n",BArrRotateLeft(4,1));
	printf("BArrRotateRight %lu\n",BArrRotateRight(4,1));
	printf("BArrRotateRight %lu\n",BArrRotateRight(~0,1));
	
	printf("BArrToString %s\n",BArrToString(10,string_buffer));
	free(string_buffer);
	
	printf("BArrMirror %lu\n", BArrMirror(~0));
	
	return 0;
}
