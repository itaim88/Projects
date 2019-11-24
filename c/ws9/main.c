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
    char deci[20] = "10";
    int i = 34510;
    char buffer[20] = "0";
    char test[20] = "AB";
    int a = 1;
    
    /********/
    
	char *dest = (char *) malloc(sizeof(char)*100);
	char newsrc[] = "this is my string";
	strcpy(dest,newsrc);
	Mymemset(dest,c,n);
	puts(dest);
	free(dest);
	/*********/
	
	Mymemcpy(destanation,src,12);
	puts(destanation);
	
	LittleOrBigEndian();
	
	printf("Myatoi %d\n",MyatoiBase(test,base));

  
    printf("int to string %s\n",Myitoa(i,buffer,base));
    

    IS_LITTLE_ENDIEN(a);
   
	return 0;
}
