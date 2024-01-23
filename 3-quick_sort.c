#include "sort.h"

/**
 * swap - Swaps two integers
 * @i: pointer to the first number
 * @j: pointer to the second number
*/
void swap(int *array, size_t size, int i, int j)
{
	int temp;

	temp = array[j];
	if (array[i] != array[j])
	{
		array[j] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}

/**
 * partition - Implements the Lomuto partition scheme for Quick sort
 * @array: array of integers
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: The index of the pivot after partitioning
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i, j;

	i = low - 1;
	j = high;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, size, i, j);
		}
	}
	swap(array, size, i + 1, high);
	return (i + 1);
}

/**
 * quick_sort_recursive - Applies Quick sort to the array Recursively
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: the size of the array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low > high)
		return;

	size_t partition_index = partition(array, low, high, size);

	quick_sort_recursive(array, low, partition_index - 1, size);
	quick_sort_recursive(array, partition_index + 1, high, size);
}

/**
 * quick_sort - sorting algorithm
 * @array: the array to be sorted
 * @size: the size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
