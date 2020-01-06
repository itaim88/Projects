#ifndef __SORTS_H__
#define __SORTS_H__

#include <stddef.h>

/* complexity: O(n^2) */
void BubbleSort(int arr[], size_t length);

/* complexity: O(n^2) */
void InsertionSort(int arr[], size_t length);

/* complexity: O(n^2) */
void SelectionSort(int arr[], size_t length);

/* complexity: O(n) */
int CountingSort(int const *arr, size_t size, int min, int max, int *res);

#endif
