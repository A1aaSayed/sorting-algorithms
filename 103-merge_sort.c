#include "sort.h"

/**
 * merge_sort - sorting algorithm
 * @array: pointer to array of integers
 * @size: the size of the array
*/
void merge_sort(int *array, size_t size)
{
	size_t mid;

	if (size > 1)
	{
		mid = size / 2;
		merge_sort(array, mid);
		merge_sort(array + mid, size - mid);
		merge(array, mid, size - mid);
	}
}

/**
 * merge - Merges two sorted subarrays into a single sorted array
 * @array: pointer to array of integers
 * @left: size of the left sub array
 * @right: size of the right sub array
*/
void merge(int *array, size_t left, size_t right)
{
	size_t size = left + right, i, j, k;
	int *temp = malloc(size * sizeof(int));

	if (!temp)
	{
		exit(EXIT_FAILURE);
	}
	i = 0;
	j = left;
	k = 0;

	while (i < left && j < size)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < left)
		temp[k++] = array[i++];
	while (j < size)
		temp[k++] = array[j++];

	for (size_t z = 0; z < size; ++z)
		array[z] = temp[z];

	print_array(array, size);
	free(temp);
}
