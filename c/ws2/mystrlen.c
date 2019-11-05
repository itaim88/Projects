/*******************************************************************************
				-Ws2
				-Itai Marienberg
				-Mon 04 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/


/* Exercise 1 this function calculate the length of a string without the '\0' */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "mystrlen.h"

	size_t Mystrlen(const char *str)
  {
  	const char *runner1 = str;
	
	/* Check if the address of str is NULL */
	assert( NULL != str);
	

	while ('\0' != *runner1)
		{
			++runner1;
		}


	return (((char *)runner1) - str);
  }


/* Exercise 2 this function compares two strings character by character */


  size_t Mystrcmp(const char *str1, const char *str2)
 {
	/* Check if the address of str is NULL */
	assert( NULL != str1);
	assert( NULL != str2);

	
	while ('\0' != *str1 && '\0' != *str2)
	{
			if ((*str1 - *str2)	!= 0)
				{
					return (*str1 - *str2);
				}
			else 
				{
					str1++;
					str2++;
				}
	
	}
	return (*str1 - *str2) ; 
 }

/* Exercise 3 this function copy one string into another */


  char *Mystrcpy(char *destination, const char *source)
 {
	char *ptr3 = destination;

	if (destination == NULL)
	return NULL;

	

	while ('\0' != *source )
		{
			*destination = *source;
			++destination;
			++source;
		}
		
			*destination = '\0';

	return ptr3;
 }

/* Exercise 4 this function copy one string into another */


char *Mystrncpy(char *dest, const char *src, size_t n)
{
	char *ptr4 = dest;

	if (dest == NULL)
	return NULL;

	

	while ('\0' != *src && n != 0 )
		{
			*dest = *src;
			++dest;
			++src;
		}
		
			*dest = '\0';

	return ptr4;
 }	


/* Exercise 5 this function compares two strings character by character
   without lower/upper case sensitivity */

  size_t Mystcasecmp(const char *string1, const char *string2)
 {
	
	int i = 0;
		
	const char *run1 = string1;
	const char *run2 = string2;
	    	
	while (tolower(*run1) == tolower(*run2) && '\0' != *run1)

	{
		++run1;
		++run2;
	}

	if(*run1 > *run2)

	    {
		i = 1;    
	    }
	   
	 else if(*run1 < *run2)

	    {
		i = -1;
	    }
	   
	  return (i);
}
	
/* Exercise 6 this function returns a pointer to the first occurrence of the
   character c in the string s */

  char *Mystrchr(const char *s, int c)
{
	const char *run = s;
	
	while ('\0' != *run)
		{
			if( 0 == (*run - c))
				{
				return (char *)run;
				}
			else
			{
				++run;
			}
		}

	return NULL;
}








