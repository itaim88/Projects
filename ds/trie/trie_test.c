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

static void TrieTest1()
{
    trie_t *new_tree = NULL;
    unsigned char ip1[4] = {100,8,5,7};
    unsigned char ip2[4] = {100,8,0,252};
    int check = 0;
    
    printf("Trie Test 1:\n");  
    new_tree = TrieCreate(10); 

    RUN_TEST(1 == TrieIsEmpty(new_tree), "TrieIsEmpty")
    RUN_TEST(0 == TrieEdgeCount(new_tree), "size");
    RUN_TEST(0 == TrieInsert(new_tree, ip1), "insert");
    RUN_TEST(10 == TrieEdgeCount(new_tree), "size");

    RUN_TEST(0 == TrieInsert(new_tree, ip2), "insert");
    RUN_TEST(19 == TrieEdgeCount(new_tree), "size");
    RUN_TEST(2 == TrieCountOccupiedLeafs(new_tree), "CountLeafs");
    

    TrieFreeLeaf(new_tree, ip2);
    check = TrieCountOccupiedLeafs(new_tree);
    RUN_TEST(1 == TrieCountOccupiedLeafs(new_tree), "TrieCountLeafs");
    
    RUN_TEST(1 == TrieIsAvailable(new_tree, ip2), "trie");
    RUN_TEST(0 == TrieIsAvailable(new_tree, ip1), "trie");

    TrieDestroy(new_tree);

}

static void TrieTest2()
{
    trie_t *new_tree = NULL;
    unsigned char ip1[4] = {100,8,5,7};
    unsigned char ip2[4] = {100,8,0,252};
    unsigned char buff[4] = {4,3,2,1};
    int check = 0;
    
    printf("Trie Test 2:\n");  
    new_tree = TrieCreate(10); 

    TreeFindNextAvail(new_tree, buff);

    TrieDestroy(new_tree);

}



int main()
{
    TrieTest1();
    TrieTest2();
  
    return 0;
}






