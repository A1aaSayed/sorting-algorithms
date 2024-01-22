#include "sort.h"

/**
 * bubble_sort - sorting algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				print_array(array, size);
			}
		}
	}
}

/**
 * swap - swap function
 * @arr: array
 * @i: first element
 * @j: second element
*/
void swap(int *arr, int i, int j)
{
	int temp = arr[i];

	arr[i] = arr[j];
}
