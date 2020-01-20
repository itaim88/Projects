/*********************************/
/*   			             	 */
/*   Data Structures             */
/*   AVL                         */
/*   Author: Itai Marienberg     */
/*   Last Updated 20/1/20        */
/*   Reviewed by:                */   
/*			                   	 */
/*********************************/

#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/

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

static void DestroyNode(avl_node_t *node)
{
    node->child[LEFT] = NULL;
    node->child[RIGHT] = NULL;
    node->data = NULL;

    FREE(node);
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
    FREE(tree);
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
    size_t new_height = 0;
    
    assert(NULL != node);
    
    if (NULL != node->child[RIGHT])
    {
        new_height = (node->child[RIGHT])->height + 1;
    }

    if ((NULL != node->child[LEFT]) && (new_height <= (node->child[LEFT])->height))
    {
        new_height = (node->child[LEFT])->height + 1;
    }
    
    node->height = new_height;
}

static int GetHeightHelper(avl_node_t *node)
{
    return ((NULL == node) ? 0 : (node->height + 1));
}

static int CalcBalanceFactor(avl_node_t *node)
{
    assert (NULL != node);
    
    return (GetHeightHelper(node->child[LEFT]) -
            GetHeightHelper(node->child[RIGHT]));
}

static void Rotate(avl_node_t **node, int side)
{
    avl_node_t *child_rot = NULL;
    
    assert(NULL != node);
    
    child_rot = (*node)->child[!side];
    (*node)->child[!side] = child_rot->child[side];
    child_rot->child[side] = *node;
    *node = child_rot;

    UpdateHeight((*node)->child[side]);
    UpdateHeight(*node);
    
    return; 
}

static void Balance(avl_node_t **root)
{
    int balance_factor = 0;
    
    assert(NULL != root);
    
    balance_factor = CalcBalanceFactor(*root);
    
    if (balance_factor < (-1))
    {   
        if (CalcBalanceFactor((*root)->child[RIGHT]) > 0)
        {
            Rotate(&(*root)->child[RIGHT], RIGHT);
        }
        
        Rotate(root, LEFT);
    }

    else if (balance_factor > 1)
    {
        if (CalcBalanceFactor((*root)->child[LEFT]) < 0)
        {
            Rotate(&(*root)->child[LEFT], LEFT);
        }
        
        Rotate(root, RIGHT);
    }

    return;
}

static int AVLInsertHelper(avl_node_t **node_ptr, compare_func_t cmp, void *data)
{
    int cmp_result = 0;
    int success_or_fail = 0;
    avl_node_t **next = NULL;

    if (NULL == *node_ptr)
    {
        *node_ptr = (CreateNode(data));

        if (NULL == *node_ptr)
        {
            return 1;
        }

        return 0;
    }

    cmp_result = cmp(data, (*node_ptr)->data);

    if (0 == cmp_result)
    {
        return 1;
    }

    next = &((*node_ptr)->child[cmp_result > 0]);    
    success_or_fail = AVLInsertHelper(next, cmp, data);
    
    if (0 == success_or_fail)
    {
        UpdateHeight(*node_ptr);
        Balance(node_ptr);
    }

    return success_or_fail;
}

int AVLInsert(avl_t *root, void *data)
{
    assert(NULL !=root);

    return (AVLInsertHelper(&(root->root), root->wraper.cmp, data));
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
    Balance(current_ptr);
}

static void RemoveNode(avl_node_t **avl_node_ptr)
{
    int right_child = !((*avl_node_ptr)->child[LEFT]);
    int left_child = !((*avl_node_ptr)->child[RIGHT]);
    avl_node_t *destroy_target = NULL;

    if (right_child + left_child > 0)
    {
        destroy_target = *avl_node_ptr;
        *avl_node_ptr = (*avl_node_ptr)->child[right_child];
        DestroyNode(destroy_target);
        destroy_target = NULL;
    }

    else
    {
        RemoveAndUpdate(&((*avl_node_ptr)->child[LEFT]), *avl_node_ptr);
        UpdateHeight(*avl_node_ptr);
        Balance(avl_node_ptr);
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
        RemoveHelper(&(*avl_node_ptr)->child[cmp_result > 0], cmp, data);
        UpdateHeight(*avl_node_ptr);
        Balance(avl_node_ptr);
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

size_t AVLGetHeight(const avl_t *tree)
{
    avl_node_t *root = NULL;

    assert(NULL != tree);

    root = tree->root;

    return ((NULL == root) ? 0 : (root->height));
}

   
