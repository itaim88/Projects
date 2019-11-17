/*******************************************************************************
				-Ws6
				-Itai Marienberg
				-Mon 17 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/
#ifndef __BIT_H__
#define __BIT_H__

#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 5
#define BYTE 8
#define SEC 2
#define SIX 6
#define FIVE_BIT 5
#define THIRD_BIT 3
#define ZERO_INDEX 15

typedef union 
{ 

    float f; 
    struct
    {  
        unsigned int mantissa : 23; 
        unsigned int exponent : 8; 
        unsigned int sign : 1; 
  
    } raw;

} myfloat; 

long Pow2(unsigned int x, unsigned int y);
int IsPow2(unsigned int n);
int IsPow2NoLoop(unsigned int n);
int Add1(unsigned int n);
int addOne(unsigned int x);
void ThreeBits(unsigned int arr[]);
unsigned int reverseBits(unsigned int num);
unsigned int reverseBitsNoLoop(unsigned int num);
unsigned int SecAndSix(unsigned int n);
unsigned int SecOrSix(unsigned int n);
unsigned int SwapBit(unsigned int n);
int SmallestDev(unsigned int n);
int SwapVar(int *x, int *y);
int SetBit(unsigned int n);
int SetBitNoLoop(unsigned int n);
int numberOfSetBits(unsigned int i);
int MynumberOfSetBits(uint64_t x);
void printBinary(int n, int i);
void printIEEE(myfloat var);

#endif
