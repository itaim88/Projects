#include <stdio.h> /* printf() */
#include <pthread.h> /* pthread_ */
#include <semaphore.h> /* sem_ */

#define CONSUMERS 10
#define UNUSED(x) (void)(x)

int producer_work = 0;
char consumer_work[11] = "i`m working";
int threads_counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
sem_t producer_waits = {0};

static void *Producer(void *param)
{
    int i = 0;

    while (1)
    {
        UNUSED(param);

        ++producer_work;
        printf("%d\n", producer_work);

        pthread_mutex_lock(&mutex);

        while (CONSUMERS != threads_counter)
        {
            pthread_mutex_unlock(&mutex);
            pthread_mutex_lock(&mutex);

        }

        threads_counter = 0;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);

        for (i = 0; i < CONSUMERS; ++i)
        {
            sem_wait(&producer_waits);
        }

    }

    return NULL;
}

static void *Consumer(void *param)
{
    while (1)
    { 
        UNUSED(param);

        pthread_mutex_lock(&mutex);
        ++threads_counter;
        pthread_cond_wait(&cond, &mutex);
        printf("consumer: %s\n", consumer_work);
        pthread_mutex_unlock(&mutex);

        sem_post(&producer_waits);
    }

    return NULL;
}

int main()
{
    pthread_t prod_thread = {0},
    cons_thread[CONSUMERS] = {0};
    int status = 0;
    size_t i = 0;
    sem_init(&producer_waits, 0, 0);

    status = pthread_create(&prod_thread, NULL, Producer, NULL);
    if (0 != status)
    {
        printf("prod_thread create error");
        return 1;
    }

    for (i = 0; i < CONSUMERS; ++i)
    {
        status = pthread_create(&cons_thread[i], NULL, Consumer, &i);
        if (0 != status)
        {
            printf("cons_thread %ld create error\n", i);
            return 1;
        }
    }

    status = pthread_join(prod_thread, NULL);
    if (0 != status)
    {
        printf("prod_pthread create error \n");
        return 1;
    }

    for (i = 0; i < CONSUMERS; ++i)
    {
        status = pthread_join(cons_thread[i], NULL);
        if (0 != status)
        {
            printf("cons_pthread create error \n");
            return 1;
        }
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    sem_destroy(&producer_waits);

    return 0;
}




