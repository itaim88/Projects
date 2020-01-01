
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

static int Sum(int num1, int num2)
{
	static int i = 0;
	float local_sum  = 2.3;

	++i;
	local_sum += i;

	return num2 + num1;
}

extern int TwoModuloCheck(int num1, int num2)
{
	static int j;
	const float x = 12.3;

	if ((0 == num1 % 2) && (0 == num2 % 2))
	{
		return 0;
	}

	++j; 
	j += x;

	return 1;
}

int global_out_main;
static var_out_main = 5;

int main()
{
	int global_1 = 10;
	static int var = 0;
	char global_2[] = "YesOrNo";

	void * heap_check_1 = NULL;
	int * heap_check_2 = NULL;

	heap_check_1 = (void *)malloc(sizeof(int) * 10);
	if (NULL == heap_check_1)
	{
		global_2[2] = 'X';
		return 1;
	}

	printf("Hello Word\n");
	heap_check_2 = (int *)malloc(sizeof(char) * 13);
	if (NULL == heap_check_2)
	{
		return 1;
	}

	var = TwoModuloCheck(global_out_main, var);
	global_1 = TwoModuloCheck(7, var) + var_out_main;

	free(heap_check_2); 
	heap_check_2 = NULL;
	free(heap_check_1); 
	heap_check_1 = NULL;

	return 0;
	
}