/*********************************/
/*                               */
/*   System Programming          */
/*   vsa                         */
/*   Itai Marienberg             */
/*   Last Updated 20/12/19       */
/*   Reviewed by:                */   
/*                               */
/*********************************/

#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */

#include "vsa.h" /* API functions */

#define MAX_BLOCK_SIZE 20
#define MAX_BLOCK_COUNT 100

#define GREEN "\033[;032m"
#define RED   "\033[;031m"
#define RESET "\033[0m"

#define UNUSED(x) (void)(x)

#define RUN_TEST(test)\
{\
  if(test)\
  {\
    printf(GREEN);\
    printf("SUCCESS\n");\
    printf(RESET);\
  }\
  else\
  {\
    printf(RED);\
    printf("FAIL \n");\
    printf(RESET);\
  }\
}



int main()
{  
 
    
    return 0;
}
