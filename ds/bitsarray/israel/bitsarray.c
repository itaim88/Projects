/************************************************
*
* File: bitsarray.c
* Ex: Bits Array
* writer: Israel Drayfus
* Description: library of functions for bits array.
*
*************************************************/

#include <assert.h> /* assert() */
#include "bitsarray.h" /* bitsarray header */

#define BITS_IN_WORD 64
#define UNUSED(var) (void)(var)

#define M1 (size_t) 0x5555555555555555
#define M2 (size_t) 0x3333333333333333
#define M4 (size_t) 0x0F0F0F0F0F0F0F0F
#define M8 (size_t) 0x00FF00FF00FF00FF
#define M16 (size_t) 0x0000FFFF0000FFFF
#define M32 (size_t) 0x00000000FFFFFFFF

#define MASK 1

#define ASCII_INT_TO_STRING '0' - 0

bitsarr_t BArrSetAllBits(bitsarr_t bits)
{
	UNUSED(bits);
	
	return ~((bitsarr_t) 0);
}

bitsarr_t BArrResetAllBits(bitsarr_t bits)
{
	UNUSED(bits);
	
	return (bitsarr_t) 0;
}

int BArrIsOn(bitsarr_t bits, int position)
{
	return !(!(bits & (bitsarr_t) MASK << (position - 1)));
}

int BArrIsOff(bitsarr_t bits, int position)
{
	return !(bits & (bitsarr_t) MASK << (position - 1));
}

bitsarr_t BArrCountOn(bitsarr_t bits)
{
	bits = (bits >> (bitsarr_t) 1 & M1) + (bits & M1);
	bits = (bits >> (bitsarr_t) 2 & M2) + (bits & M2);
	bits = (bits >> (bitsarr_t) 4 & M4) + (bits & M4);
	bits = (bits >> (bitsarr_t) 8 & M8) + (bits & M8);
	bits = (bits >> (bitsarr_t) 16 & M16) + (bits & M16);
	bits = (bits >> (bitsarr_t) 32 & M32) + (bits & M32);
	
	return bits;
}

bitsarr_t BArrCountOff(bitsarr_t bits)
{
	bits = (bits >> (bitsarr_t) 1 & M1) + (bits & M1);
	bits = (bits >> (bitsarr_t) 2 & M2) + (bits & M2);
	bits = (bits >> (bitsarr_t) 4 & M4) + (bits & M4);
	bits = (bits >> (bitsarr_t) 8 & M8) + (bits & M8);
	bits = (bits >> (bitsarr_t) 16 & M16) + (bits & M16);
	bits = (bits >> (bitsarr_t) 32 & M32) + (bits & M32);
	
	return BITS_IN_WORD - bits;
}

bitsarr_t BArrSetBit(bitsarr_t bits, int position, int status)
{
	if (1 == status)
	{
		return bits | MASK << (position - 1);
	}
	else
	{
		return bits & ~(MASK << (position - 1));
	}
}

bitsarr_t BArrSetOn(bitsarr_t bits, int position)
{
	return bits | MASK << (position - 1);
}

bitsarr_t BArrSetOff(bitsarr_t bits, int position)
{
	return bits & ~(MASK << (position - 1));
}

bitsarr_t BArrRotateLeft(bitsarr_t bits, int num_of_rotations)
{
	while (0 < num_of_rotations)
	{
		if (((bitsarr_t) MASK << (BITS_IN_WORD - 1)) & bits)
		{
			bits <<= 1;
			bits |= 1;
		}
		else
		{
			bits <<= 1;
		}
		
		--num_of_rotations;
	}
	
	return bits;
}

bitsarr_t BArrRotateRight(bitsarr_t bits, int num_of_rotations)
{
	while (0 < num_of_rotations)
	{
		if (MASK & bits)
		{
			bits >>= 1;
			bits |= ((bitsarr_t) MASK << (BITS_IN_WORD - 1));
		}
		else
		{
			bits >>= 1;
		}
		
		--num_of_rotations;
	}
	
	return bits >> num_of_rotations;
}

char *BArrToString(bitsarr_t bits, char *buffer)
{
	char *runner = NULL;
	int i = 0;
	
	assert(NULL != buffer);
	
	runner = buffer;
	
	for (i = BITS_IN_WORD; 0 < i; --i)
	{
		*runner = (char) BArrIsOn(bits, i) + ASCII_INT_TO_STRING;
		++runner;
	}
	
	*runner = '\0';
	
	return buffer;
}

bitsarr_t BArrFlipBit(bitsarr_t bits, int position)
{
	if (1 == BArrIsOn(bits, position))
	{
		return BArrSetOff(bits, position);
	}
	else
	{
		return BArrSetOn(bits, position);
	}
}

bitsarr_t BArrMirror(bitsarr_t bits)
{
	bits = (bits << 32) | (bits >> 32);
	bits = ((bits  & M16) << 16) | ((bits >> 16) & M16);
	bits = ((bits & M8) << 8) | ((bits >> 8) & M8);
	bits = ((bits & M4) << 4) | ((bits >> 4) & M4);
	bits = ((bits & M2) << 2) | ((bits >> 2) & M2);
	bits = ((bits & M1) << 1) | ((bits >> 1) & M1);
	
	return bits;
}



