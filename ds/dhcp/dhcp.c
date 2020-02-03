/*********************************/
/*   			             	 */
/*   DHCP                        */
/*   Itai Marienberg	         */
/*   Last Updated                */
/*   Reviewed by                 */   
/*			                   	 */
/*********************************/

#include <stddef.h>    /* size_t */
#include <stdlib.h>    /* malloc */
#include <assert.h>    /* assert */
#include <string.h>    /* memcpy */
#include <math.h> 	   /* math   */

#include "trie.h" /* trie funcs */
#include "dhcp.h" /* dhcp funcs */

#define IP_ARRAY_SIZE 4
#define IP_SIZE 32
#define BITS_IN_BYTE 8
#define MIN 0
#define MAX 255

struct DHCP
{
	trie_t *trie;
	ip_t subnet_mask;
	size_t available_bits;
};

/*****************************************************************************/

static int ReservedAddresses(trie_t *trie);

/*****************************************************************************/

dhcp_t *DhcpCreate(ip_t subnet_mask, size_t subnet_mask_reserved_bits)
{
	dhcp_t *new_dhcp = NULL;
	int status = 0;

	assert(NULL != subnet_mask);

	new_dhcp = (dhcp_t *) malloc(sizeof(*new_dhcp));
	if (NULL == new_dhcp)
	{
		return new_dhcp;
	}

	memcpy(new_dhcp->subnet_mask, subnet_mask, (sizeof(ip_t)));
	new_dhcp->available_bits = (sizeof(ip_t) * BITS_IN_BYTE) -
										subnet_mask_reserved_bits;

	new_dhcp->trie = TrieCreate(new_dhcp->available_bits);
	if(NULL == new_dhcp->trie)
	{
		free(new_dhcp);
		new_dhcp = NULL;
		return NULL;
	}

	status = ReservedAddresses(new_dhcp->trie);
	if (0 < status)
	{
		return NULL;
	}

	return new_dhcp;								
}

void DhcpDetroy(dhcp_t *dhcp)
{
	assert(NULL != dhcp);

	TrieDestroy(dhcp->trie);

	free(dhcp);
	dhcp = NULL;
}

alc_status_t DhcpAllocIp(dhcp_t *dhcp, ip_t requested_ip, ip_t allocated_ip)
{
	bool_t is_available = TRUE;
	int status = 0;

	assert(NULL != dhcp);
	
	memcpy(allocated_ip, requested_ip, IP_ARRAY_SIZE);

	is_available = TrieIsAvailable(dhcp->trie, requested_ip);

	if (FALSE == is_available)
	{
		TreeFindNextAvail(dhcp->trie, allocated_ip);
	}

	status = TrieInsert(dhcp->trie, allocated_ip);

	if (0 != status)
	{
		return FAIL_TO_ALLOC;
	}	

	return (is_available == FALSE ? NOT_AS_REQUESTED : AS_REQUESTED);	
}

void DhcpFreeIp(dhcp_t *dhcp, ip_t ip_address)
{
	assert(NULL != dhcp);

	TrieFreeLeaf(dhcp->trie, ip_address);
}

size_t DhcpCountFree(const dhcp_t *dhcp)
{
	assert(NULL != dhcp);

	return (pow(2, dhcp->available_bits) - TrieCountOccupiedLeafs(dhcp->trie)); 	
}

/*************************************************************************/
static int ReservedAddresses(trie_t *trie)
{
	int status = 0;
	unsigned char ip1[IP_ARRAY_SIZE] = {MIN,MIN,MIN,MIN};
    unsigned char ip2[IP_ARRAY_SIZE] = {MAX,MAX,MAX,MAX};
    unsigned char ip3[IP_ARRAY_SIZE] = {MAX,MAX,MAX,MAX - 1};

    status += TrieInsert(trie, ip1);
    status += TrieInsert(trie, ip2);
    status += TrieInsert(trie, ip3);

    return status;
}
