/*********************************/
/*   			             	 */
/*   Data Structures             */
/*   trie         */
/*   Author: Itai Marienberg      */
/*   Last Updated        */
/*   Reviewed by:          */   
/*			                   	 */
/*********************************/

#include <stdio.h> /* printf */
#include <assert.h>
#include <stdlib.h>

#include "trie.h"

#define UNUSED(x) (void)(x)

#define NORMAL "\033[0m"
#define RED "\033[;031m"
#define GREEN "\033[;032m"

#define RUN_TEST(test, error_message){\
    if (test)\
    {\
        printf(GREEN);\
        printf("SUCCESS\n");\
        printf(NORMAL);\
    }\
    else\
    {\
        printf(RED);\
        printf("FAIL %s\n", error_message);\
        printf(NORMAL);\
    }\
}



static void ipTest1()
{
    unsigned char ip[4] = {7, 5, 2, 0};
    unsigned char *ans = malloc(33);
    IPConvertAddress(ip, ans); 

    printf("%s\n" ,ans); 

    free(ans);               
}

int main()
{
    ipTest1();
  
    return 0;
}






