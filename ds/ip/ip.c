/*********************************/
/*   			             	 */
/*   Data Structures             */
/*   trie          */
/*   Author: Itai Marienberg      */
/*   Last Updated          */
/*   Reviewed by:          */   
/*			                   	 */
/*********************************/

#include <stdlib.h>
#include <assert.h>

#include "ip.h"

#define UNUSED(x) (void)(x)
#define m1 0xF0
#define m2 0xCC
#define m3 0xAA
#define BITS_IN_BYTE 8

static unsigned char ByteMirror(unsigned int x)
{
	x = ((x & m1) >> 4)  | ((x & ~m1) << 4);
	x = ((x & m2) >> 2)  | ((x & ~m2) << 2);
	x = ((x & m3) >> 1)  | ((x & ~m3) << 1);

	return x;
}

void IPConvertAddress(ip_t ip_address, unsigned char *ip_str)
{
	unsigned char j = 0 , i = 0;
	unsigned char *runner = ip_str;
	unsigned char mask = 1;
	unsigned char res = 0;

	assert(NULL != ip_address);

	while (i < ADDRESS_SIZE_IN_BYTES)
	{
		res = ByteMirror(ip_address[i]);

		j = 0;

		while (j < BYTS_IN_BYTE)
		{
			*runner = (mask & (res >> j)) + 48;
			++j;
			++runner;
		}

		++i;
	}

	*runner = '\0';
}




 
