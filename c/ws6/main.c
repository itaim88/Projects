/*******************************************************************************
				-Ws6
				-Itai Marienberg
				-Mon 17 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include "bit.h"

#define NRM "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define CYN  "\x1B[36m"

void Test( int cond, const char *err_msg )
{
	if (cond == 0)
	{
	printf(RED "%s:"NRM" %s\n" ,"ERROR:",err_msg);
	}
	if (cond == 1)
	{
	puts(GREEN "Succses" NRM);
	}
}
int main()
{
	float f = -2.25;
	FloatBinary(f);
   	
	printf(CYN"Checking func NO Arithmetic Add\n"NRM);
	Test((6==addOne(5)),"Noraml Addition Failure\n");
	Test((0==addOne(-1)),"Negative Number Increment Failure\n");
	Test((1==addOne(0)),"Failure calculating increment for Zero\n");
	   
	printf(CYN"Checking func Is Power of Two\n"NRM);
	Test((1==IsPow2(1024)),"Positive Control Failed\n");
	Test((0==IsPow2(1)),"Failure calculating for One\n");
	Test((1==IsPow2(2)),"Failure calculating for two\n");
	Test((0==IsPow2(0)),"Failure calculating for two\n");
	   
	printf(CYN"Checking func X*2^Y\n"NRM);
	Test((10*pow(2,5)==Pow2(10,5)),"Positive Control Failed\n");
	Test((10*pow(2,33)==Pow2(10,33)),"Faliure for checking y> number of bits\n");
	   
	printf(CYN"Checking unlooped Is Power of Two\n"NRM);
	Test((1==IsPow2NoLoop(1024)),"Positive Control Failed\n");
	Test((0==IsPow2NoLoop(1)),"Failure calculating for One\n");
	Test((1==IsPow2NoLoop(2)),"Failure calculating for two\n");
	Test((0==IsPow2NoLoop(0)),"Failure calculating for Zero\n");
	
	return 0;
}




