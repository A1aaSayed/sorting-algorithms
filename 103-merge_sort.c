#include "sort.h"

/**
 * merge_sort - sorting algorithm
 * @array: pointer to array of integers
 * @size: the size of the array
*/
void merge_sort(int *array, size_t size)
{
	merge_sort_array(array, size);
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
		exit(EXIT_FAILURE);
	i = 0;
	j = left;
	k = 0;

	printf("\nMerging...\n");
	printf("[left]: ");
	print_array(array, left);
	printf("[right]: ");
	print_array(array + left, right);

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

	printf("[Done]: ");
	print_array(array, size);
	free(temp);
}

/**
 * merge_sort_array - Applies the merge sort algorithm to the array
 * @array: pointer to array of integers
 * @size: the size of the array
*/
void merge_sort_array(int *array, size_t size)
{
	size_t mid;

	if (size > 1)
	{
		mid = size / 2;
		merge_sort_array(array, mid);
		merge_sort_array(array + mid, size - mid);
		merge(array, mid, size - mid);
	}
}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
