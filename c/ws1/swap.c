#include<stdio.h>

void Swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p   = *q;
	*q   = temp;	
}

void main ()
{
	int x, y;
	printf("Let`s swap two integers values\n");

	printf("Please enter the value of the first int: x\n");
	scanf("%d", &x);
	printf("the value of x is %d:\n",x);
	
	printf("\nPlease enter the value of the second int y:\n");
	scanf("%d", &y);
	printf("the value of y is: %d\n",y);
	
	Swap(&x, &y);

	printf("\nthe new value of x is %d:\n",x);
	printf("the new value of y is %d:\n",y);
	
}
