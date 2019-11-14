/*******************************************************************************
				-Ws5
				-Itai Marienberg
				-Mon 13 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/
enum STATUS{SUCC, FAIL, FAIL_OPEN,FAIL_REMOVE, EXIT};

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"
#define STR_CH 5
#define N 100
/*  struct *******************************************************************/
void Structs(general gen_arr[])
{
    gen_arr[0].str = "-exit\n";
    gen_arr[0].p_cmp = &Compare;
    gen_arr[0].p_opr = &ExitProg;

    gen_arr[1].str = "-remove\n";
    gen_arr[1].p_cmp = &Compare;
    gen_arr[1].p_opr = &RemoveFile;

    gen_arr[2].str = "-count\n";
    gen_arr[2].p_cmp = &Compare;
    gen_arr[2].p_opr = &CountLines;

    gen_arr[3].str = "<";
    gen_arr[3].p_cmp = &CharCompare;
    gen_arr[3].p_opr = &AddStringTop;

	gen_arr[4].str = "this string always match";
    gen_arr[4].p_cmp = &Compare_always;
    gen_arr[4].p_opr = &AddString;
}
/*  Compare return 0 if equel ************************************************/
int Compare(const char *s1, const char *s2)
{
	assert (NULL != s1);
	assert (NULL != s2);	
	return (strcmp(s1, s2));
}
/*  Compare char return 0 if equel ************************************************/
int CharCompare(const char *s1, const char *s2)
{
	assert (NULL != s1);
	assert (NULL != s2);

	if(*s1 == *s2)
	{
	return 0;
	}
 	return 1;	
}
/*  Compare to new string ****************************************************/
int Compare_always(const char *s1, const char *s2)
{
	assert (NULL != s1);
	assert (NULL != s2);
	return 0;
}
/*  RemoveFile ***************************************************************/
enum STATUS RemoveFile(const char *file_name, char *str)
{
	UNUSED(str);
	
	if ( 0 == remove(file_name))
    {
         printf("Deleted successfully\n");
         return SUCC;
    }
	else
    {
         printf("Unable to delete the file\n");
         return FAIL_REMOVE;
    }
}
/***EXIT File ****************************************************************/
enum STATUS ExitProg(const char *file_name, char *str)
{
	UNUSED(file_name);
	UNUSED(str);
	printf("Exiting program\n");
	return EXIT;
}
/***COUNT ********************************************************************/
enum STATUS CountLines(const char *file_name, char *str) 
{
    FILE *fp; 
    int count = 0;  /* Line counter  */ 
    char c = 0;  
 	UNUSED(str);
    fp = fopen(file_name, "r"); 
  
    if (NULL == fp) 
    { 
    	printf("Could not open file %s", file_name); 
        return FAIL_OPEN; 
    } 
    /* Extract characters from file and store in character c*/ 
	for (c = getc(fp); c != EOF; c = getc(fp)) 
    {
        if (c == '\n')
        { 
        	count = count + 1; 
        }
     
    } 
    printf("%d\n",count);
    fclose(fp);   
    return SUCC; 
} 	
/***add to file ***************************************************************/
enum STATUS AddString(const char *file_name, char *user_str)
{  
    FILE *f_ptr;
    f_ptr = fopen(file_name, "a");

    if( NULL == f_ptr )
    {
    	printf("ERROR");
        return FAIL_OPEN;
    }
 	fputs(user_str, f_ptr);
	fclose(f_ptr);
   	return SUCC;
} 
/***add to file ***************************************************************/
enum STATUS AddStringTop(const char *file_name, char *user_str)
{ 
	char ch = 0;
    FILE *fp;
    FILE *tmp_cpy;
    fp = fopen(file_name, "r");
	tmp_cpy = fopen("tmp.txt", "a");
	
    if( NULL == fp || NULL == tmp_cpy )
    {
    	printf("ERROR");
        return FAIL_OPEN;
 	}
    fputs((user_str + 1 ), tmp_cpy); 
    ch = fgetc(fp);
    
    while (ch != EOF)
    {
    	fputc(ch, tmp_cpy);
    	ch = fgetc(fp);	
    }	
 		    
	fclose(tmp_cpy);
	fclose(fp);
	
	tmp_cpy = fopen("tmp.txt", "r");
	fp = fopen(file_name, "w");
	ch = fgetc(tmp_cpy);
	
	while (ch != EOF)
    {
    	fputc(ch, fp);
    	ch = fgetc(tmp_cpy)	;
    }	
    
    fclose(tmp_cpy);
	fclose(fp);
	remove("tmp.txt");
	return SUCC;
} 
/***start program  ************************************************************/
int StartProg (const char *file_name, general gen_arr[])
{
	char input[N];
	int i = 0;
	int status = 0;
	
	while(EXIT != status)
	{  
		printf("Please enter your string: \n");
		fgets(input, N, stdin);
		
		for( i = 0 ; i < STR_CH ; ++i)
		{
			status = gen_arr[i].p_cmp(gen_arr[i].str, input);
			if( SUCC == status)
			{
				status = gen_arr[i].p_opr(file_name, input);
				break; 
			}
		}
			
	}	
	return 0;	       		
}





