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
			
	else if ( 27 == choice)
			{
				printf("You entered Esc\n");
			}
	
	else  
			{
				printf("You entered invalid character \n");
			}
			
	system("stty icanon echo");
}

void PrintSwitch()
{
	
	char choice = '0';
	
	system("stty -icanon -echo");
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
		
		case 27:
			printf("You entered Esc\n");
			break;
		
		default:
			printf("You entered invalid character \n");
	}
	
	system("stty icanon echo");
}

void Myvoid(char choice)
{
	
}

void EscPrint(char choice)
{
 printf("You entered Esc\n");
}

void LUTPrint(char c)
{
	printf("%c is pressed \n",c);
}


