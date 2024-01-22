#include "sort.h"

/**
 * swap - Swaps two integers
 * @i: pointer to the first number
 * @j: pointer to the second number
*/
void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * lomuto - Implements the Lomuto partition scheme for Quick sort
 * @array: array of integers
 * @low: starting index of the partition
 * @high: ending index of the partition
 * Return: The index of the pivot after partitioning
*/
int lomuto(int *array, size_t low, size_t high)
{
	size_t i, j;

	int pivot = array[high];

	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			++i;
			swap(&array[i], &array[j]);
			print_array(array, high - low + 1);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, high - low + 1);
	return (i + 1);
}

/**
 * quick_sort_recursive - applies Quick sort Recursively
 * @array: the array
 * @low: starting index of the partition
 * @high: ending index of the partition
*/
void quick_sort_recursive(int *array, size_t low, size_t high)
{
	size_t partition;

	if (low < high)
	{
		partition = lomuto(array, low, high);
		quick_sort_recursive(array, low, partition - 1);
		quick_sort_recursive(array, partition + 1, high);
	}
}

/**
 * quick_sort - sorting algorithm
 * @array: the array to be sorted
 * @size: the size of the array
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1);
}
