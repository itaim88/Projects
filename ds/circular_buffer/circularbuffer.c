/*******************************************************************************
-Ws Circular Buffer
-Itai Marienberg
-Dec 5 2019    
*******************************************************************************/

#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*OFFSETOF*/
#include <string.h> /*memcpy*/

#include "circularbuffer.h" /*circular buffer header*/

#define FREE(ptr) free(ptr); ptr = NULL;
#define MIN_SIZE 1

typedef char byte_t; 

struct CBuffer
{
	size_t read_index;
	size_t size;
	size_t capacity;
	byte_t arr[MIN_SIZE];
}; 

cbuffer_t *CBufferCreate(size_t capacity)
{
	cbuffer_t *new_buffer = (cbuffer_t *)malloc(offsetof(cbuffer_t, arr) 
															+ capacity);
	if(NULL == new_buffer)
	{
		return NULL;
	} 

	new_buffer->size = 0UL;
	new_buffer->read_index = 0UL; 
	new_buffer->capacity = capacity;
	
	return new_buffer;
}

void CBufferDestroy(cbuffer_t *cb)
{
	assert(NULL != cb);
	
	FREE(cb);
}

ssize_t CBufferRead(cbuffer_t *cb , void *buffer, size_t count)
{
	size_t buffer_end = (cb->capacity) - (cb->read_index);
	size_t count_return;

	void *runner = NULL;

	assert(NULL != buffer);
	assert(NULL != cb);
	
	if (count > cb->capacity)
	{
		count = cb->capacity;
		count_return = cb->capacity;
	}

	count_return = count;
	runner = buffer;

	if (count > buffer_end)
	{
		memcpy(runner, &cb->arr[cb->read_index], buffer_end);
		cb->size -= buffer_end;
		count -= (cb->read_index) - 1;
		cb->read_index = 0UL;
		runner = (char *)buffer + buffer_end; 	
	}

	memcpy(runner, &cb->arr[cb->read_index],count);	
	cb->size -= count;
	cb->read_index += count;

	return count_return;
}

/*ssize_t CBufferWrite(cbuffer_t *cb ,const void *buffer, size_t count)
{
	const void *run_buff = NULL;
	size_t count_return;
	size_t write_index = cb->read_index + cb->size;
	size_t free_space = CBufferFreeSpace(cb);
	
	assert(NULL != buffer);
	assert(NULL != cb);

	count_return = count;
	run_buff = buffer;

	if (free_space < count)
	{
		count = free_space;
		count_return = free_space;
	}

	if (cb->capacity < (count + write_index))
	{
		memcpy(&cb->arr[cb->read_index + cb->size], run_buff, cb->capacity - 
		 										  write_index);
		count -= cb->capacity - write_index;
		run_buff = (char *)run_buff + cb->capacity - write_index;	
	}
	
	memcpy(&cb->arr[0], run_buff, count);
	cb->size += count_return;
	
	return count_return;
}*/
ssize_t CBufferWrite(cbuffer_t *cb ,const void *buffer, size_t count_to_write)
{   
    byte_t *runner = NULL;
    size_t write_index = 0UL;
    size_t count = 0UL;
    size_t free_space = 0UL;
    size_t size_to_end = 0UL;

    assert(NULL != cb);
    assert(NULL != buffer);
    
    runner = (byte_t *)buffer;
    free_space = CBufferFreeSpace(cb);
    write_index = (cb->read_index + cb->size) % cb->capacity;

    if (count_to_write > free_space)
    {
		count_to_write = free_space;
    }

    count = count_to_write;
    
    if (count > free_space - cb->read_index)
    {
		size_to_end = free_space - cb->read_index;
		memcpy(&cb->arr[write_index], runner, size_to_end);
		count -= size_to_end;
	   	cb->size += size_to_end;
		write_index = 0UL;
		runner += size_to_end;
    }
    
    memcpy(&cb->arr[write_index], runner, count);
    cb->size += count;

    return count_to_write;
}

int CBufferIsEmpty(const cbuffer_t *cb)
{
	assert(NULL != cb);

	return (0UL == cb->size);
}

size_t CBufferCapacity(const cbuffer_t *cb)
{
	assert(NULL != cb);

	return (cb->capacity);

}

size_t CBufferFreeSpace(const cbuffer_t *cb)
{
	assert(NULL != cb);

	return (cb->capacity - cb->size);
}
