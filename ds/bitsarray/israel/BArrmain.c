/************************************************
*
* File: BArrMain.c
* Ex: Bits Array
* writer: Israel Drayfus
* Description: Run and test the functions of bits array library.
*
*************************************************/

#include <stdlib.h> /* malloc() */
#include <assert.h> /* assert() */

#include "bitsarray.h" /* bitsarray header */

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define WHITE "\033[0m"

#define TEST(test, errMsg) if (test)\
						   {\
						      printf(GREEN);\
						      printf("%s\n", "SUCCESS");\
						   }\
						   else\
						   {\
						      printf(RED);\
						      printf("%s, %s\n", "FAILURE", errMsg);\
						   }\
						   printf(WHITE);

#define BITS_IN_WORD 64

#define M1 (size_t) 0x5555555555555555
#define M2 (size_t) 0x3333333333333333
#define M4 (size_t) 0x0F0F0F0F0F0F0F0F
#define M8 (size_t) 0x00FF00FF00FF00FF
#define M16 (size_t) 0x0000FFFF0000FFFF
#define M32 (size_t) 0x00000000FFFFFFFF

#define MASK 1
#define M4_BITS "0000111100001111000011110000111100001111000011110000111100001111"
#define M4_COMPLEMENT_BITS "1111000011110000111100001111000011110000111100001111000011110000"

static int TestSetAll()
{
	return !(BArrSetAllBits(M1) ^ ~0);
}

static int TestResetAll()
{
	return !(BArrResetAllBits(M1) ^ 0);
}

static int TestIsOnTrue()
{
	return BArrIsOn(M1, 3);
}

static int TestIsOnFalse()
{
	return !(BArrIsOn(M1, 2));
}

static int TestIsOffTrue()
{
	return BArrIsOff(M1, 2);
}

static int TestIsOffFalse()
{
	return !(BArrIsOff(M1, 3));
}

static int TestCountOn()
{
	return (31 == BArrCountOn(M1 - 1));
}

static int TestCountOff()
{
	return (33 == BArrCountOff(M1 - 1));
}

static int TestSetBitOn()
{
	return (M1 + 2 == BArrSetBit(M1, 2, 1));
}

static int TestSetBitOff()
{
	return (M1 - 4 == BArrSetBit(M1, 3, 0));
}

static int TestSetOn()
{
	return (M1 + 2 == BArrSetOn(M1, 2));
}

static int TestSetOff()
{
	return (M1 - 1 == BArrSetOff(M1, 1));
}

static int TestRotateLeft1()
{
	return (~M1 == BArrRotateLeft(M1, 1));
}

static int TestRotateLeft2()
{
	return (M1 == BArrRotateLeft(M1, 4));
}
	
static int TestRotateRight1()
{
	return (~M1 == BArrRotateLeft(M1, 1));
}

static int TestRotateRight2()
{
	return (M1 == BArrRotateLeft(M1, 4));
}

static void TestToString1()
{
	char *buffer = (char *) malloc(BITS_IN_WORD + 1);
	
	printf("BArrToString() test:\n");
	printf("manual print:   ");
	printf(M4_BITS);
	printf("\n");
	printf("function print: %s\n", BArrToString(M4, buffer));
	
	free(buffer);
}

static void TestToString2()
{
	char *buffer = (char *) malloc(BITS_IN_WORD + 1);
	
	printf("\nmanual print:   ");
	printf(M4_COMPLEMENT_BITS);
	printf("\n");
	printf("function print: %s\n", BArrToString(~M4, buffer));
	
	free(buffer);
}

static int TestFlipBit1()
{
	return (M1 - 4 == BArrFlipBit(M1, 3));
}

static int TestFlipBit2()
{
	return (M1 + 2 == BArrFlipBit(M1, 2));
}

static int TestMirror1()
{
	return (~M1 == BArrMirror(M1));
}

static int TestMirror2()
{
	return (M1 == BArrMirror(~M1));
}

static int TestMirror3()
{
	return (~M32 == BArrMirror(M32));
}

static int TestMirror4()
{
	return ((bitsarr_t) ~0) == BArrMirror((bitsarr_t) ~0);
}

int main()
{
	TEST(TestSetAll(), "BArrSetAllBits() test failed");
	TEST(TestResetAll(), "BArrResetAllBits() test failed");
	TEST(TestIsOnTrue(), "BArrIsOn() test of true condition failed");
	TEST(TestIsOnFalse(), "BArrIsOn() test of false condition failed");
	TEST(TestIsOffTrue(), "BArrIsOff() test of true condition failed");
	TEST(TestIsOffFalse(), "BArrIsOff() test of false condition failed");
	TEST(TestCountOn(), "BArrCountOn() test failed");
	TEST(TestCountOff(), "BArrCountOff() test failed");
	TEST(TestSetBitOn(), "BArrSetBit() test of set 1 failed");
	TEST(TestSetBitOff(), "BArrSetBit() test of set 0 failed");
	TEST(TestSetOn(), "BArrSetOn() test failed");
	TEST(TestSetOff(), "BArrSetOff() test failed");
	TEST(TestRotateLeft1(), "BArrRotateLeft() test of one rotation failed");
	TEST(TestRotateLeft2(), "BArrRotateLeft() test of number rotations failed");
	TEST(TestRotateRight1(), "BArrRotateRight() test of one rotation failed");
	TEST(TestRotateRight2(), "BArrRotateRight() test of number rotations failed");
	TestToString1();
	TestToString2();
	TEST(TestFlipBit1(), "BArrFlipBit() test 1 to 0 failed");
	TEST(TestFlipBit2(), "BArrFlipBit() test 0 to 1 failed");
	TEST(TestMirror1(), "BArrMirror() test1 failed");
	TEST(TestMirror2(), "BArrMirror() test2 failed");
	TEST(TestMirror3(), "BArrMirror() test3 failed");
	TEST(TestMirror4(), "BArrMirror() test4 failed");
	
	return 0;
}










