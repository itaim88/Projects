/*******************************************************************************
-Ws9
-Itai Marienberg
-Mon 20 Nov 2019 14:50:59    
 -Reviewer:
*******************************************************************************/

#include "word.h"

int main()
{
	char str[50] = "this is my string";
	int c = '7';
	size_t n = 11;
	char destanation[50] = {"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"};
    char src[20] = {"123456789YES"};
    int base = 16;
    char deci[20] = "10";
    int i = 34510;
    char buffer[20] = "0";
    char test[20] = "AA";
    int a = 1;

	Mymemset(str,c,n);
	puts(str);
	
	Mymemcpy(destanation,src,12);
	puts(destanation);
	
	LittleOrBigEndian();
	
	printf("Myatoi %d\n",MyatoiBase(test,base));

  
    printf("int to string %s\n",Myitoa(i,buffer,base));
    

    IS_LITTLE_ENDIEN(a);
   
	return 0;
}
