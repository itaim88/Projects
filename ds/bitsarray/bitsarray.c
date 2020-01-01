/*********************************/
/*    Data Structures            */
/*    Bits Arrays                */       
/*    Author : itai           */
/*    Reviewed By: Israel        */
/*    Date: 26/11/2019           */
/*********************************/

#include <stdio.h> /*size_t*/
#include <assert.h> /*assert*/

#include "bitsarray.h"

#define SYSTEM_BITS 64 /*64 bits in word*/
#define HALF_SYSTEM_BITS 32
#define M1 (size_t) 0x5555555555555555
#define M2 (size_t) 0x3333333333333333
#define M4 (size_t) 0x0f0f0f0f0f0f0f0f
#define M8 (size_t) 0x00ff00ff00ff00ff
#define M16 (size_t) 0x0000ffff0000ffff
#define M64 (size_t) 0xffffffffffffffff
#define MASK1 (size_t) 0x0000000000000000001

/* This function sets all bits to 1 */
bitsarr_t BArrSetAllBits(bitsarr_t bits)
{
    return ~(bits & 0);
}

/* This function sets all bits to 0 */
bitsarr_t BArrResetAllBits(bitsarr_t bits) 
{
    return (bits & 0);
}

/* This function checks if given bit is 1 */
int BArrIsOn(bitsarr_t bits, int position)
{
    bits >>= (position - 1);
    return (bits & MASK1);
}

/* This function checks if given bit is 0 */
int BArrIsOff(bitsarr_t bits, int position)
{
    bits >>= (position - 1);
    return !(bits & MASK1);
}

/* This function return the number of the on bits */
size_t BArrCountOn(bitsarr_t bits)
{
    size_t count = 0;

    while (0 != bits)
    {
        count += (bits & MASK1);
        bits >>= 1;
    }
    
    return count;
}

/* This function return the number of the off bits */
size_t BArrCountOff(bitsarr_t bits)
{
    return BArrCountOn(~bits);
}

/* This function sets specific bit to 1 */
bitsarr_t BArrSetOn(bitsarr_t bits, int position)
{
    return (bits |= (MASK1 << (position-1)));
}

/* This function sets specific bit to 0 */
bitsarr_t BArrSetOff(bitsarr_t bits, int position)
{
    return (bits &= ~(MASK1 << (position-1)));
}

/* This function sets specific bit to the given status */
bitsarr_t BArrSetBit(bitsarr_t bits, int position, int status)
{
    if (status)
    {
        return BArrSetOn(bits,position);
    }
    return BArrSetOff(bits,position);
}

/* This function flips specific bit */
bitsarr_t BArrFlipBit(bitsarr_t bits, int position)
{
    return (bits ^= (MASK1 << (position-1)));
}

/* This function rotate the array to right n times */
bitsarr_t BArrRotateRight(bitsarr_t bits, int num_of_rotations)
{        
    return ((bits >> num_of_rotations) | (bits << (SYSTEM_BITS - num_of_rotations)));
}

/* This function rotate the array to left n times */
bitsarr_t BArrRotateLeft(bitsarr_t bits, int num_of_rotations)
{
    return ((bits << num_of_rotations) | (bits >> (SYSTEM_BITS - num_of_rotations)));
}

/* This function return a string presentation of given bits array */
char* BArrToString(bitsarr_t bits, char* buffer)
{
    char* runner = NULL;
    int i = 0;
    
    assert (NULL != buffer);
    
    runner = buffer + SYSTEM_BITS;
    
    *runner = '\0';
    --runner;
    
    for (; i < SYSTEM_BITS ; ++i)
    {
        if (bits & MASK1)
        {
            *runner = '1';
        }
        else
        {
            *runner = '0';
        }
        bits >>= 1;
        --runner;
    }
    
    return buffer;
}

/* This function mirroring a given bits array using Hamming Weight*/
size_t BArrMirror(bitsarr_t bits)
{
    bits = (((bits & ~M1) >> 1) | ((bits & M1) << 1));
    bits = (((bits & ~M2) >> 2) | ((bits & M2) << 2));
    bits = (((bits & ~M4) >> 4) | ((bits & M4) << 4));
    bits = (((bits & ~M8) >> 8) | ((bits & M8) << 8));
    bits = (((bits & ~M16) >> 16) | ((bits & M16) << 16));
    return ((bits >> HALF_SYSTEM_BITS) | (bits << HALF_SYSTEM_BITS));
}


