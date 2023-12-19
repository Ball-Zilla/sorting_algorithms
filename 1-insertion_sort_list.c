#include "sort.h"

/**
 * swap_nodes - swaps the positions of two nodes
 * @ptr1: pointer to first node
 * @ptr2: pointer to second enode
 *
 * Return: nothing
 */
void swap_nodes(listint_t *ptr1, listint_t *ptr2)
{
	listint_t *prev = ptr1->prev;

	ptr1->next = ptr2->next;
	ptr1->prev = ptr2;
	if (ptr2->next)
		ptr2->next->prev = ptr1;
	ptr2->prev = prev;
	ptr2->next = ptr1;
	if (prev)
		prev->next = ptr2;
}

/**
 * insertion_sort_list - sorts a doubley linked list
 * @list: address of pointer to the head node
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *ptr = NULL;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		ptr = current;
		current = current->next;
		while (ptr && ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
			{
				swap_nodes(ptr->prev, ptr);
				if ((*list)->prev)
					*list = (*list)->prev;
				print_list(*list);
			}
			else
				break;
		}
	}
}
