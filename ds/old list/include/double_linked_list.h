#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

#include <stddef.h> /* size_t */

typedef struct DLLNode *iterator_t;
typedef struct DLL dll_t;

typedef int (*action_func_ptr)(void*, void*);
typedef int (*match_func_ptr)(void*, void*);

/**********************************************/
/* Returns pointer to the DLL data structure  */
/* complexity of malloc                       */
/**********************************************/
dll_t *DLLCreate();

/*************************************************/
/* Destroys the DLL data and free it from memory */
/* complexity of free                            */
/*************************************************/
void DLLDestroy(dll_t *dll);

/*****************************************/
/* Gets a iterator                       */
/* Returns the next iterator             */
/* complexity O(1)                       */
/*****************************************/
iterator_t DLLGetNext(iterator_t it);

/*****************************************/
/* Gets a iterator                       */
/* Returns the pervious iterator         */
/* complexity O(1)                       */
/*****************************************/
iterator_t DLLGetPrev(iterator_t it);

/*********************************************************************/
/* Gets a pointer to a data structure, a iterator and a data pointer */
/* and inserts the iterator before the iterator sent by the user     */
/* complexity O(1)                                                   */
/*********************************************************************/    
iterator_t DLLInsert(dll_t *dll, iterator_t it, void *data);

/*********************************************************************/    
/* Removes the iterator sent to it and returns the iterator next     */
/* to the iterator removed                                           */
/* complexity O(1)                                                   */
/*********************************************************************/    
iterator_t DLLRemove(iterator_t it);

/***********************************************/
/* Checks if the DLL is empty                  */
/* returns 1 if its empty or 0 if not empty    */
/* complexity O(1)                             */
/***********************************************/
int DLLIsEmpty(const dll_t *dll);

/***********************************************/
/* Returns the size of the DLL                 */
/* complexity O(n)                             */
/***********************************************/
size_t DLLSize(const dll_t *dll);

/***********************************************/
/* Returns the first iterator                  */
/* complexity O(1)                             */
/***********************************************/
iterator_t DLLBegin(dll_t *dll);

/***********************************************/
/* Returns the last iterator                   */
/* complexity O(1)                             */
/***********************************************/
iterator_t DLLEnd(dll_t *dll);

/***********************************************/
/* Returns the data of the current iterator    */
/* complexity O(1)                             */
/***********************************************/
void *DLLGetData(iterator_t it);

/*********************************************************/
/* Returns 1 if the iterators are equal or 0 otherwise   */
/* complexity O(1)                                       */
/*********************************************************/
int DLLIsSameIter(const iterator_t it1, const iterator_t it2);

/**********************************************************/
/* Returns an iterator with the data sent to the function */
/* to the end of the data structure. If fails returns     */
/* the tail iterator.                                      */
/* complexity O(1)                                        */
/**********************************************************/
iterator_t DLLPushBack(dll_t *dll, void *data);

/**********************************************************************/
/* Removes the iterator sent to it from the end of the data structure */
/* complexity O(1)                                                    */
/**********************************************************************/
void *DLLPopBack(dll_t *dll);

/**********************************************************/
/* Returns a iterator with the data sent to the function  */
/* to the head of the data structure. If fails returns    */
/* the tail iterator.                                     */
/* complexity O(1)                                        */
/**********************************************************/
iterator_t DLLPushFront(dll_t *dll, void *data);

/***********************************************************************/
/* Removes the iterator sent to it from the head of the data structure */
/* complexity O(1)                                                     */
/***********************************************************************/
void *DLLPopFront(dll_t *dll);

/***************************************************************************/
/* Returns a new list that contains the elements between the iterators     */
/* start and end. Start includes the head iterator and end doesn't include */ 
/* the tail iterator.                                                      */   
/* complexity O(1)                                                         */  
/***************************************************************************/    
iterator_t DLLSplice(iterator_t start, iterator_t end, iterator_t where);

/********************************************************************/
/* Performs an action defined by a pointer to a function on all the */ 
/* iterators from the start to end.                                 */
/* return 0 if succeeds or 1 if fails                               */
/* complexity O(n)                                                  */
/********************************************************************/
int DLLForEach(iterator_t start, iterator_t end, action_func_ptr a_ptr, void *ap);

/********************************************************************/
/* Traverse the list and returns the first iterator that matchs     */
/* a condition defined by the function                              */
/* complexity O(n)                                                  */
/********************************************************************/
iterator_t DLLFind(iterator_t start, iterator_t end, match_func_ptr m_ptr, void *ap);

#endif