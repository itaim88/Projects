#include <stdio.h>

#define MAX2(a,b) ((a) > (b) ? (a) : (b))
#define MAX3(a,b,c) ((MAX2(a,b)) > (c) ? (MAX2(a,b)) : (c))
#define SIZEOF_VAR(x) (char *)(&x + 1) - (char *) (&x)	
#define SIZEOF_TYPE(type) (size_t) (1+(type*)0)

      			
int main()
{	
	int x = 4;
	char y = 2;
	
	printf("%d\n",MAX2(2,3));
	printf("%d\n",MAX3(2,3,10));
	printf("%ld\n",SIZEOF_VAR(x));
	printf("%ld\n",SIZEOF_VAR(y));
	printf("%lu\n",SIZEOF_TYPE(int));
	
	return 0;
}
