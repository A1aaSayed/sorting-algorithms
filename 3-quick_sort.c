#include "sort.h"

/**
 * swap - Swaps two integers
 * @array: pointer to array of integers
 * @size: size of the array
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
 * @size: size of the array
 * @low: starting index of the partition
 * @high: ending index of the partition
 * Return: The index of the pivot after partitioning
*/
int partition(int *array, size_t size, int low, int high)
{
	int i = low - 1, j = low;

	for (; j < high; j++)
	{
		if (array[j] < array[high])
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
 * @size: the size of the array
 * @low: starting index
 * @high: ending index
*/
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low > high)
		return;

	pivot = partition(array, size, low, high);

	quick_sort_recursive(array, size, low, pivot - 1);
	quick_sort_recursive(array, size, pivot + 1, high);
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
	quick_sort_recursive(array, size, 0, size - 1);
}
