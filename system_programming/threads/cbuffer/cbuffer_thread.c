#include <stdio.h>   /* printf */
#include <assert.h>  /* assert */
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*OFFSETOF*/

#include "cbuffer_thread.h"

#define FAIL 1
#define MIN_SIZE 1
#define PRODUCERS 40
#define CONSUMERS 20

struct CBuffer
{
    size_t read_index;
    size_t write_index;
    size_t capacity;
    int arr[MIN_SIZE];
}; 

cbuffer_t *CBufferCreate(size_t capacity)
{
    cbuffer_t *new_buffer = (cbuffer_t *)malloc(offsetof(cbuffer_t, arr)  + (capacity * sizeof(int)));
    if(NULL == new_buffer)
    {
        return NULL;
    } 

    new_buffer->write_index = 0UL;
    new_buffer->read_index = 0UL; 
    new_buffer->capacity = capacity;
    
    return new_buffer;
}

void CBufferDestroy(cbuffer_t *cb)
{
    assert(NULL != cb);
    
    free(cb);
    cb = NULL;
}

int CBufferRead(cbuffer_t *cb)
{
    int read_val = 0;

    assert(NULL != cb);

    read_val = cb->arr[cb->read_index];
    ++(cb->read_index);
    cb->read_index %= cb->capacity;
    
    return read_val;
}

void CBufferWrite(cbuffer_t *cb ,int num)
{
    assert(NULL != cb);

    cb->arr[cb->write_index] = num;
    ++(cb->write_index);
    cb->write_index %= cb->capacity;
}




/*
enum
{
    FREE,
    LOCK
};


pthread_mutex_t lock = {0};
int val = 1;
sem_t count = {0};

void *Consumer(void *dll_node);
void *Producer(void *dll_node);
  

int main()
{
    size_t i = 0;
    int status = 0;

    dll_t *new_dll = NULL;
    
    pthread_t producers[PRODUCERS];
    pthread_t consumers[CONSUMERS];
    
    pthread_mutex_init(&lock, NULL);
    sem_init (&count, 0, 0);

    new_dll = DLLCreate();
    if (NULL == new_dll)
    {
        return FAIL;
    }
    
    for (i = 0; i < PRODUCERS; ++i)
    {
        status = pthread_create(&(producers[i]), NULL, Producer,new_dll);
        if (0 != status)
        {
            printf("ERROR\n");
            return FAIL;
        }
    }
    
    for (i = 0; i < CONSUMERS; ++i)
    {
        status = pthread_create(&(consumers[i]), NULL, Consumer, new_dll);
        if (0 != status)
        {
            printf("ERROR\n");
            return FAIL;
        }
    }
    
    for (i = 0; i < PRODUCERS; ++i)
    {
        pthread_join(producers[i], NULL);
    }
    
    for (i = 0; i < CONSUMERS; ++i)
    {
        pthread_join(consumers[i], NULL);
    }
    
    DLLDestroy(new_dll);
    pthread_mutex_destroy(&lock);
    sem_destroy(&count);
    
    return 0;
}

void *Consumer(void *dll_node)
{
    assert(NULL != dll_node);
    
    sem_wait(&count);

    pthread_mutex_lock(&lock); 
    printf("%d\n", *(int*)DLLPopFront((dll_t *)dll_node)); 
    pthread_mutex_unlock(&lock);
    
    return NULL;
} 

void *Producer(void *dll_node)
{
    assert(NULL != dll_node);
    
    pthread_mutex_lock(&lock);
    DLLPushBack((dll_t *)dll_node, &val); 
    sem_post(&count);
    printf("size: %lu\n", DLLSize((dll_t*)dll_node));   
    pthread_mutex_unlock(&lock); 
    
    return NULL;   
} 
*/