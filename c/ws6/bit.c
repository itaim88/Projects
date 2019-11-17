/*******************************************************************************
				-Ws6
				-Itai Marienberg
				-Mon 13 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "bit.h"
/********** x*(2^y) ***********************************************************/
long Pow2(unsigned int x, unsigned int y)
{
	while ( y > 0)
	{
		x = x << 1;	
		--y;
	}
	
	return x;
}	
/********** loop **************************************************************/
int IsPow2(unsigned int n)
{
	unsigned int check = 1;
	
	while ( check < n + 1)
		{
		    
			if ( check == n)
			{
				return 1;
			}
			
			else
			{
				check = check << 1;
			}
		}
		
	return 0;
}
/********** no loop ***********************************************************/
int IsPow2NoLoop(unsigned int n)
{
	if ( 0 == ((n - 1) & n )) 
	{
		return 1;
	}
	return 0;
}
/********** add 1 *************************************************************/
 int Add1(unsigned int n)
{
	return (-(~n)); /* can use abs() */ 
} 

int addOne(unsigned int x) 
{ 
    unsigned int m = 1;     
    /*Flip all the set bits  
    until we find a 0 */
       
    while( 0 != (x & m) ) 
    { 
        x = x ^ m; 
        m = m << 1; 
    }    
    /* flip the rightmost 0 bit */  
    x = x ^ m; 
    return x;
}    
/********** 3 bits ************************************************************/
void ThreeBits(unsigned int arr[])
{
    int count = 0;
    int i = 0;
    unsigned int remember = 0;
    for ( i = 0 ; i < ARR_SIZE ; ++i )
    {
        remember = *(arr + i);
        count = 0;
        while ( 0 != *(arr + i))
        {
          *(arr + i) = *(arr + i) & ((*(arr + i)) - 1);
          ++count;
        }

        if ( THIRD_BIT == count)
        {
            printf("%d\n", remember);
        }
    }
}
/********** BYTE MIRROR *******************************************************/
unsigned int reverseBits(unsigned int num) 
{ 
    unsigned int NO_OF_BITS = sizeof(num) * BYTE; 
    unsigned int reverse_num = 0; 
  	unsigned int i = 0; 
    for (i = 0; i < NO_OF_BITS; i++) 
    { 
        if (0 != (num & (1 << i))) 
        {
           reverse_num = reverse_num | (1 << ((NO_OF_BITS - 1) - i));  
        }
    } 
    return reverse_num; 
} 
/********** 2 and 6 are 1 *****************************************************/
unsigned int SecAndSix(unsigned int n)
{
    unsigned int sec = 0;
    unsigned int six = 0;
    sec = ( n & 1 << SEC);
    six = ( n & 1 << SIX);
    return (68 - sec - six);
}
/********** 2 or 6 are 1 *****************************************************/
unsigned int SecOrSix(unsigned int n)
{
    unsigned int sec = 0;
    unsigned int six = 0;
    unsigned int result = 0;
    sec = ( n & 1 << SEC);
    six = ( n & 1 << SIX);
    result = sec + six;

    switch(result)
    {
        case 4:
            return 0;
            break;
        case 64:
            return 0;
            break;
        case 68:
            return 0;
            break;
    }
    return 1;
}
/********** 3 and 5 swaps *****************************************************/
unsigned int SwapBit(unsigned int n)
{
    unsigned int bit3 =  (n >> THIRD_BIT) & 1;
    unsigned int bit5 =  (n >> FIVE_BIT) & 1;
    unsigned int x = (bit3 ^ bit5);
    unsigned int result = 0;
    x = (x << THIRD_BIT) | (x << FIVE_BIT);
    result = n ^ x;
    return result;
}
/********** 16 no remainder ***************************************************/
int SmallestDev(unsigned int n)
{
/* (~0) is the largest unsigned int,
subtraction 15 (set zero at index 0,1,2,3)*/
    return  n = n & ((~0) - ZERO_INDEX); 
}
/********** swap variables****************************************************/
int SwapVar(int *x, int *y)
{
 	*x = *x ^ *y; 
    *y = *x ^ *y;
    *x = *x ^ *y;
    return 0; 
} 
/********** set bits***************************************************/
int SetBit(unsigned int n)
{
	unsigned int count = 0;
	
 	while ( 0 != n)
 	{
 		if (1 == (n & 1))
 		{
 			++count;	
 		}		
 		n = n >> 1;
 	}
 	
    return count; 
} 
/********** set bits no loop **************************************************/
int numberOfSetBits(unsigned int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
/********** set bits no loop **************************************************/
int MynumberOfSetBits(uint64_t x)
{
	const uint64_t m1  = 0x55555555; 
	const uint64_t m2  = 0x33333333; 
	const uint64_t m4  = 0x0f0f0f0f; 
	const uint64_t m8  = 0x00ff00ff; 
	const uint64_t m16 = 0x0000ffff; 
	const uint64_t m32 = 0x0000ffff; 
	const uint64_t h01 = 0x01010101;

	x = (x & m1 ) + ((x >>  1) & m1 ); 
	x = (x & m2 ) + ((x >>  2) & m2 ); 
	x = (x & m4 ) + ((x >>  4) & m4 ); 
	x = (x & m8 ) + ((x >>  8) & m8 ); 
	x = (x & m16) + ((x >> 16) & m16);  
	/*x = (x & m32) + ((x >> 32) & m32);*/ 
	return x;
}




















