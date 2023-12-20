#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @list: A pointer to the head of the list
 * @a: First node to swap
 * @b: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - Sort a doubly linked list using Cocktail Shaker Sort
 * @list: A pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do
	{
		swapped = 0;

		for (listint_t *current = start; current ? current != end : 1; \
		current = current ? current->next : *list)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}

		if (!end)
			end = *list;

		for (listint_t *current = end->prev; current != start; \
		current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}

		start = start ? start->next : *list;

	} while (swapped);
}
