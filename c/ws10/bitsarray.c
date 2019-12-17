/*******************************************************************************
-Ws10
-Itai Marienberg
-Mon 26 Nov 2019    
-Reviewer:
*******************************************************************************/

#include <stdio.h>

#include "bitsarray.h"
#define BYTES 8
#define TOTAL_BITS 64
#define DIGIT "01"
#define BASE 2
#define m1 0xaaaaaaaaaaaaaaaa
#define m2 0xcccccccccccccccc
#define m3 0xf0f0f0f0f0f0f0f0
#define m4 0xff00ff00ff00ff00
#define m5 0x0000ffff0000ffff


/*********set all bits to 1****************************************************/
size_t BArrSetAllBits(size_t bits)
{
	return (bits |= ~0);
}

/*********set all bits to 0****************************************************/
size_t BArrResetAllBits(size_t bits)
{
	return bits &= 0; 
}

/*********check if bit is 1 in position ***************************************/
int BArrIsOn(size_t bits, int position)
{
	return (0 != (bits & (1 << (position - 1)))); 
}
	
/*********check if bit is 0 in position ***************************************/
int BArrIsOff(size_t bits, int position)
{
	return (0 != (bits ^ (1 << (position - 1)))); 
}

/*********Count bit set 1 ****************************************************/
size_t BArrCountOn(size_t bits)
{
	int count = 0;
	
	while ( 0 != bits )
	{
		bits = bits & (bits -1);
		++count;
	}
	
	return count;
}

/*********check if bit is 1 in position ***************************************/
size_t BArrCountOff(size_t bits)
{
	int count = 0;
	
	while ( 0 != bits )
	{
	bits = bits & (bits -1);
	++count;
	}
	
	return ((sizeof(size_t) * BYTES) - count);
}

/****This function sets specific bit to the given status *********************/
size_t BArrSetBit(size_t bits, int position, int status)
{
	if ( 1 == status)
	{
	return (bits |= (1 << (position - 1))); 
	}	
	
	else
	{
	return (bits &= ((~0) - (1 << (position -1))));
	}
}

/****This function sets specific bit to the given status *********************/
size_t BArrSetOn(size_t bits, int position)
{
	return (bits |= (1 << (position -1)));
}
/****This function sets specific bit to the given status *********************/
size_t BArrSetOff(size_t bits, int position)
{
	return (bits &= ((~0) - (1 << (position -1))));
}

/***** This function rotate the array to left n times ************************/
size_t BArrRotateLeft(size_t bits, int num_of_rotations)
{
	while (0 < (num_of_rotations % (TOTAL_BITS)))
	{
		if (1 == BArrIsOn(bits, TOTAL_BITS))   
		{
			bits <<= 1;
			bits = BArrSetBit(bits, 1, 1);	
		}
		
		else   
		{
			bits <<= 1;
		}
		
		--num_of_rotations;
	}
	return bits;
}

/* This function rotate the array to right n times ***************************/
size_t BArrRotateRight(size_t bits, int num_of_rotations)
{
	while (0 < (num_of_rotations % (TOTAL_BITS)))
	{
		if (1 == BArrIsOn(bits, 1))   
		{
			bits >>= 1;
			bits = BArrSetBit(bits, TOTAL_BITS, 1);	
		}
		
		else   
		{
			bits >>= 1;
		}
		
		--num_of_rotations;
	}
	return bits;
}

/**** This function return a string presentation of given bits array **********/
char* BArrToString(size_t bits, char* buffer)
{
	size_t i = 0;

	for (i = TOTAL_BITS; 0 < i; --i)
	{
		if (0 != (bits & (1 << (i - 1))))
		{
		*buffer = '1';
		}
		else
		{
		*buffer = '0';
		}

	++buffer;
	}
	
	*buffer = '\0';
	buffer -= TOTAL_BITS;

	return buffer;
}

/* This function flips specific bit *******************************************/
size_t BArrFlipBit(size_t bits, int position)
{
	return (bits ^= (1 << (position -1)));
}

/* This function mirroring a given bits array *********************************/
size_t BArrMirror(size_t bits)
{
	bits = (((bits & m1) >> 1) | ((bits & -m1) << 1));
	bits = (((bits & m2) >> 2) | ((bits & -m2) << 2));
	bits = (((bits & m3) >> 4) | ((bits & -m3) << 4));
	bits = (((bits & m4) >> 8) | ((bits & -m4) << 8));
	bits = (((bits & m5) >> 16) | ((bits & -m5) << 16));
	bits = ((bits >> 32) | (bits << 32));
	
    return bits; 
}








