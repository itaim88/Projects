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
    char *ip1 = "1";
    char *ip2 = "101";
    char *ip3 = "010";
    


    printf("Trie Test 1:\n");  
    new_tree = TrieCreate(); 

    RUN_TEST(1 == TrieIsEmpty(new_tree), "TrieIsEmpty");
    RUN_TEST(0 == TrieSize(new_tree), "insert");
    RUN_TEST(0 == TrieInsert(new_tree, ip1), "insert");
    RUN_TEST(1 == TrieSize(new_tree), "insert");

    RUN_TEST(0 == TrieInsert(new_tree, ip2), "insert");
    RUN_TEST(3 == TrieSize(new_tree), "size");
    RUN_TEST(1 == TrieCountLeafs(new_tree), "trie");
    FreeLeaf(new_tree, ip2);
    RUN_TEST(0 == TrieCountLeafs(new_tree), "trie");

    RUN_TEST(3 == TrieSize(new_tree), "size");
    RUN_TEST(1 == TrieIsAvailable(new_tree, ip2), "trie");
    RUN_TEST(1 == TrieIsAvailable(new_tree, ip1), "trie");

    RUN_TEST(0 == TrieInsert(new_tree, ip3), "insert");
    RUN_TEST(0 == TrieIsAvailable(new_tree, ip3), "trie");


    TrieDestroy(new_tree);

}

int main()
{
    TrieTest1();
  
    return 0;
}






