
#include <sys/types.h> /* pid_t */
#include <stdlib.h>    /* malloc () */
#include <unistd.h>    /* getpid() */
#include <pthread.h>   /* pthread_create () */
#include <fcntl.h>     /* For O_* constants */
#include <sys/stat.h>  /* For mode constants */
#include <semaphore.h> /* sem_open () */
#include <signal.h>    /* sigaction () */
#include <assert.h>    /* assert() */
#include <stdio.h>     /* printf () */
#include <string.h>    /* strcpy () */

#include "scheduler.h"
#include "wdhelper.h"

pid_t updated_id = {0};
sem_t *sem_is_wd_up = NULL;

static status_t SemaphoreInitIMP(wd_t *wrap, status_t *status)
{
    if (SEM_FAILED == (wrap->sem_p1 = sem_open("/sem_wd_ready", O_CREAT, 0644, 0)))
    {
        *status = FAIL;
        return FAIL;
    }
    
    if (SEM_FAILED == (wrap->sem_p2 = sem_open("/sem_app_ready", O_CREAT, 0644, 0)))
    {  
        *status = FAIL;
        return FAIL;
    }
 
    if (SEM_FAILED == (sem_is_wd_up = sem_open("/sem_is_wd_up", O_CREAT, 0644, 0)))
    {
        *status = FAIL;
        return FAIL;
    }
    return SUCCESS;    
}

wd_t *WDStart(const char *filename, status_t *status)
{
    wd_t *wrap = NULL;
    pid_t pid = {0};
    int sem_wd_up_value = 0;
    
    assert(NULL != filename);
    assert(NULL != status);
    
    wrap = malloc(sizeof(*wrap));
    if (NULL == wrap)
    {
        return NULL; 
    }
    
    wrap->status = WDInit(wrap);
    if (FAIL == wrap->status)
    {
        free(wrap); wrap = NULL;
        return wrap;
    }     

    if (FAIL == SemaphoreInitIMP(wrap, status))
    {
        return NULL;    
    }

    strcpy(wrap->filename, "/home/codesila/git/system_programming/watchdoghelper/outdebug/main_wd_out");
    
    sem_getvalue(sem_is_wd_up, &sem_wd_up_value);
    if (0 == sem_wd_up_value)
    {
        if (0 == (pid = fork()))
        {
            execl(wrap->filename, wrap->filename, NULL);
        }    
        else
        {
            updated_id = pid;
        }
        sem_post(sem_is_wd_up);
    }
    
    else
    {
        updated_id = getppid();
    }
            
    if (0 != pthread_create(&(wrap->thread), NULL, &WDSchedulerRun, wrap))
    {
        *status = FAIL;
        return NULL;
    }
    
    return wrap;
}

void WDStop(wd_t *wd)
{
    time_t start = time(NULL);
    time_t seconds = 10;   
    time_t end = start + seconds;
    int sval = 0;
    
    assert(NULL != wd);

    printf("counting down %ld seconds...\n", seconds);
    while (!sval && (start < end))
    {
        printf("timeout loop\n");
        start = time(NULL);
        sem_getvalue(sem_stop_flag, &sval);
        printf("updated_id for SIGUSR2 %d\n", updated_id);
        kill(updated_id, SIGUSR2);
    }

    if (0 == sval)
    {
        sem_post(sem_stop_flag);
        kill(updated_id, SIGTERM);    
    }
    
    sem_close(wd->sem_p1);
    sem_close(wd->sem_p2);
    sem_close(sem_is_wd_up);
    
    sem_unlink("/sem_stop_flag");
    sem_unlink("/sem_wd_ready");
    sem_unlink("/sem_app_ready");
    sem_unlink("/sem_is_wd_up");
    
    printf("pthread join line\n"); 
    pthread_join(wd->thread, NULL);
    
    free(wd); wd = NULL;
}