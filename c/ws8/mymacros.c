#include <stdio.h>

#define MAX2(a,b) ((a) > (b) ? (a) : (b))
#define MAX3(a,b,c) ((MAX2(a,b)) > (c) ? (MAX2(a,b)) : (c))
#define SIZEOF_VAR(x) (char *)(&x + 1) - (char *) (&x)	
			
int main()
{	
	int x = 4;
	char y = 2;
	printf("%d\n",MAX2(2, 3));
	printf("%d\n",MAX3(2, 3, 10));
	
	printf("%ld\n",SIZEOF_VAR(x));
	printf("%ld\n",SIZEOF_VAR(y));
	return 0;
}
