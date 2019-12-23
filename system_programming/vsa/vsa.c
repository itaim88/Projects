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
#include <assert.h> /*assert */
#include <stdio.h> /*sizeof*/

#include "vsa.h" /*vsa*/

#define SIZE_OF_HEADER sizeof(vsa_t)
#define MAGIC_NUMBER 0x0101010101010101
#define END_OF_SEGMENT 0x7FFFFFFFFFFFFFFF

/* if a block_size is bigger or equele to zero then it's
 free for the user, if the block size is < 0 then it is full */

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

	end_segment = (block_header_t *)((char *)(new_block)
					 + (segment_size - SIZE_OF_HEADER));
	end_segment->block_size = END_OF_SEGMENT ;

	return new_block;
}

void *VSAAlloc(vsa_t *vsa, size_t block_size)
{
    size_t chunks_collector = 0;
    long header_count = 0;
    block_header_t *runner_index = NULL;
    block_header_t *chunk_head_index = NULL;

    assert(NULL != vsa);

    runner_index = vsa;
    chunk_head_index = vsa;

    while ((chunks_collector < block_size) && (END_OF_SEGMENT > runner_index->block_size))
    {
        header_count = 0;
        chunks_collector = 0;

        while ((0 <= runner_index->block_size) && (END_OF_SEGMENT != runner_index->block_size))
        {
            ++header_count;
            chunks_collector += runner_index->block_size;
            runner_index = (block_header_t *)((char *)runner_index +
                                 ((runner_index->block_size) + (SIZE_OF_HEADER)));
        }

        if (chunks_collector < SIZE_OF_HEADER)
        {
            chunks_collector = 0;
        }

        else
        {
            chunks_collector += (header_count * SIZE_OF_HEADER) - (2 * SIZE_OF_HEADER);	
        }
           
        if (block_size <= chunks_collector)
        {
            chunk_head_index->block_size = -block_size;
            runner_index = chunk_head_index;
            runner_index = (block_header_t *)((char *)runner_index + SIZE_OF_HEADER + block_size);
            runner_index->block_size = chunks_collector - block_size;

            #ifndef NDEBUG
            runner_index->magic_number = MAGIC_NUMBER;
            #endif

            break;
        }

        if (END_OF_SEGMENT == runner_index->block_size)
        {
            return NULL; 
        }

        runner_index = (block_header_t *)((char *)runner_index - (runner_index->block_size)+ (SIZE_OF_HEADER));
        chunk_head_index  = runner_index;
    }

    return (void *)(((char *)(chunk_head_index) + SIZE_OF_HEADER));
}

void VSAFree(void *block)
{
    block_header_t *test = NULL;

    assert (NULL != block);

    test = (block_header_t *)block; 
    test = (block_header_t *)((char *) test - SIZE_OF_HEADER);

    assert(test->magic_number == MAGIC_NUMBER);

    block = (void *)(((char *) block - SIZE_OF_HEADER));
    ((block_header_t *)block)->block_size = (-1) * (((block_header_t *)
                                            (block))->block_size);
} 

size_t VSALargestChunkSize(vsa_t *vsa)
{
		long largest = 0;
		long chunks_collector = 0;
		long header_count = 0;

		assert (NULL != vsa);

		while (END_OF_SEGMENT > vsa->block_size)
		{
            header_count = 0;
            chunks_collector = 0;

			while ((0 <= vsa->block_size) && (END_OF_SEGMENT != vsa->block_size))
			{
			    ++header_count;
				chunks_collector += vsa->block_size;
				vsa = (block_header_t *)((char *)vsa + ((vsa->block_size) + (SIZE_OF_HEADER)));
			}

			if (largest < chunks_collector)
			{
				largest = chunks_collector + (header_count * SIZE_OF_HEADER);
			}

            if (END_OF_SEGMENT == vsa->block_size)
            {
                break;
            }

			vsa = (block_header_t *) ((char *)vsa -(vsa->block_size) + (SIZE_OF_HEADER));
		}

		return (largest - ( 2 * SIZE_OF_HEADER)); 
}




