/*********************************/
/*    cbuffer_thread             */
/*                               */
/*********************************/
#include <unistd.h>  /* sleep */
#include <pthread.h> /* pthread_create */
#include <semaphore.h> /* sem_init */
#include <stdio.h> /* printf */
#include <assert.h>  /* assert */


#include "./../../include/cbuffer_thread.h" /* API functions */

#define FAIL 1
#define PRODUCERS 100
#define CONSUMERS 100
#define CAPACITY 40

#define GREEN "\033[;032m"
#define RED   "\033[;031m"
#define RESET "\033[0m"

#define UNUSED(x) (void)(x)

#define RUN_TEST(test)\
{\
  if(test)\
  {\
    printf(GREEN);\
    printf("SUCCESS\n");\
    printf(RESET);\
  }\
  else\
  {\
    printf(RED);\
    printf("FAIL \n");\
    printf(RESET);\
  }\
}


enum
{
    FREE,
    LOCK
};


pthread_mutex_t lock = {0};
pthread_mutex_t lock2 = {0};
int val = 3;
sem_t write_sem = {0};
sem_t read_sem = {0};
cbuffer_t *new_cb = NULL;

void *Consumer(void *new_cb);
void *Producer(void *new_cb);
  

int main()
{
    size_t i = 0;
    int status = 0;

    pthread_t producers[PRODUCERS];
    pthread_t consumers[CONSUMERS];
    
    pthread_mutex_init(&lock, NULL);
    pthread_mutex_init(&lock2, NULL);
    sem_init (&write_sem, 0, CAPACITY);
    sem_init (&read_sem, 0, 0);

    new_cb = CBufferCreate(CAPACITY);

    for (i = 0; i < PRODUCERS; ++i)
    {
        status = pthread_create(&(producers[i]), NULL, Producer, new_cb);
        if (0 != status)
        {
            printf("ERROR\n");
            return FAIL;
        }
    }
    
    for (i = 0; i < CONSUMERS; ++i)
    {
        status = pthread_create(&(consumers[i]), NULL, Consumer, new_cb);
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
    
    pthread_mutex_destroy(&lock);
    pthread_mutex_destroy(&lock2);
    sem_destroy(&write_sem);
    sem_destroy(&read_sem);
    CBufferDestroy(new_cb);
    
    return 0;
}

void *Producer(void *new_cb)
{
    assert(NULL != new_cb);
    
    sem_wait(&write_sem);
    pthread_mutex_lock(&lock); 

    CBufferWrite(new_cb ,val);
    printf("W\n");
    sem_post(&read_sem);
    pthread_mutex_unlock(&lock);
    
    return NULL;   
} 
void *Consumer(void *new_cb)
{
    assert(NULL != new_cb);
    
    sem_wait(&read_sem);
    pthread_mutex_lock(&lock2); 
  
    CBufferRead(new_cb);
    printf("R\n");
    sem_post(&write_sem);
    pthread_mutex_unlock(&lock2);
    
    return NULL;
} 


