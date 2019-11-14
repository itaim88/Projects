

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
	
	if ( ((n - 1) & n ) == 0) 
	{
		return 1;
	}
	return 0;
}











