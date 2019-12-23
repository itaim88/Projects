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

struct BlockHeader
{
    long block_size;
    
    #ifndef NDEBUG
    long unique;
    #endif
};

static void TestInitDebug()
{
    void *allocated = malloc(1000);
    vsa_t *vsa = NULL;
    
    printf("Test Init: \n");
    
    vsa = VSAInit(allocated, 1000);
    
    RUN_TEST(968 == vsa->block_size);
    
    free(allocated); allocated = NULL;
}

static void TestAllocDebug()
{
    void *allocated = malloc(1000);
    void *block1 = NULL, *block2 = NULL, *block3 = NULL;
    vsa_t *vsa = NULL;

    printf("\nTest Alloc: \n");
    
    vsa = VSAInit(allocated, 1000);
    
    block1 = VSAAlloc(vsa, 200);
    
    block1 = (char *)block1 - sizeof(vsa_t);
    
    RUN_TEST(-200 == ((vsa_t *)block1)->block_size);
    
    block2 = VSAAlloc(vsa, 300);
    
    block2 = (char *)block2 - sizeof(vsa_t);
    
    RUN_TEST(-300 == ((vsa_t *)block2)->block_size);
    
    block3 = VSAAlloc(vsa, 452);
    
    RUN_TEST(NULL == block3);
    
    block3 = VSAAlloc(vsa, 400);
    
    block3 = (char *)block3 - sizeof(vsa_t);
    
    RUN_TEST(-400 == ((vsa_t *)block3)->block_size);
    
    free(allocated); allocated = NULL;
}

static void TestFreeDebug()
{
    void *allocated = malloc(1000);
    void *block1 = NULL, *block2 = NULL, *block3 = NULL, *runner = NULL;
    vsa_t *vsa = NULL;
    
    printf("\nTest Free: \n");

    vsa = VSAInit(allocated, 1000);
    
    block1 = VSAAlloc(vsa, 100);
    block2 = VSAAlloc(vsa, 200);
    block3 = VSAAlloc(vsa, 300);
    
    VSAFree(block2);
    block2 = (char *)block2 - sizeof(vsa_t);
    
    RUN_TEST(304 == VSALargestChunkSize(vsa));
    
    RUN_TEST(200 == ((vsa_t *)block2)->block_size);

    VSAFree(block1);    
    VSAFree(block3);
    block1 = (char *)block1 - sizeof(vsa_t);

    RUN_TEST(100 == ((vsa_t *)block1)->block_size);
    
    block1 = VSAAlloc(vsa, 50);
    
    runner = block1;
    runner = (char *)runner - sizeof(vsa_t);

    RUN_TEST(-50 == ((vsa_t *)runner)->block_size);
    
    runner = (char *)runner - (((vsa_t *)runner)->block_size) + sizeof(vsa_t);

    RUN_TEST(902 == ((vsa_t *)runner)->block_size);
    
    free(allocated); allocated = NULL;
}

static void TestInitRelease()
{
    void *allocated = malloc(1000);
    vsa_t *vsa = NULL;
    
    printf("Test Init: \n");
    
    vsa = VSAInit(allocated, 1000);
    
    RUN_TEST(984 == vsa->block_size);
    
    free(allocated); allocated = NULL;
}

static void TestAllocRelease()
{
    void *allocated = malloc(1000);
    void *block1 = NULL, *block2 = NULL, *block3 = NULL;
    vsa_t *vsa = NULL;

    printf("\nTest Alloc: \n");
    
    vsa = VSAInit(allocated, 1000);
    
    block1 = VSAAlloc(vsa, 200);
    
    block1 = (char *)block1 - sizeof(vsa_t);
    
    RUN_TEST(-200 == ((vsa_t *)block1)->block_size);
    
    block2 = VSAAlloc(vsa, 300);
    
    block2 = (char *)block2 - sizeof(vsa_t);
    
    RUN_TEST(-300 == ((vsa_t *)block2)->block_size);
    
    block3 = VSAAlloc(vsa, 452);
    
    block3 = (char *)block3 - sizeof(vsa_t);
    
    RUN_TEST(-452 == ((vsa_t *)block3)->block_size);
    
    free(allocated); allocated = NULL;
}

static void TestFreeRelease()
{
    void *allocated = malloc(1000);
    void *block1 = NULL, *block2 = NULL, *block3 = NULL, *runner = NULL;
    vsa_t *vsa = NULL;
    
    printf("\nTest Free: \n");

    vsa = VSAInit(allocated, 1000);
    
    block1 = VSAAlloc(vsa, 100);
    block2 = VSAAlloc(vsa, 200);
    block3 = VSAAlloc(vsa, 300);
    
    VSAFree(block2);
    block2 = (char *)block2 - sizeof(vsa_t);
   
    RUN_TEST(352 == VSALargestChunkSize(vsa));
 
    RUN_TEST(200 == ((vsa_t *)block2)->block_size);

    VSAFree(block1);    
    VSAFree(block3);
    block1 = (char *)block1 - sizeof(vsa_t);

    RUN_TEST(100 == ((vsa_t *)block1)->block_size);
    
    block1 = VSAAlloc(vsa, 50);
    
    runner = block1;
    runner = (char *)runner - sizeof(vsa_t);
    
    RUN_TEST(-50 == ((vsa_t *)runner)->block_size);
    
    runner = (char *)runner - ((vsa_t *)runner)->block_size + sizeof(vsa_t);
    
    RUN_TEST(926 == ((vsa_t *)runner)->block_size);
    
    free(allocated); allocated = NULL;
}

int main()
{
    #ifndef NDEBUG
    TestInitDebug();
    TestAllocDebug();
    TestFreeDebug();
    #endif
    
    #ifdef NDEBUG
    TestInitRelease();          
    TestAllocRelease();
    TestFreeRelease();
    #endif   
    
    return 0;
}
