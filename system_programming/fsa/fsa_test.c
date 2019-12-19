/*********************************/
/*    Data Structures            */
/*    Fixed Size Allocator       */       
/*    Author: Guy Cohen Zedek    */
/*    Date: 18/12/2019           */
/*                               */
/*********************************/

#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */

#include "fsa.h" /* API functions */

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

struct FixedSizeAllocator
{
    size_t next_available_inedx;
    size_t block_size;
    size_t segment_size;
};

struct BlockHeader
{
    size_t next_free_index;
};

static void TestSuggestSize()
{
    size_t block_size = 4;
    size_t blocks_count = 5;
    printf("\nTest Suggest:\n");
    printf("5 block of size 4 bytes:\n");
    RUN_TEST(104 == FSASuggestSize(blocks_count, block_size));
    
    block_size = 12;
    blocks_count = 5;
    
    printf("\n5 block of size 12 bytes:\n");    
    RUN_TEST(144 == FSASuggestSize(blocks_count, block_size));
}

static void TestFSAInit()
{
    char *allocated = malloc(56);
    fsa_t *fsa_ptr = NULL;
    
    printf("\nTest Initialize:\n");
    fsa_ptr = FSAInit(allocated, 56, 4);

    RUN_TEST(24 == fsa_ptr->next_available_inedx);
    RUN_TEST(8 == fsa_ptr->block_size);
    
    free(allocated); allocated = NULL;
}

static void TestFSAAlloc()
{
    void *allocated = malloc(56);
    void *place1 = NULL, *place2 = NULL;
    fsa_t *fsa_ptr = NULL;
    
    printf("\nTest Alloc:\n");
    fsa_ptr = FSAInit(allocated, 56 , 4);
    place1 = FSAAlloc(fsa_ptr);
    place2 = FSAAlloc(fsa_ptr);
    
    place1 = (char *)place1 - 8;
    place2 = (char *)place2 - 8;
    
    RUN_TEST(24 == ((struct BlockHeader *)place1)->next_free_index);
    RUN_TEST(40 == ((struct BlockHeader *)place2)->next_free_index);
    
    RUN_TEST(0 == FSACountFree(fsa_ptr));
    
    free(allocated); allocated = NULL;  
}

static void TestFSAFree()
{
    void *allocated = malloc(104);
    void *place1 = NULL, *place2 = NULL, *place3 = NULL, *place4 = NULL;
    fsa_t *fsa_ptr = NULL;
    
    printf("\nTest Free:\n");
    fsa_ptr = FSAInit(allocated, 104 , 4);
    place1 = FSAAlloc(fsa_ptr);
    place2 = FSAAlloc(fsa_ptr);
    place3 = FSAAlloc(fsa_ptr);
    place4 = FSAAlloc(fsa_ptr);
    
    RUN_TEST(1 == FSACountFree(fsa_ptr));
    
    FSAFree(place2);
    RUN_TEST(2 == FSACountFree(fsa_ptr));  
    FSAFree(place3);
    RUN_TEST(3 == FSACountFree(fsa_ptr));
    FSAFree(place1);
    RUN_TEST(4 == FSACountFree(fsa_ptr));
    FSAFree(place4);
    RUN_TEST(5 == FSACountFree(fsa_ptr));
    
    free(allocated); allocated = NULL;   
}

int main()
{  
    TestSuggestSize();
    TestFSAInit();
    TestFSAAlloc();
    TestFSAFree();
    
    return 0;
}
