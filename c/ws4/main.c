/*******************************************************************************
				-Ws4
				-Itai Marienberg
				-Mon 11 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lut.h"

int main()
{
/* this is if/else test **********************/
 
	/* PrintIf();  */   
	 
	/******* this is switch case test*************/
		 
   /*PrintSwitch();*/  
	
	/***this LUT test ****************************/ 
	
	char choice = '0';
	int (*ptr[256]) (char);
	int i = 0;
	system("stty -icanon -echo");
	
	
	for( i = 0 ; i < 256; ++i)
		{
			ptr[i] = Myvoid;
		}
		
	ptr[65] = &LUTPrint;
	ptr[84] = &LUTPrint;
	ptr[27] = &EscPrint;
	
	while(*ptr[choice]) (choice) != 1)
	{
	printf("Please pressed A or T or Esc to exit: \n");
	scanf("%c", &choice);
	
	(*ptr[choice]) (choice);
	}
	
	system("stty icanon echo");	
	return 0;
}
