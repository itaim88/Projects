/*********************************/
/*   			             	 */
/*   Data Structures             */
/*   Hash Table                  */
/*   Author: Itai Marienberg     */
/*   Last Updated 21/1/20        */
/*   Reviewed by:                */   
/*			                   	 */
/*********************************/

#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <stddef.h> /*OFFSETOF*/

#include "dllist.h"
#include "hash.h"

#define UNUSED(x) (void)(x)
#define FREE(ptr) {free(ptr); ptr = NULL;}

struct Hash
{
	size_t table_size;
	match_func_t is_match;
	hash_func_t hash_func;
	dll_t *table[1];
};

hash_t *HashCreate(size_t table_size, hash_func_t hash_func, match_func_t is_match)
{
	size_t i = 0;
	size_t j = 0;

	hash_t *new_hash = (hash_t*)malloc(offsetof(hash_t, table) +
							 (table_size * sizeof(dll_t *))); 
	if (NULL == new_hash)
	{
		return NULL;
	}

	new_hash->table_size = table_size;
	new_hash->is_match = is_match;
	new_hash->hash_func = hash_func;

	for (i = 0; i < table_size; ++i)
	{
		new_hash->table[i] = DLLCreate();
		if (NULL == new_hash->table[i])
		{
			for (j = 0; j < i ; ++j)
			{
				DLLDestroy(new_hash->table[j]);
			}

		free(new_hash);
		new_hash = NULL;

		return NULL;

		}
	}

	return new_hash;
}

void HashDestroy(hash_t *hash_table)
{
	size_t i = 0;

	assert(NULL != hash_table);

	for (i = 0; i < hash_table->table_size; ++i)
	{
		DLLDestroy(hash_table->table[i]);
	}

	free(hash_table);
	hash_table = NULL;
}

int HashInsert(hash_t *hash_table, void *data)
{
	dll_t *position = NULL;

	assert(NULL != hash_table);

	position = hash_table->table[hash_table->hash_func(data)];

	return (NULL == DLLInsert(position, DLLBegin(position),data));	
}

static void *HashRemoveHelper(hash_t *hash_table, const void *data)
{
	size_t hash_key = 0;

	assert(NULL != hash_table);

	hash_key = hash_table->hash_func(data);

    return ((DLLFind(DLLBegin(hash_table->table[hash_key]),
			DLLEnd(hash_table->table[hash_key]),
		    hash_table->is_match, (void *)data)));
 
}

void HashRemove(hash_t *hash_table, const void *data)
{
	assert(NULL != hash_table);	

	DLLRemove(HashRemoveHelper(hash_table, data));
}

void *HashFind(const hash_t *hash_table, const void *data)
{
	size_t hash_key = 0;
	void *node_data = NULL;
	iterator_t iter;

	assert(NULL != hash_table);	

	hash_key = hash_table->hash_func(data);
	iter = (HashRemoveHelper((hash_t *)hash_table, data));

	node_data = DLLGetData(iter);
	if (NULL != node_data)
	{	
		DLLRemove(iter);
		DLLPushFront(hash_table->table[hash_key], (void *)data);
	}
	
	return node_data;
}

int HashForeach(hash_t *hash_table, action_func_t action, void *param)
{
	size_t i = 0;
	int succ_or_fail = 0;

	assert(NULL != hash_table);

	for(i = 0; (i < hash_table->table_size) && (0 == succ_or_fail); ++i)  
	{
		succ_or_fail = DLLForEach(DLLBegin(hash_table->table[i]), 
				  	   DLLEnd(hash_table->table[i]), action, param);
	}

	return succ_or_fail;	
}

size_t HashSize(const hash_t *hash_table)
{
	size_t i = 0;
	size_t size = 0;

	assert(NULL != hash_table);

	for (i = 0; i < hash_table->table_size; ++i)
	{
		size += DLLSize(hash_table->table[i]);
	}

	return size;
}

int HashIsEmpty(const hash_t *hash_table)
{
	size_t i = 0;

	assert(NULL != hash_table);

	for (i = 0; i < hash_table->table_size; ++i)
	{
		if (1 != DLLIsEmpty(hash_table->table[i]))
		{
			return 0;
		}
	}
    
    return 1; 
}




