/*********************************/
/*    Task                       */
/*    Author :Itai Marienberg   */
/*    Reviewed By: Yoav          */
/*    Date: 15/12/2019           */
/*********************************/

#include <stdio.h>
#include <assert.h>

#define SIZE_OF_FIB 51

int F[SIZE_OF_FIB];

size_t RecFib(int n)
{
	if (1 >= n)
	{
		return n;
	}

	if(F[n] != -1)
	{
		return F[n];
	}

	return F[n] = RecFib(n-1) + RecFib(n-2);
}     

size_t ItrFib(int n)
{
	int i = 0;
	size_t a[SIZE_OF_FIB] = {0};
	a[0] = 0;
	a[1] = 1;

	for (i = 0; i < n; ++i)
	{
		a[i+1] = a[i] + a[i-1];
	}

	return a[n];
}

size_t RecStrlen(const char *str)
{
	char *runner = NULL;

	assert(NULL != str);

	runner = (char *) str;

	if ('\0' == *runner)
	{
		return 0;
	}

	return (RecStrlen(runner + 1) + 1);	
}

int RecStrcmp(const char *str1, const char *str2)
{
	const char *runner1 = NULL;
	const char *runner2 = NULL;
	
	assert(NULL != str1);
	assert(NULL != str2);

	runner1 = str1;
	runner2 = str2;

	if (*runner1 != *runner2 || ('\0' == *runner1) || ('\0' == *runner2))
	{
		return *runner1 - *runner2;
	}

	return RecStrcmp(runner1 + 1,  runner2 + 1);;
}

char * RecStrcpy(char *dst, char *src)
{
	assert(NULL != dst);
	assert(NULL != src);

	if ('\0' == *src)
	{
		*dst = *src;
		return dst;
	}

	*dst = *src;

	RecStrcpy(dst + 1, src + 1);

	return dst;
}	

char * RecStrcat(char *dst, const char *src)
{
	char *dest_location = dst + RecStrlen(dst); 

	if ('\0' == *src)
	{
		return dst;	
	}	

	*dest_location = *(char *)src;
	return (RecStrcat(dst, src + 1));
}

int main()
{	
	int i = 0;
	char dst[] = "helloword";
	char src[] = "itai";
	char dst1[50] = "helloword";
	char src1[5] = "itai";

	printf("This is rec Fib test: \n\n");

	for (i = 0; i < SIZE_OF_FIB; ++i)
	{
		F[i] = -1;
	}
	printf("fib(10) value is %lu \n", RecFib(10));
	printf("fib(20) value is %lu \n", RecFib(20));
	printf("fib(30) value is %lu \n", RecFib(30));
	printf("fib(40) value is %lu \n", RecFib(40));
	printf("fib(50) value is %lu \n", RecFib(50));

	printf("\n\nThis is itr Fib test: \n\n");

	printf("fib(10) value is %lu \n", RecFib(10));
	printf("fib(20) value is %lu \n", RecFib(20));
	printf("fib(30) value is %lu \n", RecFib(30));
	printf("fib(40) value is %lu \n", RecFib(40));
	printf("fib(50) value is %lu \n", RecFib(50));

	printf("\n\nThis is Recstrlen test: \n\n");

	printf("hello length is %lu \n", RecStrlen("hello"));
	printf("helloword length is %lu \n", RecStrlen("helloword"));

	printf("\n\nThis is RecStrcmp test: \n\n");

	printf("hello, hello same %d \n", RecStrcmp("hello","hello"));
	printf("helloword, hello not same %d \n", RecStrcmp("heword", "hello"));

	printf("\n\nThis is RecStrcpy test: \n\n");

	printf("itai == %s \n", RecStrcpy(dst, src));

	printf("\n\nThis is RecStrcat test: \n\n");

	printf("itai == %s \n", RecStrcat(dst1, src1));
	

	return 0;
}
