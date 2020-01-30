#ifndef __IP_H__
#define __IP_H__

#include <stddef.h> /* size_t */

#define ADDRESS_SIZE_IN_BYTES 4

typedef unsigned char ip_t[ADDRESS_SIZE_IN_BYTES];

/*
*converts ip_address to string of bits
*O(n)
*/
void IPConvertAddress(ip_t ip_address, unsigned char *ip_str);

#endif 

