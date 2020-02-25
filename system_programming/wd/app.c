#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <time.h>

#include "wd.h"

int main(int argc, char *argv[])
{
    status_t status;
    time_t sleep_delay = 20;
    
    wd_t *wd = WDStart("/home/codesila/git/system_programming/watchdogtimer/outdebug/app", &status);
 
    while (sleep_delay)
    {
        sleep_delay = sleep(sleep_delay);
    }
    
    WDStop(wd);
    
    printf("App is alive!\n");
    
    sleep_delay = 3;
    
    while (sleep_delay)
    {
        sleep_delay = sleep(sleep_delay);
    }
    
    return 0;
}

