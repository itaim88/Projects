#include "mymem.h"
#define IS_LITTLE(x) ((0Xff & x) == x) ? printf("I am a Litle Endian!\n") : printf("I am a Big Endian!\n")
#define APROFIT 7
#define BYTE1 8
#define WORD1 8
#define UPTONINE 57
#define CASTOINT 48

/*******8 same char to 1 word*******/

size_t WordOfChar(char c)
{
	int i = 0;
	size_t wordofchar = c;

	for (i = 0; i < WORD1; ++i)
	{
		wordofchar <<= BYTE1;
		wordofchar |= c;
	}

	return wordofchar;
}

/*******8 char to 1 word*******/

size_t WordOfStr(const char *source)
{
	int i = 0;
	const char *runner = source;
	size_t wordofstr = *runner;

	runner += BYTE1;
	wordofstr = *runner;

	for (i = 0; i < WORD1; ++i)
	{
		wordofstr <<= BYTE1;
		--runner;
		wordofstr |= *runner;
	}

	return wordofstr;
}

/******* MyMemset*******/

void *MyMemset(void *str, int c, size_t n)
{
	char *runner = str;
	unsigned int count = n;
	size_t addres = (size_t)str;
	size_t char_set = 0;

	assert(NULL != str);
	
	printf("%p\n", runner);

	while (0 != addres % WORD1)
	{
		*runner = c;
		++runner;
		--count;	
	}

	printf("%p\n", runner);
	char_set = WordOfChar(c);

	while ((WORD1) < count)
	{
		*(size_t*)runner = char_set;
		count -= WORD1;
		runner += WORD1;
		printf("%p\n", runner);
	}

	while (0 != count)
	{
		*runner = c;
		++runner;
		--count;	
		printf("%p\n", runner);
	}

	return str;
}

/******* MyMemcpy*******/

void *MyMemcpy(void *dest, const void *source, size_t n)
{
	char *dest_runner = dest;
	const char *source_runner = source;
	unsigned int count = n;
	size_t addres = (size_t)dest;
	size_t str_set = 0;

	assert(NULL != source);
	assert(NULL != dest);
	
	printf("%p\n", dest_runner);

	while (0 != addres % WORD1)
	{
		*dest_runner = *source_runner;
		++dest_runner;
		++source_runner;
		--count;	
	}

	while ( 7 < count)
	{
		str_set = WordOfStr(source_runner);
		*(size_t*)dest_runner = str_set;
		count -= WORD1;
		dest_runner += WORD1;
		source_runner += WORD1;
	}

	while (0 != count)
	{
		*dest_runner = *source_runner;
		++dest_runner;
		++source_runner;
		--count;	
	}

	*dest_runner = '\0';

	return dest;
}

/*******MyMemMoveReverse*******/

void *MyMemMoveReverse(void *dest, const void *source, size_t n)
{
        char *dest_runner = dest;
        const char *source_runner = source;

        dest_runner += n-1;
        source_runner += n-1;

        while (0 < n)
        {
                *dest_runner = *source_runner;
                --dest_runner;
                --source_runner;
                --n;
        }

        return dest;
}

/*******MyMemMove*******/

void *MyMemMove(void *dest, const void *source, size_t n)
{
        char *dest_runner = dest;
        const char *source_runner = source;

        if (source >= dest)
        {
                MyMemcpy(dest_runner, source_runner, n);
        }
        else
        {
                MyMemMoveReverse(dest_runner, source_runner, n);
        }
        
        return dest;
}

/*******MyItoa*******/

void *MyItoa(const int value, char *str, int base)
{
	int temp_num = value;
	int temp_rest = 0;
	char *runner = str;
	char *s_runner = runner;
	char temp = 0;

	if (0 > value)
	{
		*runner = '-';
		++runner;
		++s_runner;
		temp_num *= -1;
	}

	while (0 != temp_num)
	{
		temp_rest = temp_num % base + CASTOINT;	
		temp_num = temp_num / base;

		if (UPTONINE < temp_rest)
		{
			temp_rest += APROFIT;
		}

		*runner = (char)(temp_rest);
		++runner;
		}

		*runner = '\0';
		--runner;

	while (s_runner < runner)
	{
		temp = *s_runner;
		*s_runner = *runner;
		*runner = temp;
		++s_runner;
		--runner;
	}

	return str;
}

/*******MyAtoi*******/

size_t MyAtoi(const char *str, int base)
{
	size_t number = 0;
	const char *runner = str;
	int temp_num = *runner;
	int negetiv = 1;

	if ( '-' == *runner)
	{
		negetiv = -1;
		++runner;
	}

	while ('\0' != *runner)
	{
		temp_num = *runner;
		if ( UPTONINE < *runner)
		{
			temp_num = *runner - APROFIT;
		}
		number = (number * base) + (temp_num) - CASTOINT;
		++runner;
	}

	return (number * negetiv);
}

/*******TowOrNathing*******/

void TowOrNathing(const char arr1[], const char arr2[], const char arr3[])
{
	const char *runner = arr1;
	char *temp_arr = (char*)calloc(20,sizeof(char));
	char *temp_runner = temp_arr;

	while ('\0' != *runner)
	{
		if ((strchr(arr2, *runner) != NULL) && (strchr(arr3, *runner) == NULL) && (strchr(temp_arr, *runner) == NULL))
		{
			*temp_runner = *runner;
			printf("%c\n",*temp_runner);
			++temp_runner;
		}
		++runner;
	}

	free(temp_arr);
}

/*******LittleOrBigEndian*******/

void LittleOrBigEndian()
{
	size_t num = 1;
	size_t *p = &num;
	
	if (1 == *(char*)p)
	{
		printf("I am a Litle Endian!\n");
	}
	else 
	{
		printf("I am a Big Endian!\n");
	}	
}
