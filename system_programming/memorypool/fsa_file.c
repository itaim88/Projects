/*********************************/
/*   			             	 */
/*   System Programming          */ 
/*   Itai Marienberg	     */
/*   Last Updated 15/12/19       */
/*   Reviewed by:             */   
/*			                   	 */
/*********************************/

#include <stdio.h> /* printf */

#include "fsa.h"

#define UNUSED(x) (void)(x)

#define FREE(ptr) {free(ptr); ptr = NULL;}

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


/*static void SchedulerTest1()
{

}
*/

int main()
{
   /* SchedulerTest1();*/
    return 0;
}
