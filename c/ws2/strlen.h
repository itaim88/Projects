/****************************************
				-ws2
				-Itai Marienberg
				-Sun 03 Nov 2019 17:04:07 IST
 				-reviewer:
*****************************************/


/* Exercise 1 this function calculate the length of a string without the '\0' */

#include <stdio.h>
#include <assert.h>

	size_t strlen(const char *str)
  {
  
	assert( NULL != str);
	const char *runner = str;

	while ('\0' != *runner)
		{
			++runner;
		}


	return (runner - str);
  }


/* Exercise 2 this function */




