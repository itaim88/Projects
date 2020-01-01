
#include <stdio.h>

int main()
{
	int a = 100;
	void *p;
	
	FILE *collecter = fopen("first.txt", "r");
	if (NULL != collecter)
	{
		fscanf(collecter, "%p", &p);
	}
	
	fclose(collecter);
		
    printf("%p \n", p);
	printf("%d \n", *(int*)p);
	

	

	
	return 0;
}
