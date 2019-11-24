/*******************************************************************************
-Ws9
-Itai Marienberg
-Mon 20 Nov 2019 14:50:59    
 -Reviewer:
*******************************************************************************/

#include "word.h"


int main()
{
	
	int c = '7';
	size_t n = 11;
	char destanation[50] = {"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"};
    char src[20] = {"123456789YES"};
    int base = 16;
    int i = 34510;
    char buffer[20] = "0";
    char test[20] = "AB";
    int a = 1;
    char abc[50] = {"abcdef"};
    char *A = "98765{432";
	char *B = "987{6";
	char *C = "23";
 	char sorce[50] = "abcdef";
 	char *dest = sorce;
    
	char *dest_new = (char *) malloc(sizeof(char)*100);
	char newsrc[] = "this is my string";
	strcpy(dest_new,newsrc);
	Mymemset(dest_new,c,n);
	puts(dest_new);
	free(dest_new);
	
	
	Mymemcpy(destanation,src,12);
	puts(destanation);
	
	LittleOrBigEndian();
	
	printf("Myatoi %d\n",MyatoiBase(test,base));

  
    printf("int to string %s\n",Myitoa(i,buffer,base));
    
    Mymemmove((abc +2), abc, 4);
    puts(destanation);

    IS_LITTLE_ENDIEN(a); 
   

	
	
	dest = dest + 2;
	Mymemmove (dest, sorce, 3);
	puts (dest);
  

	TwoGoodToBeThree(A,B,C);
	
  return 0;
}

   

