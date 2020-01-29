/*********************************/
/*   			             	 */
/*   Data Structures             */
/*   trie          */
/*   Author: Itai Marienberg      */
/*   Last Updated          */
/*   Reviewed by:          */   
/*			                   	 */
/*********************************/

#include <stdlib.h>
#include <assert.h>

#include "trie.h"

#define UNUSED(x) (void)(x)

enum Childside
{ 
    LEFT,
    RIGHT,
    NUM_OF_CHILDREN    
};

typedef enum Availability
{ 
    AVAILABLE,
    NOT_AVAILABLE    
} available_t;

typedef struct TrieNode
{
    struct TrieNode *direction[2];
    available_t is_available;
}trie_node_t;

struct Trie
{
    struct TrieNode *root;    
}; 


trie_t *TrieCreate()
{
    trie_t *new_tree = (trie_t*)malloc(sizeof(*new_tree));
    if (NULL == new_tree)
    {
        return NULL;
    }

    new_tree->root = NULL;

    return new_tree;
}

static void DestroyIMP(trie_node_t *node)
{
    if (NULL == node)
    {
        return;
    }

    DestroyIMP(node->direction[LEFT]);
    DestroyIMP(node->direction[RIGHT]);
    free(node);
    node = NULL;
}

void TrieDestroy(trie_t *trie)
{
    assert(NULL != trie);

    DestroyIMP(trie->root);

    trie->root = NULL;
    free(trie);
    trie = NULL;
}


status_t TrieInsert(trie_t *trie, char *data)
{
    
}


bool_t TrieIsEmpty(const trie_t *trie)
{
    assert(NULL != trie);

    return (NULL == trie->root);
      
}

static size_t SizeIMP(trie_node_t *node)
{
    if(NULL == node)
    {
        return 0;
    }

    return (1 + SizeIMP(node->direction[LEFT]) + 
                SizeIMP(node->direction[RIGHT]));
}

size_t TrieSize(const trie_t *trie)
{
    assert(NULL != trie); 

    return SizeIMP(trie->root);
}

static size_t CountUsedLeafsIMP(trie_node_t *node)
{
    if (NULL == node->direction[LEFT] && 
        NULL == node->direction[RIGHT] && 
        NOT_AVAILABLE == node->is_available)
    {
        return 1;   
    }

    else if (NULL == node->direction[LEFT] && 
             NULL == node->direction[RIGHT] && 
             AVAILABLE == node->is_available)
    {
        return 0;
    }

    return (CountUsedLeafsIMP(node->direction[LEFT]) +
            CountUsedLeafsIMP(node->direction[RIGHT]));
}

size_t TrieCountLeafs(const trie_t *trie)
{
    assert(NULL != trie); 

    return CountUsedLeafsIMP(trie->root);  
}

