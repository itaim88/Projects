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
#include <stdlib.h>
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

	if (src == NULL)
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
	    	
	while ((tolower(*run1) == tolower(*run2)) && ('\0' != *run1) &&
		  ('\0' != *run2))

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

/* Exercise 7 this function returns a pointer to a null-terminated byte string,
   which is a duplicate f the string pointed to by s */

  char *Mystrdup(const char *s)
{
		
	 char *newtmp = (char *) malloc (sizeof(char) * strlen(s));
	 char *firstpos = newtmp;
		while ('\0' != *s)
				{
				*newtmp = *s;
				++newtmp;
				++s;
				}
		return (char *) firstpos;	 
}
    
/* Exercise 8 this function returns a pointer to a null-terminated byte string,
   which is a duplicate f the string pointed to by s */

  char *Mystrcat(char *dest, const char *src)
{
 	
	const char *runsrc = src;
	char *rundest = dest;
	 
	while ( '\0' != *rundest)
		{
			++rundest;
		}
	
	while ('\0' != *runsrc)
		{
			*rundest = *runsrc;
			++rundest;
			++runsrc;	
		}
	 
	return (char *) dest;
}
  
/* Exercise 9 this function appends the string pointed to by src to the end of
 the string pointed to by dest up to n characters long */

  /* char *Mystrncat(char *dest, const char *src, size_t n)
{
 	



} */


 /* Exercise - this function checks if a string is a palindrome */

 int Ispolindrome(const char *str)
{
	const char *start = str;
	const char *end = str;
	int length = strlen(str);
	int i = 0;
	
	end = (( length - 1 )+str); /* points to address of the last 
												character of srt */
	

	for ( i = 0; i < (length /2); ++i)
		{
			if ( *start == *end)
				{
					++start;
					--end;
				}
			else 
				{
					 printf("Not a polindrome\n");
					 return 0;
				}
		}
		
	printf("polindrome\n"); 
	return 0; 
}


 /* Exercise - this function plays 7 BOOM*/

void SevenBoom (int a, int z) 
{
	int i=0, temp= 0, flag =0, t2=0;

	for( i=a; i<=z; i++)
	{
		flag= 0;
		if (i % 7 == 0)
		{
			flag=1; 
		}
		if ((i / 10) > 0)
		{
			temp= i;
			while (0 < temp)
			{
				t2= temp %10;
				if( t2 % 10 == 7)
				{
					flag =1;
					break;
				}
				temp /= 10;
			}
		}	
		if (1 == flag)
		{
			printf("Boom ");
		}
		else
		{
			printf("%d ",i);
		}		
	}
}

 /* Exercise - SWAP 2 pointers to int*/

void Swap (int *a, int *z) 
{
	int temp = *a;
	*a = *z;
	*z = temp;
}


/* Exercise - white spaces deletion*/

void Whitespace(char *s)
{
    char *runner1 = s;
    char *runner2 = s;
    char *temp = s;
   
    while (isspace(*runner1))
    {
        ++runner1;
    }
   
    strcpy(runner2, runner1);
   
    runner1 = runner2;
    temp = runner2;
   
    while ('\0' != *runner1)
    {
        if(isspace(*runner1) && isspace(*(runner1 + 1)))
        {
            while (isspace(*runner1))
            {
                ++runner1;
            }
           
            strcpy(++runner2, runner1);
            runner1 = runner2;
        }    
       
        ++runner1;
        ++runner2;
    }
   
    printf("%s\n", temp);
     
}

























