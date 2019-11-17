/*******************************************************************************
				-Ws5
				-Itai Marienberg
				-Mon 13 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/

#ifndef __BIT_H__
#define __BIT_H__

#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 5

long Pow2(unsigned int x, unsigned int y);
int IsPow2(unsigned int n);
int IsPow2NoLoop(unsigned int n);
int Add1(int n);
int addOne(int x);
void ThreeBits(unsigned int arr[]);
unsigned int reverseBits(unsigned int num);
unsigned int SecAndSix(unsigned int n);
unsigned int SecOrSix(unsigned int n);
unsigned int SwapBit(unsigned int n);
int SmallestDev(unsigned int n);
int SwapVar(int *x, int *y);
int SetBit(int n);
int SetBitNoLoop(int n);

#endif
