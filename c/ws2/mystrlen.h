/*******************************************************************************
				-Ws2
				-Itai Marienberg
				-Mon 04 Nov 2019 08:42:33  
 				-Reviewer:
*******************************************************************************/


/* Exercise 1 this function calculate the length of a string without the '\0' */

#include <stdio.h>
#include <assert.h>

	size_t mystrlen(const char *str)
  {
  
	assert( NULL != str);
	const char *runner1 = str;

	while ('\0' != *runner1)
		{
			++runner1;
		}


	return (runner1 - str);
  }


/* Exercise 2 this function compares two strings character by character */


  size_t mystrcmp(const char *str1, const char *str2)
 {
	
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


  char *mystrcpy(char *destination, const char *source)
 {
	if (destination == NULL)
	return NULL;

	char *ptr3 = destination;

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


char *mystrncpy(char *dest, const char *src, size_t n)
{

	if (dest == NULL)
	return NULL;

	char *ptr4 = dest;

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


#include <ctype.h>

  size_t mystcasecmp(const char *string1, const char *string2)
 {
	
	assert( NULL != string1);
	assert( NULL != string2);
	int i = 0;
	const char *run1 = string1;
	const char *run2 = string2;

    while( '\0' != *run1 )
	{
      tolower(*run1);
	  ++run1;

	}
	
	while ('\0' != *string1 && '\0' != *string2)
	{
			if ((*string1 - *string2)	!= 0)
				{
					return (*string1 - *string2);
				}
			else 
				{
					string1++;
					string2++;
				}
	
	}
	return (*string1 - *string2) ; 
 }















}












