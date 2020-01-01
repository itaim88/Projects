#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitsarray.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define M0 (size_t) 0x0000000000000000
#define M1 (size_t) 0x5555555555555555
#define M2 (size_t) 0x3333333333333333
#define M4 (size_t) 0x0f0f0f0f0f0f0f0f
#define M8 (size_t) 0x00ff00ff00ff00ff
#define M16 (size_t) 0x0000ffff0000ffff
#define M32 (size_t) 0x00000000ffffffff
#define M64 (size_t) 0xffffffffffffffff
#define MASK1 (size_t) 0x0000000000000000001

#define RUN_TEST(test,mssg)\
            if (test)\
            {\
                printf(GREEN "SUCCESS: %s\n",mssg);\
            }\
            else\
            {\
                printf(RED "FAIL: %s\n",mssg);\
            }\

static void TestBArrSetAllBits()
{
    RUN_TEST((BArrSetAllBits(M0) == M64), "set all - 0");
    RUN_TEST((BArrSetAllBits(~M4) == M64), "set all")
}

static void TestBArrResetAllBits()
{
    RUN_TEST((BArrResetAllBits(M1) == M0), "reset all");
    RUN_TEST((BArrResetAllBits(M64) == M0), "reset all - 0xffffffffffffffff");
    RUN_TEST((BArrResetAllBits(M0) == 0), "reset all - 0x0000000000000000");
}   

static void TestBArrIsOn()
{
    RUN_TEST((BArrIsOn(M0,2) == 0), "second bit in M0 is not on");  
    RUN_TEST((BArrIsOn(123456789,5) == 1), "5th bit in 123456789 is on");
    RUN_TEST((BArrIsOn(M64,64) == 1), "bit 64 in M64 is on");         
}    

static void TestBArrIsOff()
{
    RUN_TEST((BArrIsOff(0,2) == 1), "second bit in 0 is off");  
    RUN_TEST((BArrIsOff(123456789,5) == 0), "5th bit in 123456789 is not on");
    RUN_TEST((BArrIsOn(M64,64) == 1), "bit 64 in M64 is not on");
    RUN_TEST((BArrIsOn(M2,1) == 1), "bit 1 in M2 is off");       
}   

static void TestBArrCountOn()
{
    RUN_TEST((BArrCountOn(M64) == 64), "64 set bits in M64");  
    RUN_TEST((BArrCountOn(MASK1) == 1), "1 set bits in MASK1");
    RUN_TEST((BArrCountOn(M0) == 0), "0 set bits in M0");         
}

static void TestBArrCountOff()
{ 
    RUN_TEST((BArrCountOff(M32) == 32), "32 bits off in M32");
    RUN_TEST((BArrCountOff(M64) == 0), "0 bits off in M64");          
}
  
static void TestBArrSetOn()
{
    RUN_TEST((BArrSetOn(123456789,2) == 123456791), "SetOn");
    RUN_TEST((BArrSetOn(M0,1) == MASK1), "SetOn");
    RUN_TEST((BArrSetOn(M32,2) == M32), "SetOn");           
}
    
static void TestBArrSetOff()
{
    RUN_TEST((BArrSetOff(123456789,3) == 123456785), "SetOff");
    RUN_TEST((BArrSetOff(MASK1,1) == M0), "SetOff");          
}

static void TestBArrSetBit()
{
    RUN_TEST((BArrSetBit(MASK1,1,0) == M0), "SetBit");  
    RUN_TEST((BArrSetBit(M32,3,1) == M32), "SetBit");
    RUN_TEST((BArrSetBit(123456789,3,0) == 123456785), "SetBit");          
}   

static void TestBArrFlipBit()
{
    RUN_TEST((BArrFlipBit(3,2) == 1), "flip");  
    RUN_TEST((BArrFlipBit(123456785,3) == 123456789), "flip");
    RUN_TEST((BArrFlipBit(MASK1,1) == M0), "flip");          
}   

static void TestBArrRotateRight()
{  
    RUN_TEST((BArrRotateRight(0,3) == 0), "RotateRight");
    RUN_TEST((BArrRotateRight(0,3) == 0), "RotateRight");          
}   

static void TestBArrRotateLeft()
{  
    RUN_TEST((BArrRotateLeft(0,0) == 0), "RotateLeft");         
} 
/*
static void TestBArrToString()
{
    char* buffer = (char*)malloc(65);
    RUN_TEST((strcmp(BArrToString(4611686018427387904,buffer),"0100000000000000000000000000000000000000000000000000000000000000") == 0),"tostring");
    free(buffer);          
} 
*/
static void TestBArrMirror()
{
    RUN_TEST((BArrMirror(~M0) == ~0), "mirrorr");
    RUN_TEST((BArrMirror(M8) == ~M8), "mirrorr");  
} 

int main()
{
    TestBArrSetAllBits();
    TestBArrResetAllBits();
    TestBArrIsOn();
    TestBArrIsOff();
    TestBArrCountOn();
    TestBArrCountOff();
    TestBArrSetOn();
    TestBArrSetOff();
    TestBArrSetBit();
    TestBArrFlipBit();
    TestBArrRotateRight();
    TestBArrRotateLeft();
/*    TestBArrToString();*/
    TestBArrMirror();
    
    return 0;
}
