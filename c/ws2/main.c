#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "mystrlen.h"

int main()
{
	/*
	printf("this is start of strlen\n");
	char a[] = "hello";
	printf("%ld\n", Mystrlen(a));
	printf("\n this is end of strlen\n"); 
	*/
	
	
	/* 
	char new[] = "Learn programming yourself";
	int b = 'p';
	char *result;

	printf("%s\n", result= Mystrchr(new, b)); 
	*/

	
	/* 
	char new1[] = "Learn";
	char *tmp = Mystrdup(new1); 
	printf("%s\n" , tmp);
	
	free(tmp); 
	*/

	
	char dest[50] = "hello";
	char src[] = "world1";
	Mystrcat(dest,src);
	
	printf("%s\n" , dest);
	
	
	/*char a[] = "ACBA";
	Ispolindrome(a); */

	return 0;

}
