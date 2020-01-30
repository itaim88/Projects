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

/************************************************************************/















/**********************************************************************/
static trie_node_t *CreatNodeIMP()
{
    trie_node_t *new_node = (trie_node_t *)malloc(sizeof(trie_node_t));
    if (NULL == new_node)
    {
        return NULL;
    }    

    new_node->direction[LEFT] = NULL;
    new_node->direction[RIGHT] = NULL;
    new_node->is_available = AVAILABLE;

    return new_node;
}

trie_t *TrieCreate()
{
    trie_t *new_tree = (trie_t*)malloc(sizeof(*new_tree));
    if (NULL == new_tree)
    {
        return NULL;
    }

    new_tree->root = CreatNodeIMP();

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

static void StatusUpdateIMP(trie_node_t *node)
{
    if (NOT_AVAILABLE == node->direction[LEFT]->is_available &&
        NOT_AVAILABLE == node->direction[RIGHT]->is_available)
    {
       node->is_available = NOT_AVAILABLE; 
    }
}

static status_t InsertIMP(trie_node_t *node, char *data)
{
    status_t status = SUCCESS;

    if ('\0' == *data )
    {
        node->is_available = NOT_AVAILABLE;

        return SUCCESS;   
    }

    if (NULL == node->direction[*data - 48])
    {
        node->direction[*data - 48] = CreatNodeIMP();
        
        if  (NULL == node->direction[*data - 48])
        {
            return FAIL;
        }            
    }

    status = InsertIMP(node->direction[*data - 48], data + 1);

    if (SUCCESS == status && NULL != node->direction[!(*data - 48)])
    {
        StatusUpdateIMP(node);
    } 

    return status;
}

status_t TrieInsert(trie_t *trie, char *data)
{
    assert(NULL != trie);

    return InsertIMP(trie->root, data);
}

bool_t TrieIsEmpty(const trie_t *trie)
{
    assert(NULL != trie);

    return (NULL == trie->root->direction[LEFT] &&
            NULL == trie->root->direction[RIGHT]);
      
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

    return (SizeIMP(trie->root) - 1);
}

static size_t CountUsedLeafsIMP(trie_node_t *node)
{
    if (NULL == node)
    {
        return 0;
    }

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

static void FreeLeafIMP(trie_node_t *node, char *data)
{
    if ('\0' == *data)
    {
        node->is_available = AVAILABLE;
        return; 
    }

    
    FreeLeafIMP(node->direction[*data - 48], data + 1);
     node->is_available = AVAILABLE;
    
}

void FreeLeaf(trie_t *trie, char *data)
{
    assert(NULL != trie); 

    FreeLeafIMP(trie->root, data);
}

static bool_t TrieIsAvailableIMP(trie_node_t *node, char *data)
{
    status_t status = TRUE;

    if (NULL == node || (AVAILABLE == node->is_available && '\0' == *data))
    {
        return TRUE;
    }

    if (NOT_AVAILABLE  == node->is_available)
    {
        return FALSE;
    }

    status *= TrieIsAvailableIMP(node->direction[*data - 48], data + 1);

    return status;
}

bool_t TrieIsAvailable(trie_t *trie, char *data)
{
    assert(NULL != trie);

    return TrieIsAvailableIMP(trie->root, data);
}

