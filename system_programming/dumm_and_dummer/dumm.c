
#include <stdio.h>

int main()
{
	int a = 200;
	void *ptr = &a;

	FILE *pa = fopen("first.txt", "w");;
	
	if(NULL == pa)
	{
		return 1;
	}
	
	fprintf(pa, "%p\n",ptr);
	fclose(pa);

	return 0;
}
