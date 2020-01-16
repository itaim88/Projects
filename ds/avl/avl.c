/*********************************/
/*   			             	 */
/*   Data Structures             */
/*   AVL          */
/*   Author: Itai Marienberg      */
/*   Last Updated 7/1/20         */
/*   Reviewed by:          */   
/*			                   	 */
/*********************************/

#include <stdlib.h>
#include <assert.h>

#include "avl.h"

#define UNUSED(x) (void)(x)
#define FREE(ptr) {free(ptr); ptr = NULL;}

enum
{
    LEFT,
    RIGHT,
    NUM_OF_CHILDREN
};

struct AVLNode
{
    void *data;
    size_t height;
    struct AVLNode *child[NUM_OF_CHILDREN];
};

typedef struct Wrap
{
    void *user_data;
    compare_func_t cmp;
}wrap_t;

struct AVLTree
{
    wrap_t wraper;
    avl_node_t *root;
};



static int LeftOrRight(const void *wrap, const void *tree_data)
{
    return 0 < ((wrap_t *)wrap)->cmp(((wrap_t *)wrap)->user_data, tree_data);
}

static void Balance(avl_node_t *root)
{

}

avl_t *AVLCreate(compare_func_t cmp)
{
    avl_t *new_root = (avl_t *)malloc(sizeof(avl_t));
    if (NULL == new_root)
    {
        return NULL;
    }

    new_root->wraper.cmp = cmp;
    new_root->wraper.user_data = NULL;
    new_root->root = NULL;
    
    return new_root;       
}

/************************************************** 
    Destroys the AVL data and free it from memory 
    Complexity o(n) * free                            
 **************************************************/
static void DestroyHelper(avl_node_t *node)
{

    if (NULL == node->child[LEFT] && NULL == node->child[RIGHT])
    {
        FREE(node);

        return;
        
    }

    DestroyHelper(node->child[LEFT]);
    DestroyHelper(node->child[RIGHT]);
    FREE(node);
}
void AVLDestroy(avl_t *tree) /*postorder*/
{ 

    if (NULL == tree->root)
    {
        FREE(tree);
        return; 
    }

    DestroyHelper(tree->root);
    FREE(tree);
}

/********************************************************************* 
    Gets a pointer to the tree and insert new data in the correct place  
    Return 0 for success, otherwise: 1
    Complexity of malloc * O(log(n))                            
 ********************************************************************/
static avl_node_t *CreateNode(void *data)
{

    avl_node_t *node = (avl_node_t *)malloc(sizeof(avl_node_t));
    if (NULL == node)
    {
        return NULL;
    }
    
    node->child[LEFT] = NULL;
    node->child[RIGHT] = NULL;
    node->data = data;
    node->height = 0; /* need to check*/
  
    return node;
}

static int AVLInsertHelper(avl_node_t *node, void *data, wrap_t wraper)
{

    if (NULL == node->child[LeftOrRight(&wraper, node->data)])
    {
        
        if (NULL == (node->child[LeftOrRight(&wraper, node->data)] = CreateNode(data)))
        {
            return 1;
        } 

        return 0;   
    }

    AVLInsertHelper(node->child[LeftOrRight(&wraper, node->data)], data, wraper);
}

int AVLInsert(avl_t *tree, void *data)
{
    assert(NULL != tree);

    tree->wraper.user_data = data;

    if (NULL == tree->root)
    {
        if (NULL == (tree->root = CreateNode(data)))
        {
            return 1;
        }

        return 0;
    }

    return AVLInsertHelper(tree->root, data, tree->wraper);
}


/*********************************************** 
    Get a pointer to data to remove from the tree
    Complexity: O(log n)
 ***********************************************/
void AVLRemove(avl_t *tree, const void *data)
{

}

/*********************************************************************** 
    Gets a pointer to the tree and search if the data exist in the tree
    Returns the data if it was found, otherwise: NULL
    Complexity: avg-case: O(log(n)), worst-case: O(log(n))
 ***********************************************************************/
static void * AVLFindHelper(avl_node_t *node, wrap_t wraper)
{
    if (NULL == node)
    {
        return NULL;
    }

    if (0 == wraper.cmp(wraper.user_data, node->data))
    {
        return wraper.user_data;
    }

    AVLFindHelper(node->child[LeftOrRight(&wraper, node->data)], wraper);
   
} 
    
void *AVLFind(const avl_t *tree, const void *data)
{
    avl_t *tree_avl = NULL;

    assert(NULL != tree);

    tree_avl = (avl_t *)tree;
    tree_avl-> wraper.user_data = (void *)data;

    if (NULL == tree_avl)
    {
        return NULL;
    }

    return (AVLFindHelper(tree_avl->root, tree_avl->wraper));
}

static int ForeachHelper(avl_node_t *node, action_ptr_t action, void *param)
{
    if (NULL == node)
    {
        return 0;
    }

    return (ForeachHelper(node->child[LEFT], action, param) +
                                   action(param,node->data) +
            ForeachHelper(node->child[RIGHT], action, param));

}

int AVLForeach(avl_t *tree, action_ptr_t action, void *param)
{
    assert(NULL != tree);

    return ForeachHelper(tree->root, action, param);
}  

static size_t SizeHelper(avl_node_t *node)
{
    if(NULL == node)
    {
        return 0;
    }

    return (1 + SizeHelper(node->child[LEFT]) + 
                SizeHelper(node->child[RIGHT]));
}

size_t AVLSize(const avl_t *tree)
{
    assert(NULL != tree);

    return SizeHelper(tree->root);
}

int AVLIsEmpty(const avl_t *tree)
{
    assert(NULL != tree);

    return (NULL == tree->root);
}

static size_t GetHeightHelper(avl_node_t *node)
{
    size_t height_left = 0;
    size_t height_right = 0;

    if(NULL == node->child[LEFT] && NULL == node->child[RIGHT])
    {
        return 0;
    }

    height_left = 1 + GetHeightHelper(node->child[LEFT]);
    height_right = 1 + GetHeightHelper(node->child[RIGHT]);

  return height_left > height_right? height_left : height_right;
}

size_t AVLGetHeight(const avl_t *tree)
{
    assert(NULL != tree);

    if(NULL == tree->root)
    {
        return 0;
    }

    return GetHeightHelper(tree->root);

}


   