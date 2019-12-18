/*********************************/
/*   			             	 */
/*   System Programming          */
/*   Scheduler                   */
/*   Itai Marienberg	      */
/*   Last Updated 17/12/19       */
/*   Reviewed by:                */   
/*			                   	 */
/*********************************/

#include <stddef.h>	/*size_t*/
#include <stdlib.h> /* malloc */
#include <assert.h> /* assert */

#include "fsa.h" /*priority functions*/

#define FREE(ptr) {free(ptr); ptr = NULL;}

typedef struct Block_Header block_header_t;
