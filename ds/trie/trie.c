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
#define BITS_IN_BYTE 8
#define IP_SIZE 32

typedef enum Childside
{ 
    LEFT,
    RIGHT,
    NUM_OF_CHILDREN    
}side_t;

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
    size_t height;    
}; 

/**************************************************************************/

static trie_node_t *CreatNodeIMP();
static void DestroyIMP(trie_node_t *node);
static void StatusUpdateIMP(trie_node_t *node);
static int IPReadIMP(size_t height, unsigned char *data);
static status_t InsertIMP(trie_node_t *node, unsigned char *data, size_t height);
static size_t EdgeCountIMP(trie_node_t *node);
static size_t CountOccupiedLeafsIMP(trie_node_t *node);
static void FreeLeafIMP(trie_node_t *node, unsigned char *data, size_t height);
static bool_t TrieIsAvailableIMP(trie_node_t *node, unsigned char *data, size_t height);
static void FindNextAvailIMP(trie_node_t *node, unsigned char *ip_buffer, size_t height);

/**************************************************************************/

trie_t *TrieCreate(size_t height)
{
    trie_t *new_tree = (trie_t*)malloc(sizeof(*new_tree));
    if (NULL == new_tree)
    {
        return NULL;
    }

    new_tree->root = CreatNodeIMP();
    new_tree->height = height;

    return new_tree;
}

void TrieDestroy(trie_t *trie)
{
    assert(NULL != trie);

    DestroyIMP(trie->root);

    trie->root = NULL;
    free(trie);
    trie = NULL;
}

status_t TrieInsert(trie_t *trie, unsigned char *data)
{
    assert(NULL != trie);

    if (NULL == trie->root)
    {
            trie->root = CreatNodeIMP();
            if (NULL == trie->root)
            {
                return FAIL;
            }
    }

    return InsertIMP(trie->root, data, trie->height);
}

bool_t TrieIsEmpty(const trie_t *trie)
{
    assert(NULL != trie);

    return (NULL == trie->root->direction[LEFT] &&
            NULL == trie->root->direction[RIGHT]);     
}

size_t TrieEdgeCount(const trie_t *trie)
{
    assert(NULL != trie); 

    return (EdgeCountIMP(trie->root) - 1);
}

size_t TrieCountOccupiedLeafs(const trie_t *trie)
{
    assert(NULL != trie); 

    return CountOccupiedLeafsIMP(trie->root); 
}

void TrieFreeLeaf(trie_t *trie, unsigned char *data)
{
    assert(NULL != trie); 

    FreeLeafIMP(trie->root, data, trie->height);
}

bool_t TrieIsAvailable(trie_t *trie, unsigned char *data)
{
    assert(NULL != trie);

    return TrieIsAvailableIMP(trie->root, data, trie->height);
}

void TreeFindNextAvail(trie_t *trie, unsigned char *ip_buffer)
{
    size_t height;
    int mask = 1;

    assert(NULL != trie);

    height = trie->height;

    while (0 < height)
    {
        *(ip_buffer + ((IP_SIZE - height) / BITS_IN_BYTE)) &=
                     ~(mask << ((height - 1) % BITS_IN_BYTE)); 
        --height;
    }    

    FindNextAvailIMP(trie->root, ip_buffer, trie->height);
}

/**************************************************************************/

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


static void StatusUpdateIMP(trie_node_t *node)
{
    if (NULL != node->direction[LEFT] &&
        NULL != node->direction[RIGHT] &&
        NOT_AVAILABLE == node->direction[LEFT]->is_available &&
        NOT_AVAILABLE == node->direction[RIGHT]->is_available)
    {
       node->is_available = NOT_AVAILABLE; 
    }
}

static int IPReadIMP(size_t height, unsigned char *data)
{
    int mask = 1;
    int side_holder = 0;

    side_holder = ((*(data + (IP_SIZE - height) / BITS_IN_BYTE)) & (mask << ((height - 1) % BITS_IN_BYTE)));

    return (side_holder >> ((height - 1) % BITS_IN_BYTE));    
}

static status_t InsertIMP(trie_node_t *node, unsigned char *data, size_t height)
{
    status_t status = SUCCESS;
    int side = IPReadIMP(height, data);

    if (0 == height)
    {
        node->is_available = NOT_AVAILABLE;

        return SUCCESS;
    }

    if (NULL == node->direction[side])
    {
        node->direction[side] = CreatNodeIMP();
    }

    if (NULL == node->direction[side])
    {
        return FAIL;
    }

    status = InsertIMP(node->direction[side], data, height - 1);
    StatusUpdateIMP(node);

    return status;
}

static size_t EdgeCountIMP(trie_node_t *node)
{
    if(NULL == node)
    {
        return 0;
    }

    return (1 + EdgeCountIMP(node->direction[LEFT]) + 
                EdgeCountIMP(node->direction[RIGHT]));
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

static size_t CountOccupiedLeafsIMP(trie_node_t *node)
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

    return (CountOccupiedLeafsIMP(node->direction[LEFT]) +
            CountOccupiedLeafsIMP(node->direction[RIGHT]));
}

static void FreeLeafIMP(trie_node_t *node, unsigned char *data, size_t height)
{
    int side = 0;
    if (0 == height)
    {
        node->is_available = AVAILABLE;
        return; 
    }

    side = IPReadIMP(height, data);
    FreeLeafIMP(node->direction[side], data, height - 1);
    node->is_available = AVAILABLE;   
}

static bool_t TrieIsAvailableIMP(trie_node_t *node, unsigned char *data, size_t height)
{
    status_t status = TRUE;
    int side = 0;

    if (NULL == node || (AVAILABLE == node->is_available && 0 == height))
    {
        return TRUE;
    }

    if (NOT_AVAILABLE  == node->is_available)
    {
        return FALSE;
    }

    side = IPReadIMP(height, data);
    status *= TrieIsAvailableIMP(node->direction[side], data, height - 1);

    return status;
}

static void FindNextAvailIMP(trie_node_t *node, unsigned char *ip_buffer, size_t height)
{
    int side = IPReadIMP(height, ip_buffer);
    int mask = 1;

    if (NULL == node || 0 == height)
    {
        return;    
    }

    if (NULL != node->direction[LEFT] &&
        NOT_AVAILABLE == node->direction[LEFT]->is_available)
    {
        *(ip_buffer + ((IP_SIZE - height) / BITS_IN_BYTE)) |=
                     (mask << ((height - 1) % BITS_IN_BYTE));  

        FindNextAvailIMP(node->direction[RIGHT], ip_buffer, height - 1);
    }
     
    else
    {
        FindNextAvailIMP(node->direction[LEFT], ip_buffer, height - 1);
    }
}