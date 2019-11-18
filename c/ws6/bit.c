/*******************************************************************************
				-Ws6
				-Itai Marienberg
				-Mon 17 Nov 2019 14:50:59    
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
	if ( 0 == n )
	{
		return 0;
	}
	
    while (0 == n % 2)
    {
        n = n >> 1;
    }
    
    if (1 == n)
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
/********** BYTE MIRROR no loop ***********************************************/
unsigned int reverseBitsNoLoop(unsigned int num) 
{ 
	num = (((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1));
	num = (((num & 0xcccccccc) >> 2) | ((num & 0x33333333) << 2));
	num = (((num & 0xf0f0f0f0) >> 4) | ((num & 0x0f0f0f0f) << 4));
	num = (((num & 0xff00ff00) >> 8) | ((num & 0x00ff00ff) << 8));
	num = ((num >> 16) | (num << 16));
    return num; 
} 
/********** 2 and 6 are 1 *****************************************************/
unsigned int SecAndSix(unsigned int n)
{
    unsigned int sec = 0;
    unsigned int six = 0;
    
    sec = ( n & 1 << SEC);
    six = ( n & 1 << SIX);
    return (SEC_SIX - sec - six);
}
/********** 2 or 6 are 1 *****************************************************/
unsigned int SecOrSix(unsigned int n)
{
	unsigned sec = ((n & (1 << SEC)) >> SEC);
	unsigned six = ((n & (1 << SIX)) >> SIX);
	
	return sec | six;
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
int MynumberOfSetBits(unsigned int x)
{
	x = (x & 0x55555555 ) + ((x >> 1) & 0x55555555 ); 
	x = (x & 0x33333333 ) + ((x >> 2) & 0x33333333 ); 
	x = (x & 0x0f0f0f0f ) + ((x >> 4) & 0x0f0f0f0f ); 
	x = (x & 0x00ff00ff ) + ((x >> 8) & 0x00ff00ff ); 
	x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);  
	
	return x;
}
/********** print float bits **************************************************/
/*void printBinary(int n, int i) 
{ 
    int k; 
    for (k = i - 1; k >= 0; k--)
    { 
        if ((n >> k) & 1) 
        {
            printf("1"); 
        }
        else
        {
            printf("0");
        } 
    } 
} 

void printIEEE(myfloat var) 
{ 
    printf("%d | ", var.raw.sign); 
    printBinary(var.raw.exponent, 8); 
    printf(" | "); 
    printBinary(var.raw.mantissa, 23); 
    printf("\n"); 
} */

/* This function gets float and print the binary number*/
void FloatBinary(float f)
{
    unsigned int *p;
    
    p = (unsigned int *)(&f);
    PrintBinary(*p);
}

/* This function gets number and display binary number*/
void PrintBinary(unsigned int n)
{
    unsigned int  i = (1 << (INT_SIZE - 1));
    
    for ( ; i > 0; i >>= 1)
    {
        (n & i) ? printf("1") : printf("0");
    }
    printf("\n");
}












