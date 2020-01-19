/*********************************/
/*   			             	 */
/*   Data Structures             */
/*   AVL                         */
/*   Author: Itai Marienberg     */
/*   Last Updated 7/1/20         */
/*   Reviewed by:                */   
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

static void DestroyNode(avl_node_t *avl_node)
{
    avl_node->child[LEFT] = NULL;
    avl_node->child[RIGHT] = NULL;
    avl_node->data = NULL;

    free(avl_node); 
    avl_node = NULL;
}

static void AVLDestroyHelper(avl_node_t *avl_node)
{
    if (NULL == avl_node)
    {
        return;
    }

    AVLDestroyHelper(avl_node->child[LEFT]);
    AVLDestroyHelper(avl_node->child[RIGHT]);
    DestroyNode(avl_node);
}

void AVLDestroy(avl_t *tree)
{
    assert(NULL != tree);

    AVLDestroyHelper(tree->root);

    tree->root = NULL;
    free(tree); tree = NULL;
}

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
    node->height = 0; 
  
    return node;
}

static void UpdateHeight(avl_node_t *node)
{
    int is_right_null = 0;
    int is_left_null = 0;
    size_t new_height = 0;
    
    assert(node);
    
    is_right_null = !(node->child[RIGHT]);
    is_left_null = !(node->child[LEFT]);
    
    if (!is_right_null)
    {
        new_height = (node->child[RIGHT])->height + 1;
    }

    if ((!is_left_null) && (new_height <= (node->child[LEFT])->height))
    {
        new_height = (node->child[LEFT])->height + 1;
    }
    
    node->height = new_height;
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

    return AVLInsertHelper(node->child[LeftOrRight(&wraper, node->data)], data, wraper);
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

static void RemoveAndUpdate(avl_node_t **current_ptr, avl_node_t *remove_node)
{
    avl_node_t *target_destroy = NULL;
    
    assert (current_ptr);
   
    if (NULL == (*current_ptr)->child[RIGHT])
    {
        target_destroy = *current_ptr;
        *current_ptr = (*current_ptr)->child[LEFT];
        remove_node->data = target_destroy->data;
        DestroyNode(target_destroy);
        return;
    }
    
    RemoveAndUpdate(&((*current_ptr)->child[RIGHT]), remove_node);
    UpdateHeight(*current_ptr);
    /*Balance(current_ptr);*/
}

static void RemoveNode(avl_node_t **avl_node_ptr)
{
    int right_child = !((*avl_node_ptr)->child[LEFT]);
    int left_child = !((*avl_node_ptr)->child[RIGHT]);
    avl_node_t *destroy_target = NULL;

    /* case of 1 or 0 children, connect parent of the avl_node to its child
       if there are no children the parent will be connected to the left side,
       which holds NULL value.
     */ 
    if (right_child + left_child > 0)
    {
        destroy_target = *avl_node_ptr;
        *avl_node_ptr = (*avl_node_ptr)->child[right_child];
        DestroyNode(destroy_target);
        destroy_target = NULL;
    }
    /* case of two children, swap data with prev and destroy */
    else
    {
        RemoveAndUpdate(&((*avl_node_ptr)->child[LEFT]), *avl_node_ptr);
        UpdateHeight(*avl_node_ptr);
        /*Balance(avl_node_ptr);*/
    }
    
}

static void RemoveHelper(avl_node_t **avl_node_ptr, compare_func_t cmp, const void *data)
{
    int cmp_result = cmp(data, (*avl_node_ptr)->data);

    if (0 == cmp_result)
    {
        RemoveNode(avl_node_ptr);
        avl_node_ptr = NULL;
    }
    else
    {
        /* go to right child if compare is positive, else go left */
        RemoveHelper(&(*avl_node_ptr)->child[cmp_result > 0], cmp, data);
        UpdateHeight(*avl_node_ptr);
        /*Balance(avl_node_ptr);*/
    }
}

void AVLRemove(avl_t *tree, const void *data)
{
    assert(NULL != tree);

    RemoveHelper(&(tree->root), tree->wraper.cmp, data);
}

static void *AVLFindHelper(avl_node_t *node, wrap_t wraper)
{
    if (NULL == node)
    {
        return NULL;
    }

    if (0 == wraper.cmp(wraper.user_data, node->data))
    {
        return wraper.user_data;
    }

    return AVLFindHelper(node->child[LeftOrRight(&wraper, node->data)], wraper);
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

/*static size_t GetHeightHelper(avl_node_t *node)
{
    size_t height_left = 0;
    size_t height_right = 0;

    if(NULL == node->child[LEFT] && NULL == node->child[RIGHT])
    {
        return 0;
    }

    height_left = 1 + GetHeightHelper(node->child[LEFT]);
    height_right = 1 + GetHeightHelper(node->child[RIGHT]);

  return (height_left > height_right? height_left : height_right);
}*/


size_t AVLHeight(const avl_t *tree)
{
    avl_node_t *root = NULL;

    assert(NULL != tree);

    root = tree->root;

    return (NULL == root) ? 0 : (root->height);
}

   