/*********************************/
/*   			             	 */
/*   Data Structures             */
/*   dhcp                  */
/*   Author: Itai Marienberg     */
/*   Last Updated 20/1/20        */
/*   Reviewed by:                */   
/*			                   	 */
/*********************************/

#include <stdio.h> /* printf */
#include <assert.h> /* assert */

#include "./../include/dhcp.h"

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

static void Test()
{

}
int main()
{   
    Test();
    return 0;
}
