#ifndef __IP_H__
#define __IP_H__

#include <stddef.h> /* size_t */

#define ADDRESS_SIZE_IN_BYTES 4

/*
*converts ip_address to string of bits
*O(n)
*/
void IPConvertAddress(unsigned char *ip_address, unsigned char *ip_str);

void IPConvertAddressToIP(unsigned char *ip_address, unsigned char *ip_str);

#endif 

