/*******************************************************************************
				-Ws4
				-Itai Marienberg
				-Mon 11 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lut.h"

void PrintIf()
{	
	char choice = '0';
	
	system("stty -icanon -echo");
	
	while(27 != choice)
	{
	printf("Please pressed A or T or Esc to exit: \n");
	scanf("%c", &choice);
	
	if('A' == choice)
			{
				printf("You entered A\n");
			}
			
	else if('T' == choice)
			{
				printf("You entered T\n");
			}
	else  
			{
				printf("You entered invalid character \n");
			}
			
	}
	system("stty icanon echo");
}

void PrintSwitch()
{
	
	char choice = '0';
	
	system("stty -icanon -echo");
	
	while(27 != choice)
	{
	printf("Please pressed A or T or Esc to exit: \n");
	scanf("%c", &choice);
	
		switch (choice)
		{
			case 'A':
				printf("You entered A\n");
				break;
				
			case 'T':
				printf("You entered T\n");
				break;
			
			default:
				printf("You entered invalid character \n");
		}
	}
	system("stty icanon echo");
}

int Myvoid(char choice)
{
	return NULL;
}

int EscPrint(char choice)
{
 printf("You entered Esc\n");
 
	 return 1;
}

int LUTPrint(char c)
{
 printf("%c is pressed \n",c);
	return 0;
}


