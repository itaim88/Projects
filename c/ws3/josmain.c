/*******************************************************************************
				-Ws3 - Josephus
				-Itai Marienberg
				-Mon 04 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "mycodes.h"

/*void ArrCreate(int N);*/

int main()
{
	int N = 10;                                        /* number of soldiers */
 	int arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};	
	int index = 3;                         /* the user first soldier choise */
	int i = index - 1;               /* the actual user first soldier choise */
	int *end = arr + (N-1);
	int *start = arr;
	int *sword = arr;
	int alive = N;
	
	sword = sword + index;
			
	while ( alive > 1 ) 
			{
			
			
			
			MoveToNextAlive( sword, end, start);
				
			printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,		 \n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9]);
			
			alive--;
			}
			
	return 0;

}

 
