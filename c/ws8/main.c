/*******************************************************************************
-Ws8
-Itai Marienberg
-Mon 20 Nov 2019 14:50:59    
 -Reviewer:
*******************************************************************************/

#include "myprogram.h"

int main()
{
	int Succes = 0;
	
	addprint arr[NUM_ELEMENTS];
	Succes = Initialize(arr);
	if ( 0 != Succes)
	{
		printf("Fail to Initialize");
		return 1; 
	}
	
	Succes = RunProgram(arr);
	if ( 0 != Succes)
	{
		printf("Fail to Initialize");
		return 1; 
	}
	
	return 0;
}



