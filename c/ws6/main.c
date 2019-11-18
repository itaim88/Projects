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
	puts(GREEN "GREAT " NRM);
	}
}
int main()
{
	float f = -2.25;
   /* ***unsigned int x[ARR_SIZE] = {14, 0, 67, 14, 7};
    ThreeBits(x);****/
    
	/***unsigned int c = 100;
    printf("%d\n" ,SecAndSix(c)); /* if 0 true, else something else****/
    
	/*****unsigned int c = 65;
    printf("%d\n" ,SecOrSix(c)); /* if 0 true, else something else******/
    
	/*****unsigned int num = 8;
    printf("%d\n", SwapBit(num));
    
	SmallestDev(81);******/
	
	/*******
	int x = 10;
	int y = 5;
	
	SwapVar(&x, &y);
	printf("After Swapping: x = %d, y = %d\n", x, y); ******/ 
	
	/*printf("%d\n",SetBit(0));*/
	
	/*unsigned int x = 38;
	printf("%u\n",reverseBits(x));*/
	
	/*uint64_t i = 10;
	printf("%d\n",MynumberOfSetBits(i));*/
	
	/*printf("%u\n",reverseBitsNoLoop(~0));*/
	
	  

    
   FloatBinary(f);
   	
   /*printf(CYN"Checking func NO Arithmetic Add\n"NRM);
   Test((6==NoArithAdd(5)),"Noraml Addition Failure\n");
   Test((0==NoArithAdd(-1)),"Negative Number Increment Failure\n");
   Test((1==NoArithAdd(0)),"Failure calculating increment for Zero\n");
   printf(CYN"Checking func Is Power of Two\n"NRM);
   Test((1==Ispoweroftwo(1024)),"Positive Control Failed\n");
   Test((0==Ispoweroftwo(1)),"Failure calculating for One\n");
   Test((1==Ispoweroftwo(2)),"Failure calculating for two\n");
   Test((0==Ispoweroftwo(0)),"Failure calculating for two\n");
   printf(CYN"Checking func X*2^Y\n"NRM);
   Test((10*pow(2,5)==Pow2(10,5)),"Positive Control Failed\n");
   Test((10*pow(2,33)==Pow2(10,33)),"Faliure for checking y> number of bits\n");
   printf(CYN"Checking unlooped Is Power of Two\n"NRM);
   Test((1==UnLoopedIsPowerofTwo(1024)),"Positive Control Failed\n");
   Test((0==UnLoopedIsPowerofTwo(1)),"Failure calculating for One\n");
   Test((1==UnLoopedIsPowerofTwo(2)),"Failure calculating for two\n");
   Test((0==UnLoopedIsPowerofTwo(0)),"Failure calculating for Zero\n");*/
	
	return 0;
}




