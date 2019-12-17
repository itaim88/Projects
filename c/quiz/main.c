#include <stdio.h>
#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"

void test(int result, const char *msg)
{
	if (1 == result)
	{
		printf(GREEN "SUCCSES \n" NRM);
	}
	else 
	{
		printf(RED "%s FAIL\n" NRM, msg);
	}	
}
int RotChek(const char *s1, const char *s2)
{
	 const char *runner = s2;
	
	/*while ( '\0' != runner)
	{
		if ()
		{
		
		}
		else ()
		{
		
		}			
	}*/
	return 0;
}
int main()
{
	const char s1[] = "123156";
	const char s2[] = "156123";
	int result = 0;
	
	test (RotChek("abc", "def") == 0, "simple fail");
	test (RotChek("abc", "bca") == 1, "simple true");
	
	return;
}
