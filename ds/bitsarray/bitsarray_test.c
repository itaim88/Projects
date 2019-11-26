/*******************************************************************************
-Ws1
-Itai Marienberg
-Mon 26 Nov 2019   
 -Reviewer: 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "bitsarray.h"

#define TOTAL_BITS 64
#define NRM "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define MSB 0x8000000000000000UL

#define RUN_TEST(test,err_msg){\
							if (test)\
							{\
								printf(GREEN"success\n");\
							}\
							else\
							{\
								printf(RED"FAIL: %s\n", err_msg);\
							}\
						}

void test_BArrSetAllBits()
{
	RUN_TEST((BArrSetAllBits(0) == ~0UL), "can't set on all the bits");	
	RUN_TEST((BArrSetAllBits(~0) == ~0UL), "can't set on all the bits");	
	RUN_TEST((BArrSetAllBits(528734) == ~0UL), "can't set on all the bits");	
}
void test_BArrResetAllBits()
{
	RUN_TEST((BArrResetAllBits(1) == 0UL),"Reset failed (1)");
	RUN_TEST((BArrResetAllBits(~0) == 0UL),"Reset failed (~0)");
	RUN_TEST((BArrResetAllBits(123) == 0UL),"Reset failed (123)");
}

void test_BArrSetOn()
{
	RUN_TEST((BArrSetOn(0,32) == 2147483648UL), "SetBitOn error");
	RUN_TEST((BArrSetOn(0,1) == 1ul), "SetBitOn error");
	RUN_TEST((BArrSetOn(0,2) == 2ul), "SetBitOn error");
}

void test_BArrIsOff()
{
	RUN_TEST((BArrIsOff(4,7) == 1UL),"IsOff 1 returns succ instead of fail");
	RUN_TEST((BArrIsOff(4,2) == 1UL),"IsOff 2 returns fail instead of succ");
	RUN_TEST((BArrIsOff(11,1) == 0UL),"IsOff 3 fails with normal input");
	RUN_TEST((BArrIsOff(10,2) == 0UL),"IsOff 4 fails with normal input");
	RUN_TEST((BArrIsOff(11,10) == 1UL),"IsOff 5 fails with normal input");
	RUN_TEST((BArrIsOff(10,10) == 1UL),"IsOff 6 fails with normal input");
}

void test_BArrIsOn()
{
	RUN_TEST((BArrIsOn(4,7) == 0),"IsOn 1 returns succ instead of fail");
	RUN_TEST((BArrIsOn(4,2) == 0),"IsOn 2 returns fail instead of succ");
	RUN_TEST((BArrIsOn(11,1) == 1),"IsOn 3 fails with normal input");
	RUN_TEST((BArrIsOn(10,2) == 1),"IsOn 4 fails with normal input");
	RUN_TEST((BArrIsOn(11,10) == 0),"IsOn 5 fails with normal input");
	RUN_TEST((BArrIsOn(10,10) == 0),"IsOn 6 fails with normal input");
}	

void test_BArrSetOff()
{
	RUN_TEST((BArrSetOff(2147483648,32) == 0UL), "SetBitOf 1 error");
	RUN_TEST((BArrSetOff(8,4) == 0UL), "Set 2 BitOf error");

}

void test_BArrCountOn()
{
	RUN_TEST((BArrCountOn(33) == 2UL), "Count return unebitspected value");
	RUN_TEST((BArrCountOn(~0) == 64UL), "Count return unebitspected value");
}

void test_BArrCountOff()
{
	RUN_TEST((BArrCountOff(33) == 62UL), "Count 1 return unebitspected value");
	RUN_TEST((BArrCountOff(~0) == 0UL), "Count 2 return unebitspected value");
}

void test_BArrRotateLeft()
{
	RUN_TEST((BArrRotateLeft(MSB,2) == 2UL), "MSB failes to move to the first bit place");
}

void test_BArrRotateRight()
{
	RUN_TEST((BArrRotateRight(1,1) == MSB), "1 failes to move to the MSB bit place");	
}

void test_BArrMirror()
{
	RUN_TEST((BArrMirror(MSB) == 1), "mirror fails to change msb place");
	RUN_TEST((BArrMirror(1) == MSB), "mirror fails to change 1st bit place");
	RUN_TEST((BArrMirror(~0) == ~0UL), "mirror fails bla bla");
}

void test_BArrSetBit()
{
	RUN_TEST((BArrSetBit(0,4,1) == 8), "SetBit error");
}

void test_BArrFlipBit()
{
	RUN_TEST((BArrFlipBit(3,2) == 1), "Flip error");
}



int main()
{
	char *string_buffer = (char *)calloc(TOTAL_BITS + 1, sizeof(char));
	test_BArrSetAllBits();
	test_BArrResetAllBits();	
	test_BArrSetOn();
	test_BArrIsOff();
	test_BArrIsOn();
	
	test_BArrSetOff();
	test_BArrCountOn();	
	test_BArrCountOff();
	test_BArrRotateLeft();
	test_BArrRotateRight();

	test_BArrMirror();
	test_BArrSetBit();	
	test_BArrFlipBit();
	test_BArrFlipBit();

	free(string_buffer);
	

	return 0;
}

						



