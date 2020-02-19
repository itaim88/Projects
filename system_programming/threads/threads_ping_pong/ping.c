#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

int main(int argc, char *argv[])
{
    size_t i = 0;
    sem_t *ping = {0};
    sem_t *pong = {0};
    int status = 0;
 
    ping = sem_open("/ping", O_CREAT, 0644, 0);
    pong = sem_open("/pong", O_CREAT, 0644, 0);   
       
    while (i < 5)
    {   
        write(1, "ping\n", 5);
        sem_post(pong);
        sem_wait(ping);

        ++i;
    }            
    
    status = sem_close(pong);
    if (0 != status)
    {
        exit(EXIT_FAILURE);
    }

    status = sem_close(ping);
    if (0 != status)
    {
       exit(EXIT_FAILURE);
    }
    
    
    status = sem_unlink("/ping");
    if (0 != status)
    {
       exit(EXIT_FAILURE);
    }

    status = sem_unlink("/pong");
    if (0 != status)
    {
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
