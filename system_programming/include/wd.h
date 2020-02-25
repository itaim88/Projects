#ifndef __WD_H__
#define __WD_H__

typedef enum status
{
	SUCCESS;
	MEMORY FAIL;
};

typedef struct WatchDog wd_t;

/* the function recives a pointer to a thread created by the user */
/* which will hold the tread to be joined in WDStop(). the first argument is the excute filename by path */
/* this function guards the process from failing postcall. if the process fails, it will be revived. */
/* Return value: 0 for success, 1 for fail. */
wd_t *WDStart(const char *filename, enum *status);

/* the function ends the reviving effect. */
/* it recievs the pointer to the thread created in WDStart() */
void WDStop(wd_t *wd);

#endif