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

struct AVLTree
{
    compare_func_t cmp;
    avl_node_t *root;
};

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

    new_root->cmp = cmp;
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
        
    }

    DestroyHelper(node->child[LEFT]);
    DestroyHelper(node->child[RIGHT]);
    FREE(node);
}
void AVLDestroy(avl_t *tree) /*postorder*/
{
    assert(NULL != tree);

    if ( NULL == tree->node)
    {
        FREE(tree);
        return; 
    }

    DestroyHelper(tree->node);
    FREE(tree);
}

/********************************************************************* 
    Gets a pointer to the tree and insert new data in the correct place  
    Return 0 for success, otherwise: 1
    Complexity of malloc * O(log(n))                            
 ********************************************************************/
static avl_node_t *CreateNode(avl_node_t *node, void *data)
{
    node = (avl_node_t *)malloc(sizeof(avl_node_t));
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

int AVLInsert(avl_t *tree, void *data);

/*********************************************** 
    Get a pointer to data to remove from the tree
    Complexity: O(log n)
 ***********************************************/
void AVLRemove(avl_t *tree, const void *data);

/*********************************************************************** 
    Gets a pointer to the tree and search if the data exist in the tree
    Returns the data if it was found, otherwise: NULL
    Complexity: avg-case: O(log(n)), worst-case: O(log(n))
 ***********************************************************************/
void *AVLFind(const avl_t *tree, const void *data);

/********************************************************************************** 
    Gets a tree pointer and action function pointer to operate on the elements in the tree
    Returns 0 for success, otherwise: non-zero value
    Complexity: worst-case: O(n) 
 ***********************************************************************************/
int AVLForeach(avl_t *tree, action_ptr_t action, void *param);

/*inorder*/

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


   