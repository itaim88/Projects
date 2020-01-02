/*********************************/
/*    Data Structures            */
/*    sort               */       
/*    Author : itai           */
/*    Reviewed By:       */
/*           */
/*********************************/

#include <stddef.h> /*size_t */ 

/*#include "sort.h"*/

void BubbleSort(int arr[], size_t length)
    {
        size_t i = 0;
        size_t j = 0;
        int is_sorted_done = 0;
        int temp = 0;

        for (i = 0; i < length - 1; ++i)
        {
            is_sorted_done = 0;

            for (j = 0; j < length - 1 -i; ++j)
            {
                if (arr[j] > arr[j+1])
                {   
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    is_sorted_done = 1; 
                }
            }

            if (0 == is_sorted_done)
            {
                break;  
            }   
        }
    }
