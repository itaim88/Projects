/*********************************/
/*   			             	 */
/*   Data Structures             */
/*   Hash Table                  */
/*   Author: Itai Marienberg     */                  
/*			                   	 */
/*********************************/

#include <stdio.h> /* printf */
#include <assert.h> /* assert */
#include "utilities.h"

#include "hash.h"

size_t HashFunc(const void *data)
{
    return *(size_t *)data % 10;
}

int IsMatch(void *d1, void *d2)
{
    return (*(int *)d1 == *(int *)d2);
}

int PrintHashTable(void *d, void *param)
{
    UNUSED(param);
    printf("%d", *(int*)d);
    
    return 0;
}

void Test1()
{
    int one = 1;
    int two = 2;
    hash_t *hash_table = HashCreate(10, HashFunc, IsMatch);
    
    TEST(HashIsEmpty(hash_table) == 1, "IsEmpty (1)");
    TEST(HashSize(hash_table) == 0, "IsEmpty (1)");
    HashInsert(hash_table, &one);
    TEST(HashIsEmpty(hash_table) == 0, "IsEmpty (2)");
    TEST(HashSize(hash_table) == 1, "IsEmpty (2)");
    TEST(HashFind(hash_table, &one) == &one, "Find (1)");
    TEST(HashFind(hash_table, &two) == NULL, "Find (2)");
    HashForeach(hash_table, PrintHashTable, NULL);
    HashRemove(hash_table, &one);
    printf("\n");
    HashDestroy(hash_table);
}

int main()
{
    Test1();
    
    return 0;
}