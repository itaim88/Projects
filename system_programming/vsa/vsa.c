/*********************************/
/*   			             	 */
/*   System Programming          */
/*   vsa                 		 */
/*   Itai Marienberg			 */
/*   Last Updated 20/12/19       */
/*   Reviewed by:                */   
/*			                   	 */
/*********************************/

#include <stddef.h>	/*size_t*/
#include <assert.h> /* assert */
#include <stdio.h> /*sizeof*/
#include <stdlib.h> /*abc*/

#include "vsa.h" /*vsa*/

/*#define BYTES_IN_SMALL_WORD sizeof(size_t)*/
#define SIZE_OF_HEADER sizeof(vsa_t)
#define MAGIC_NUMBER 0x0101010101010101
#define END_OF_SEGMENT 0x0123456789ABCDEF

/* if a long block_size is bigger or equele then zero then it's
 free for the user if the long block is < 0 then it is full;

/*#define MSB 0x10000000*/

struct BlockHeader
{
	long block_size;

	#ifndef NDEBUG
	long magic_number;
	#endif	
};

typedef vsa_t block_header_t;

vsa_t *VSAInit(void *allocated, size_t segment_size)
{
	block_header_t *new_block = NULL;
	block_header_t *end_segment = NULL;

	assert (NULL != allocated);

	new_block = allocated;
	new_block->block_size = segment_size - (2 * SIZE_OF_HEADER);

	#ifndef NDEBUG
	new_block->magic_number =  MAGIC_NUMBER;
	#endif

	end_segment = (block_header_t *)(char *)(new_block)
					 + (segment_size - SIZE_OF_HEADER);
	end_segment->block_size = END_OF_SEGMENT ;

	return new_block;
}
           
void *VSAAlloc(vsa_t *vsa, size_t block_size)
{

}
       

void VSAFree(void *block)
{
	assert (NULL != block);

	((block_header_t *)block)->block_size = abs(((block_header_t *)
											(block))->block_size);
}

size_t VSALargestChunkSize(vsa_t *vsa)
{
		size_t largest = 0;
		size_t chunks_colector = 0;

		assert (NULL != vsa);

		while (END_OF_SEGMENT != vsa->block_size)
		{

			while (0 <= vsa->block_size) 
			{
				chunks_colector += vsa->block_size;
				vsa = ((block_header_t *) (char *)vsa + (vsa->block_size));
			}

			if (largest < chunks_colector)
			{
					largest = chunks_colector;
			}

			chunks_colector = 0;

			vsa = ((block_header_t *) (char *)vsa + (vsa->block_size));

		}

		return largest;
}


