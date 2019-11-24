/*******************************************************************************
-Ws9
-Itai Marienberg
-Mon 24 Nov 2019 14:50:59    
 -Reviewer: Yonatan
*******************************************************************************/
#include "word.h"

size_t CharOfWord(char c)
{
	size_t char_word_maker = c;
	int i = 0;

	for ( ; (WORD - 1) > i ; ++i)
	{
		char_word_maker <<= BYTE;
		char_word_maker |= c;
	}

	return char_word_maker;
}
/***************************************************************************/

 size_t StringOfWord(char *src)
{
    int i = 0;
	size_t string_word_maker = *(src + BYTE - 1);
    char *runner = (src + BYTE - 1);

	for ( ; (WORD - 1) > i ; ++i)
	{
        string_word_maker <<= BYTE;
        string_word_maker |= *(runner-1);
        --runner;
	}

	return string_word_maker;
}
/*********Mymemset************************************************************/

 void *Mymemset(void *str, int c, size_t n)
{
	size_t address = (size_t) str;
	char *runner = (char *)str;
	size_t word_block = 0;

	assert(NULL != str);

	while ((0 != (address % WORD))&& ( 0 < n))
	{
		*runner = (char)c;
		++runner;
		--n;
	}

	while (WORD <= n)
	{
		word_block = CharOfWord((char)c);
		*(size_t*)runner = word_block;
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

/**********Mymemcpy******************************************************/
void *Mymemcpy(void *destanation, const void *source, size_t n)
{
    size_t destanation_address = (size_t) destanation;
    char *destanation_runner = (char *) destanation;
    char *source_runner = (char *) source;
    size_t str_word = 0;

    assert(NULL != destanation);
    assert(NULL != source);

    while ((0 != (destanation_address % WORD)) && ( 0 < n))
    {
        *destanation_runner = *source_runner;
        ++destanation_runner;
        ++source_runner;
        --n;
    }


    while (WORD <= n)
    {
    	str_word = StringOfWord(source_runner);
        *(size_t*)destanation_runner = str_word;
        n -= WORD;
		destanation_runner += WORD;
		source_runner += WORD;
    }

    while (0 < n)
    {
        *destanation_runner = *source_runner;
        ++destanation_runner;
        ++source_runner;
        --n;
    }
    return destanation;
}
/*********Mymemmove********************************************************/
void *Mymemmove(void *destanation, const void *source, size_t n)
{
    char *runner_dest = (char *) destanation;
    char *runner_src = (char *) source;
    
    assert(NULL != destanation);
    assert(NULL != source);
    
    if ((size_t)runner_dest < (n + (size_t)runner_src)) 
    {
    	runner_dest += n - 1;
		runner_src += n - 1 ;
    	while ( 0 < n)
    	{
		
		*runner_dest =  *runner_src;
		--runner_dest;
		--runner_src;
		--n;
		}
	}
    
	else
    {
    	Mymemcpy(destanation, source, n);
    }

  return destanation;
}


/*******atoi *****************************************************************/
int Myatoi(const char *str)
{
    const char *runner = str;
    int string_to_number = 0;
    int  negitive = 1;
    
    if (*runner ==  '-')
    {
        negitive = -1;
        ++runner;
    }

    while ('\0' != *runner) 
    { 
        string_to_number = (*runner - '0') + (10 * string_to_number);
        ++runner;
    }
    return (negitive * string_to_number);
}

/*******atoi evry BASE ********************************************************/

int AtoiAscii(char c) 
{ 
    if ('0' <= c && '9' >= c) 
    {
        return ((int)c - '0'); 
    }
    else
    {
        return ((int)c - 'A' + 10);
    } 
} 

int MyatoiBase(char *str, int base) 
{ 
    int len = strlen(str); 
    int power = 1; 
    int num = 0;   
    int i = 0; 
  
    for (i = (len - 1); 0 <= i; --i) 
    { 
        if (AtoiAscii(str[i]) >= base) 
        { 
        	printf("Invalid Number\n"); 
            return -1; 
        } 
  
    	num += AtoiAscii(str[i]) * power; 
        power *= base; 
    } 
  
    return num; 
} 
/*********Myitoa************************************************************/
char* Myitoa(int i,char buffer[],int base)
{
    int shifter = i;
    char *runner = buffer;
    int right_digit = 0;
    
    if(0 > i)
    {
        *runner = '-';
        ++runner;
        i *= -1;
        shifter = i;
    }
    
    do
    { 
        ++runner;
        shifter /= base;
    }while(0 != shifter);

    *runner = '\0';

    do
    { 
        right_digit = i % base;
        *(--runner) = DIGIT[right_digit];
        i /= base;
    }while(0 != i);

    return buffer;
}

/********LittleOrBigEndian*****************************************************/   
int LittleOrBigEndian()
{
    unsigned int i = 1;
    char *c = (char*)(&i);
    if (1 == *c)
    {
      printf("Little endian\n");
    }
    else
    {
      printf("Big endian\n");
    }

    return 0;
}

/*****3 arrays*************************************************************/   

void TwoGoodToBeThree(char *a, char *b, char *c)
{
	char **abc = NULL;
	int i = 0;

	abc = (char**)calloc(3,1);
	
	for (i = 0; 3 > i; ++i)
	{
    	abc[i] = (char *)calloc(128, 1);
    	if (NULL == abc[i])
		{
			printf("Error - fail to allocate memory");
		}
	}

	while (('\0' != *a) || ('\0' != *b) || ('\0' != *c))
	{
		++abc[0][(int)*a];
		++abc[1][(int)*b];
		++abc[2][(int)*c];
		if ('\0' != *a)
		{
			++a;
		}
		if ('\0' != *b)
		{
			++b;
		}
		if ('\0' != *c)
		{
			++c;
		} 
	}

	for (i = 0 ; 128 > i ; ++i)
	{
		if ((abc[0][i]  > 0) && ((abc[1][i]) > 0) && ((abc[2][i] == 0)))
		{
			printf("%c\n",i);
		}
	}
	free(abc);
}





















