
#include <stdlib.h>
#include <stdio.h>

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
	unsigned int check = 1;
	
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
      
    // Flip all the set bits  
    // until we find a 0  
    while( x & m ) 
    { 
        x = x ^ m; 
        m = m << 1; 
    } 
      
    // flip the rightmost 0 bit  
    x = x ^ m; 
    return x;
/********** add 1 *************************************************************/
void Add1(unsigned int arr[])
{
	
	printf("");
}	


































