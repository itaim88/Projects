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
int CountingSort(const int *arr, size_t size, int min, int max, int *res);

/* complexity: O(n) */
int RadixSort(int *arr, size_t size, int num_of_bits);

#endif
