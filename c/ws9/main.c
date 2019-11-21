/*******************************************************************************
-Ws9
-Itai Marienberg
-Mon 20 Nov 2019 14:50:59    
 -Reviewer:
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define WORD 8
#define BYTE 8

size_t ChunksOfWords (char c)
{
	size_t word_maker = c;
	int i = 0;
	
	for ( ; WORD > i ; ++i)
	{
		word_maker <<= BYTE;
		word_maker |= c;		
	}
	
	return word_maker;
}
 void *Mymemset(void *str, int c, size_t n)
{
	size_t address = (size_t) str;
	char *runner = (char *)str;
	size_t word_maker = 0;
	
	assert(NULL != str);
	
	while ( 0 != (address % WORD))
	{
		*runner = (char)c;
		++runner;
		--n;			 		
	}
	
	word_maker = ChunksOfWords((char)c);
	
	while (WORD <= n)
	{
		*(size_t*)runner = word_maker; 
		n -= WORD;
		runner += WORD;			 		
	}
	
		while (0 < n)
	{
		*runner = (char)c;
		++runner;
		--n;			 		
	}
	
	return str;	
}


int main()
{
	char str[50] = "this is my string";
	int c = '$';
	size_t n = 3;
				
	Mymemset(str,c,n);
	puts(str);
	
	return 0;
}
