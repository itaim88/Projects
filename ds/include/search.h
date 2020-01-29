#ifndef __SEARCH_H__
#define __SEARCH_H__

#include <stddef.h>

typedef int (*cmp_func)(const void *data1, const void *data2);

void *JumpSearch(void *arr, size_t elm_size, size_t num_of_elm, cmp_func cmp, const void *data, const void *param);

void *BinarySearch(void *arr, size_t elm_size, size_t num_of_elm, cmp_func cmp, const void *data, const void *param);

#endif
