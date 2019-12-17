/*******************************************************************************
				-Ws3 - Josephus
				-Itai Marienberg
				-Mon 04 Nov 2019 14:50:59    
 				-Reviewer:
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define N 3           /* user choice*/

void init_arr();       /* initialize the array with N members*/
void kill();           /* execute the nth member starting and index start*/
void reorder_arr();    /* reorder the array such that the member at index 
						  n is removed*/
void print_winner();

int arr[N];       /* user choice*/
int choice = 1;   /* user choice*/
int len = N;
int start = 0; /* must enter the user choice - 1 */

int main()
{
    if (1 > N ||  N < choice )
        {
           printf("Are we here to play or to test this game?\ntry again \n");
           return 0;
        }

    init_arr();


					while (len > 1)
						{
						kill();
						reorder_arr();
						}

					print_winner();

    return 0;
}

void init_arr()
{
	int i = 0;
    for  (i = 0 ; i < N ; ++i)
        arr[i] = i;
}

void kill()
{
    int i = 0;
    i = ( start + 1 ) % len;
    arr[i] = -1;
    start = i;
}

void reorder_arr()
{
    int i;
    for (i = 0; i < len && arr[i] != -1; i++); /* find index of the one to kill*/
		
        for (++i; i < len; ++i) /* increment so we run him over*/
        {
         arr[i-1] = arr[i];
        }
   		 --len;
       
}

void print_winner()
{
    printf("number %d on index %d is the winner ", arr[0],(arr[0] + 1));
    printf("\n");
}



