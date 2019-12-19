/*********************************/
/*   			             	 */
/*   System Programming          */
/*   fsa                  */
/*   Itai Marienberg	      */
/*   Last Updated 17/12/19       */
/*   Reviewed by:                */   
/*			                   	 */
/*********************************/

#include <stddef.h>	/*size_t*/
#include <assert.h> /* assert */
#include <stdio.h> /*sizeof*/

#include "fsa.h" /*fsa*/

#define BYTES_IN_SMALL_WORD sizeof(size_t)
#define SIZE_OF_FSA sizeof(fsa_t)
#define SIZE_OF_BLOCK_HEAD sizeof(header_block_t)

typedef struct BlockHeader
{
	size_t next_free_index;
} header_block_t;

struct FixedSizeAllocator
{
	size_t next_available_index;
	size_t block_size;
	size_t segment_size;
};

size_t RevisedBlockSize(const size_t block_size)
{
	size_t revised_block_size = block_size;

	while (0 != (revised_block_size % BYTES_IN_SMALL_WORD))
	{
		++revised_block_size;
	}

	return revised_block_size;
}

size_t BlockCounter(fsa_t *fsa)
{
	assert(NULL != fsa);

	return  (fsa->segment_size - SIZE_OF_FSA) / (fsa->block_size + SIZE_OF_BLOCK_HEAD);
}

fsa_t *FSAInit(void *allocated, const size_t segment_size, const size_t block_size)
{
	fsa_t *new_fsa = NULL;
	header_block_t *block_header = NULL;
	size_t number_of_blocks = 0UL;
	size_t index_holder = 0UL;

	assert(NULL != allocated);

	new_fsa = allocated;
	new_fsa->next_available_index = SIZE_OF_FSA;
	new_fsa->block_size = RevisedBlockSize(block_size);
	new_fsa->segment_size = segment_size;

	block_header = (header_block_t *)((char *)new_fsa + SIZE_OF_FSA);
	block_header->next_free_index = new_fsa->next_available_index;
	number_of_blocks = BlockCounter(new_fsa);

	index_holder = block_header->next_free_index;

	while (0UL < (number_of_blocks - 1UL))
	{
		block_header->next_free_index = index_holder + new_fsa->block_size + 
														SIZE_OF_BLOCK_HEAD;
		index_holder = block_header->next_free_index;
		block_header = (header_block_t *)((char *)block_header +
								 (SIZE_OF_BLOCK_HEAD + new_fsa->block_size));
		--number_of_blocks;
	}

	block_header->next_free_index = index_holder + new_fsa->block_size +
													 SIZE_OF_BLOCK_HEAD;

	return new_fsa;
}

void *FSAAlloc(fsa_t *fsa)
{
	size_t temp_index_for_swap = 0UL;
	header_block_t *jump_to_available = NULL;

	assert(NULL != fsa);

	if (!FSACountFree(fsa))
	{
		return NULL;
	}

	temp_index_for_swap = fsa->next_available_index;
	jump_to_available = (header_block_t *)((char *)fsa + temp_index_for_swap);
	fsa->next_available_index = jump_to_available->next_free_index;
	jump_to_available->next_free_index = temp_index_for_swap;

	return ((void *)((char *)jump_to_available + SIZE_OF_BLOCK_HEAD));
}

void FSAFree(void *block)
{
	header_block_t *head_runner = NULL;
	size_t index_for_moving = 0UL;
	size_t index_for_holding = 0UL;

	assert(NULL != block);

	head_runner = (header_block_t *)((char *)block - SIZE_OF_BLOCK_HEAD);
	index_for_moving = head_runner->next_free_index;
	head_runner = (header_block_t *)((char *)head_runner - (index_for_moving));
	index_for_holding = ((fsa_t *)head_runner)->next_available_index;
	((fsa_t *)head_runner)->next_available_index = index_for_moving;
	head_runner = (header_block_t *)((char *)head_runner + (index_for_moving));
	head_runner->next_free_index = index_for_holding;
}

size_t FSACountFree(const fsa_t *fsa)
{	
	header_block_t *runner = NULL;
	size_t counter_for_free = 0UL;

	assert(NULL != fsa);

	runner = (header_block_t *)fsa;

	while (fsa->segment_size > runner->next_free_index)
	{
		++counter_for_free;
		runner = (header_block_t *)(((char *)fsa + runner->next_free_index));
	}
	
	return counter_for_free;
}

size_t FSASuggestSize(const size_t blocks_count, const size_t block_size)
{	
	return ((blocks_count * (RevisedBlockSize(block_size) + SIZE_OF_BLOCK_HEAD))
	                                       					  + SIZE_OF_FSA);
}
