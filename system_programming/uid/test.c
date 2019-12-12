
/*******************************************************************************
-Ws UID
-Itai Marienberg
-Dec 10 2019    
*******************************************************************************/

#include <stdio.h>  /*printf */

#include "uid.h" /* uid API */

#define UNUSED(x) (void)(x)
#define GREEN "\033[;032m"
#define RED   "\033[;031m"
#define RESET "\033[0m"

#define RUN_TEST(test,mssg)\
            if (test)\
            {\
                printf(GREEN "SUCCESS: %s\n",mssg);\
                printf(RESET);\
            }\
            else\
            {\
                printf(RED "FAIL: %s\n",mssg);\
                printf(RESET);\
 


int main()
{   
    return 0;
}
