/*********************************/
/*                               */
/*    Author :Itai Marienberg    */
/*    Reviewed By:               */
/*					             */
/*********************************/

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <stack.h>

#define SIZE_OF_FIB 51

int F[SIZE_OF_FIB];

struct Stack
{
    void *start;
    void *current;
    void *end;
    size_t element_size; 
}; 

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

/*char *RecStrstr(char *haystack, char *needle)
{

	if( 0 == strncmp(haystack,needle,3))
	{
		return haystack;
	}

	return RecStrstr(haystack + 1, needle + 1);
}*/

void RecSortStack(stack_t *stack)
{
	void *holder = StackPeek(stack);
	void *tmp = NULL;
	
	StackPop(stack);
	
	if (1 == StackSize(stack))
	{
		if (*(int*)holder < *(int*)StackPeek(stack))
		{
			tmp = StackPeek(stack);
			StackPop(stack);
			StackPush(stack, holder);
			StackPush(stack, tmp);	
		}
		
		else 
		{
			StackPush(stack, holder); 
		}
		
		return;
	}
	
	RecSortStack(stack);
	
	if (*(int*)holder < *(int*)StackPeek(stack))
	{
		tmp = StackPeek(stack);
		StackPop(stack);
		StackPush(stack, holder); 
		RecSortStack(stack);
		StackPush(stack, holder); 
	}
	
	else
	{
		StackPush(stack, holder); 
	}
	
	return;
	
				
}


int main()
{	
	int i = 0;
	char dst[] = "helloword";
	char src[] = "itai";
	char dst1[50] = "helloword";
	char src1[5] = "itai";
	char haystack[10] = "123456789";
	char needle[10] = "456";
	int x = 12, y = 7, z = 50, w = 3;
	
    stack_t *stack1 = StackCreate(4, 8);
    stack_t *stack2 = StackCreate(4, 8);
    StackPush(stack1, &x);
    StackPush(stack1, &y);
    StackPush(stack1, &z);
    StackPush(stack1, &w);
    
    RecSortStack(stack1);
	
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

	printf("src = helloword, dst = itai \n");
	printf("result is: %s \n", RecStrcat(dst1, src1));
	
	printf("\n\nThis is RecStrstr test: \n\n");

	/*printf("haystack 123456789 needle 456 \n");
	printf("result is: %s \n", RecStrstr(haystack, needle));*/

	return 0;
}
