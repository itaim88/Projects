/*******************************************************************************
				-Ws6
				-Itai Marienberg
				-Mon 13 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
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
int Add1(int n)
{
	return (-(~n)); /* can use abs() */ 
} 

int addOne(int x) 
{ 
    int m = 1;     
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

        if ( 3 == count)
        {
            printf("%d\n", remember);
        }
    }
}
/********** BYTE MIRROR *******************************************************/
unsigned int reverseBits(unsigned int num) 
{ 
    unsigned int NO_OF_BITS = sizeof(num) * 8; 
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
    sec = ( n & 1 << 2);
    six = ( n & 1 << 6);
    return (68 - sec - six);
}
/********** 2 or 6 are 1 *****************************************************/
unsigned int SecOrSix(unsigned int n)
{
    unsigned int sec = 0;
    unsigned int six = 0;
    unsigned int result = 0;
    sec = ( n & 1 << 2);
    six = ( n & 1 << 6);
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
    unsigned int bit3 =  (n >> 3) & 1;
    unsigned int bit5 =  (n >> 5) & 1;
    unsigned int x = (bit3 ^ bit5);
    unsigned int result = 0;
    x = (x << 3) | (x << 5);
    result = n ^ x;
    return result;
}
/********** 16 no remainder ***************************************************/
int SmallestDev(unsigned int n)
{
/* (~0) is the largest unsigned int,
subtraction 15 (set zero at index 0,1,2,3)*/
    return  n = n & ((~0)-15); 
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
int SetBit(int n)
{
	int count = 0;
	
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
int SetBitNoLoop(int n)
{
 	n= (n & (~0));
    return n; 
} 



























