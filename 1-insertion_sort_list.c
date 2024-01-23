#include "sort.h"
/**
 * invalid_list - checks if the list has less than two element
 * @list: list to be checked
 * Return: true or false due to list status
 */
bool invalid_list(listint_t **list)
{
	if (!(*list)->next)
		return (true);
	return (false);
}

/**
 * insertion_sort_list - sorting algorithm
 * @list: the list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous;

	if (!list || !(*list) || invalid_list(list))
		return;

	for (current = (*list)->next; current; current = current->next)
	{
		int data = current->n;

		previous = current->prev;

		while (previous && previous->n > data)
		{
			swap_nodes(list, current, previous);
			print_list(*list);
			previous = current->prev;
		}
	}
}

/**
 * swap_nodes - swap two nodes
 * @list: the list of integers
 * @current: current node
 * @prev_node: previous node
*/
void swap_nodes(listint_t **list, listint_t *current, listint_t *prev_node)
{
	if (!current || !prev_node || current == prev_node)
	{
		return;
	}

	if (*list == current)
	{
		*list = prev_node;
	}
	else if (*list == prev_node)
	{
		*list = current;
	}

	if (prev_node->prev)
	{
		prev_node->prev->next = current;
	}

	if (current->next)
	{
		current->next->prev = prev_node;
	}

	prev_node->next = current->next;

	current->next = prev_node;

	current->prev = prev_node->prev;

	prev_node->prev = current;
}
