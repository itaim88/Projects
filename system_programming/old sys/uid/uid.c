/*******************************************************************************
-Ws UID
-Itai Marienberg
-Dec 10 2019    
*******************************************************************************/

#include <time.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>

#include "uid.h"

ilrd_uid_t UIDCreate()
{
	ilrd_uid_t new_id = {0};
	static size_t count = 0UL;

	new_id.time_stamp = time(NULL);
	new_id.counter = count++;
	new_id.process_id = getpid();

	return new_id;
}

int UIDIsBad(ilrd_uid_t new_id)
{
	return(0 == new_id.counter || 0 == new_id.time_stamp || 
											0 == new_id.process_id);
}

int UIDIsSame(ilrd_uid_t uid1, ilrd_uid_t uid2)
{
	return (uid1.time_stamp == uid2.time_stamp && uid1.counter == 
						uid2.counter && uid1.process_id == uid2.process_id);
}
