/*******************************************************************************
				-Ws5
				-Itai Marienberg
				-Mon 13 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/
enum STATUS{SUCC, FAIL, FAIL_OPEN,FAIL_REMOVE, EXIT};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

#define STRUCT_ARR 5

int main()
{
	general gen_arr[STRUCT_ARR];
	Structs(gen_arr);
	StartProg ("ws5try.txt", gen_arr);
	
	return 0;
}



