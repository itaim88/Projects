/*******************************************************************************
				-Ws6
				-Itai Marienberg
				-Mon 13 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "bit.h"



int main()
{
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
	
	/*unsigned int x = ~0;
	printf("%u\n",reverseBits(x));*/
	
	uint64_t i = 10;
	printf("%d\n",MynumberOfSetBits(i));
	
	
	return 0;
}



