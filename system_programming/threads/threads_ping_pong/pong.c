#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

int main(int argc, char *argv[])
{
    size_t j = 0;
    sem_t *ping = {0};
    sem_t *pong = {0};
    int status = 0;
 
    ping = sem_open("/ping", O_CREAT, 0644, 0);  
    pong = sem_open("/pong", O_CREAT, 0644, 0);
     
    while (j < 5)
    {   
        sem_wait(pong);
        write(1, "pong\n", 5);
        sem_post(ping);  
        ++j;
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
    
    
    return 0;
}
