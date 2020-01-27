/*******************************************************************************
-Ws3
-Itai Marienberg
-Dec 1 2019    
*******************************************************************************/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/
#include <string.h> /* memcpy*/

#include "vector.h"

struct Vector
{
	void *start;
	size_t size;
	size_t capacity;
	size_t element_size;
};

vector_t* VectorCreate(size_t element_size, size_t capacity)
{
	vector_t *new_vector = NULL;

	if ((0 == element_size) | (0 == capacity))
	{
		return NULL;
	}

	new_vector = (vector_t *)malloc(sizeof(vector_t));
	if (NULL == new_vector)
	{
		return NULL;
	}

	new_vector->start = (void *)malloc((element_size * capacity));
	if (NULL == new_vector->start)
	{
		return NULL;
	}

	new_vector->element_size = element_size;
	new_vector->capacity = capacity;
	new_vector->size = 0;

	return new_vector;
}

void VectorDestroy(vector_t* myvector)
{
	assert(NULL != myvector);

	free(myvector->start); myvector->start = NULL;
	free(myvector); myvector = NULL;
}

int VectorPushBack(vector_t *myvector, const void *data)
{
	int status = 0;
	assert(NULL != myvector);

	if (myvector->size == myvector->capacity)
	{
		myvector->capacity *= 2;
		status = VectorReserve( myvector, (myvector->capacity));
	}

	memcpy(((char *)myvector->start + ((myvector->size * myvector->element_size)
											  )), data, myvector->element_size);
	++(myvector->size);

	return status;
}

void VectorPopBack(vector_t *myvector)
{
	assert(NULL != myvector);

	if ( 0 < myvector->size)
	{
		--(myvector->size);
	
		if ((myvector->capacity / 4) >= (myvector->size))
		{
			VectorReserve(myvector, (myvector->capacity / 2));
		}
	}	
}

int VectorReserve(vector_t *myvector, size_t new_capacity)
{
	assert(NULL != myvector);

	myvector->capacity = new_capacity; 
	myvector->start = (void *)realloc(myvector->start,(new_capacity *
													myvector->element_size));

	if (NULL == myvector->start)
	{
		return 1;
	}

	return 0;
}

size_t VectorCapacity(const vector_t *myvector)
{
	assert(NULL != myvector);

	return (myvector->capacity);
}

size_t VectorSize(const vector_t *myvector)
{
	assert(NULL != myvector);

	return (myvector->size);	
}

void *VectorGetItemAddress(const vector_t *myvector, size_t position)
{
	assert(NULL != myvector);

	if ((0 >= position) | (myvector->size < position))
	{
		return NULL;
	}

	return ((char *)myvector->start + ((position - 1) * (myvector->element_size)
																			 ));
}
