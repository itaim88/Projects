/*******************************************************************************
-Ws1
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
#define m4 0xf0f0f0f0f0f0f0f0
#define m8 0xff00ff00ff00ff00
#define m16 0x0000ffff0000ffff
#define MASK_1 0x01UL
#define BITWISE1 1
#define BITWISE2 2
#define BITWISE4 4
#define BITWISE8 8
#define BITWISE16 16
#define BITWISE32 32
#define MSB 0x8000000000000000UL

/*********set all bits to 1****************************************************/
bitsarr_t BArrSetAllBits(bitsarr_t bits)
{
	return (bits |= ~0);
}

/*********set all bits to 0****************************************************/
bitsarr_t BArrResetAllBits(bitsarr_t bits)
{
	return bits &= 0; 
}

/*********check if bit is 1 in position ***************************************/
int BArrIsOn(bitsarr_t bits, int position)
{
	return (0 != (bits & (MASK_1 << (position - 1)))); 
}
	
/*********check if bit is 0 in position ***************************************/
int BArrIsOff(bitsarr_t bits, int position)
{
	if ((0 == (bits & (MASK_1 << (position - 1))))) 
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

/*********Count bit set 1 ****************************************************/
bitsarr_t BArrCountOn(bitsarr_t bits)
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
bitsarr_t BArrCountOff(bitsarr_t bits)
{
	int count = 0;
	
	while (0 != bits )
	{
		bits = bits & (bits -1);
		++count;
	}
	
	return ((sizeof(size_t) * BYTES) - count);
}

/****This function sets specific bit to the given status *********************/
bitsarr_t BArrSetBit(bitsarr_t bits, int position, int status)
{
	if ( 1 == status)
	{
		return (bits |= (MASK_1 << (position - 1))); 
	}	
	
	else
	{
		return (bits &= ((~0) - (MASK_1 << (position -1))));
	}
}

/****This function sets specific bit to the given status *********************/
bitsarr_t BArrSetOn(bitsarr_t bits, int position)
{
	return (bits |= (0x01UL << (position -1)));
}
/****This function sets specific bit to the given status *********************/
bitsarr_t BArrSetOff(bitsarr_t bits, int position)
{
	return (bits &= ((~0) - (MASK_1 << (position -1))));
}

/***** This function rotate the array to left n times ************************/
bitsarr_t BArrRotateLeft(bitsarr_t bits, int num_of_rotations)
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
bitsarr_t BArrRotateRight(bitsarr_t bits, int num_of_rotations)
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
char* BArrToString(bitsarr_t bits, char* buffer)
{
	size_t i = 0;

	for (i = TOTAL_BITS; 0 < i; --i)
	{
		if (0 != (bits & (MASK_1 << (i - 1))))
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
bitsarr_t BArrFlipBit(bitsarr_t bits, int position)
{
	return (bits ^= (MASK_1 << (position -1)));
}

/* This function mirroring a given bits array *********************************/
bitsarr_t BArrMirror(bitsarr_t bits)
{
bits = (((bits & 0xaaaaaaaaaaaaaaaa) >> BITWISE1) | ((bits & 0x5555555555555555)
		 << BITWISE1));
bits = (((bits & 0xcccccccccccccccc) >> BITWISE2) | ((bits & 0x3333333333333333)
		 << BITWISE2));
bits = (((bits & 0xf0f0f0f0f0f0f0f0) >> BITWISE4) | ((bits & 0x0f0f0f0f0f0f0f0f)
		 << BITWISE4));
bits = (((bits & 0xff00ff00ff00ff00) >> BITWISE8) | ((bits & 0x00ff00ff00ff00ff)
		 << BITWISE8));
bits = (((bits & 0xffff0000ffff0000) >> BITWISE16) | ((bits & 0x0000ffff0000ffff
		) << BITWISE16));
		
return ((bits >> BITWISE32) | (bits << BITWISE32));
	
}








