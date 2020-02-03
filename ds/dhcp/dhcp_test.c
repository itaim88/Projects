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
}

static void Test()
{
    dhcp_t *dhcp = NULL;
    unsigned char sub[4] = {7,4,3,0};
    size_t size = 0;

    dhcp = DhcpCreate(sub, 24);
    size = DhcpCountFree(dhcp);
    
    RUN_TEST(253 == DhcpCountFree(dhcp), "CountLeafs");
    DhcpFreeIp(dhcp, sub);
    RUN_TEST(254 == DhcpCountFree(dhcp), "CountLeafs");

    DhcpDetroy(dhcp);

}

static void Test1()
{
    dhcp_t *dhcp = NULL;
    unsigned char sub[4] = {7,4,3,0};
    unsigned char requested[4] = {7,4,3,1};
    unsigned char alloc[4] = {0,0,0,0};
    unsigned char requested1[4] = {0,0,0,0};
    unsigned char requested2[4] = {0,0,3,255};
    unsigned char requested3[4] = {0,0,0,255};

    size_t size = 0;

    dhcp = DhcpCreate(sub, 22);
    size = DhcpCountFree(dhcp);
    RUN_TEST(1021 == DhcpCountFree(dhcp), "CountLeafs");
    RUN_TEST(0 == DhcpAllocIp(dhcp, requested, alloc), "Alloc");
    printf("%d \n", alloc[0]);
    printf("%d \n", alloc[1]);
    printf("%d \n", alloc[2]);
    printf("%d \n", alloc[3]);
    
    RUN_TEST(1 == DhcpAllocIp(dhcp, requested1, alloc), "Alloc");
    printf("%d \n", alloc[0]);
    printf("%d \n", alloc[1]);
    printf("%d \n", alloc[2]);
    printf("%d \n", alloc[3]);

    RUN_TEST(1 == DhcpAllocIp(dhcp, requested2, alloc), "Alloc");
    printf("%d \n", alloc[0]);
    printf("%d \n", alloc[1]);
    printf("%d \n", alloc[2]);
    printf("%d \n", alloc[3]);

    RUN_TEST(0 == DhcpAllocIp(dhcp, requested3, alloc), "Alloc");
    printf("%d \n", alloc[0]);
    printf("%d \n", alloc[1]);
    printf("%d \n", alloc[2]);
    printf("%d \n", alloc[3]);

    DhcpDetroy(dhcp);
}

int main()
{   
    Test();
    Test1();

    return 0;
}
