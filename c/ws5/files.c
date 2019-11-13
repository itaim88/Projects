/*******************************************************************************
				-Ws5
				-Itai Marienberg
				-Mon 11 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/
enum STATUS{SUCC, FAIL, EXIT};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

/*  struct *******************************************************************/

int Structs()
{
	struct general
    {
        char *str;
        int (*p_cmp)(const char *, const char *);
        enum STATUS(*p_opr)(const char *);
    }   gen_arr[4];

    gen_arr[0].str = "-exit";
    gen_arr[0].p_cmp =&Compare;
    gen_arr[0].p_opr =&ExitProg;

    gen_arr[1].str = "-remove";
    gen_arr[1].p_cmp =&Compare;
    gen_arr[1].p_opr =&RemoveFile;

    gen_arr[2].str = "-count";
    gen_arr[2].p_cmp =&Compare;
    gen_arr[2].p_opr =&CountLines;

    gen_arr[3].str = "add";
    gen_arr[3].p_cmp =&Compare;
    gen_arr[3].p_opr =&AddString;

 return 0;
}

/*  Compare return 0 if equel ************************************************/

int Compare(const char *, const char *)
{
	return (strcmp(const char *,const char *));
}

/*  RemoveFile ***************************************************************/

enum STATUS RemoveFile(const char *file_name)
{
	if ( 0 == remove(file_name))
    {
         printf("Deleted successfully\n");
         return SUCC;
    }

	else
    {
         printf("Unable to delete the file\n");
         return FAIL;
    }
}

/***EXIT File ****************************************************************/

enum STATUS ExitProg(const char *)
{
	printf("Exiting program\n");
    return EXIT;
}

/***COUNT ********************************************************************/

enum STATUS CountLines() 
{
    FILE *fp; 
    int count = 0;  /* Line counter (result) */
    char filename[MAX_FILE_NAME]; 
    char c;  /* To store a character read from file*/ 
  
    /* Get file name from user. The file should be 
     either in current folder or complete path should be provided*/ 
    printf("Enter file name: "); 
    scanf("%s", filename); 
  
    /* Open the file*/ 
    fp = fopen(filename, "r"); 
  
    /* Check if file exists*/ 
    if (fp == NULL) 
    { 
    	printf("Could not open file %s", filename); 
        return FAIL; 
    } 
  
    /* Extract characters from file and store in character c*/ 
	for (c = getc(fp); c != EOF; c = getc(fp)) 
    {
        if (c == '\n')
        { /* Increment count if this character is newline*/ 
        	count = count + 1; 
        }
    }
    /* Close the file*/ 
    fclose(fp); 
    printf("The file %s has %d lines\n ", filename, count); 
  
    return SUCC; 
} 
	
/***add to file ***************************************************************/

 "<"
enum STATUS AddString()
{
   
    print   
    FILE *fp;
    fp = fopen("try.txt", "a");
    char input[MAX_LINES];

    if( fp == NULL)
    {
    	printf("ERROR");
        return FAIL;
    }
	else if ( "<")
	{
			
			
		return SUCC;
	}
		
	else	
    {
    	printf("Enter a string to add to the file\n");
        gets(input)!= NULL;
        fputs(input, fp);
        fclose(fp);
    }
        
    return SUCC;

} 

/***start program  ************************************************************/
int StartProg ()
{
	while()
	{
	printf("Please enter one of the following commands or a string to add to\
	the file:\n");
	printf("\"-remove\" to delete an existing file\n");
	printf("\"-count\" to count the number of lines in existing file\n");
	printf("\"exit\" to close the program\n");
	printf("begin a string with \"<\" to add the string at the beginning of file\n"); 
	
		while()
		{
			
			return;
		}
	}	
	       		
}





מציג את FILES.txt.
