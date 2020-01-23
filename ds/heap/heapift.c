/*********************************/
/*   			             	 */
/*   Heap                        */
/*   Itai Marienberg	         */
/*   Last Updated                */
/*   Reviewed by                 */   
/*			                   	 */
/*********************************/

#include <stddef.h>    /* size_t */
#include <stdlib.h>    /* malloc */
#include <assert.h>    /* assert */

#include "heapify.h" /* priority list functions */

void HeapifyUp(void *arr, size_t size, size_t index, size_t element_size,
                                              cmp_func cmp, void *param);

void HeapifyDown(void *arr, size_t size, size_t index, size_t element_size,
                                                cmp_func cmp, void *param);
