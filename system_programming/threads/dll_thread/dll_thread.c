#include <stdio.h>   /* printf */
#include <unistd.h>  /* sleep */
#include <assert.h>  /* assert */
#include <pthread.h> /* pthread_create */

#include "./../../../ds/include/dllist.h"

#define FAIL 1
#define PRODUCERS 50
#define CONSUMERS 10

enum
{
    FREE,
    LOCK
};

pthread_mutex_t lock;
int val = 1;

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
    
    new_dll = DLLCreate();
    if (NULL == new_dll)
    {
        return FAIL;
    }
    
    for (i = 0; i < PRODUCERS; ++i)
    {
        status = pthread_create(&(producers[i]), NULL, Producer, new_dll);
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
    
    return 0;
}


void *Producer(void *dll_node)
{
    assert(NULL != dll_node);
    
    pthread_mutex_lock(&lock);
    DLLPushBack((dll_t *)dll_node, &val); 
    printf("size: %lu\n", DLLSize((dll_t*)dll_node));   
    pthread_mutex_unlock(&lock); 
    
    return NULL;   
}

void *Consumer(void *dll_node)
{
    assert(NULL != dll_node);
    
    while (DLLIsEmpty((dll_t*)dll_node));
    
    pthread_mutex_lock(&lock); 

    if (!DLLIsEmpty((dll_t*)dll_node))
    {    
        printf("%d\n", *(int*)DLLPopFront((dll_t *)dll_node)); 
    }  

    pthread_mutex_unlock(&lock);
    
    return NULL;
}

