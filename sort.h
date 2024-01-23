#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
bool invalid_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *current, listint_t *prev_node);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *i, int *j);
int partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, size_t left, size_t right);
void merge_sort_array(int *array, size_t size);


#endif
