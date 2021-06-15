#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list with insertion sort
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *back, *forward;

	if (!list || !*list)
		return;
	if (!(*list)->next)
		return;
	back = *list;
	forward = (*list)->next->next;
	current = (*list)->next;
	while (1)
	{
		while (current->n < back->n)
		{
			if (current->next)
				current->next->prev = back;
			if (back->prev)
				back->prev->next = current;
			current->prev = back->prev;
			back->next = current->next, current->next = back;
			back->prev = current, back = current->prev;
			while ((*list)->prev)
				*list = (*list)->prev;
			print_list(*list);
			if (!back)
				break;
		}
		if (!forward)
			break;
		if (!forward->next)
		{
			current = forward;
			back = forward->prev, forward = forward->next;
		}
		else
		{
			current = forward->prev, back = current->prev;
			forward = forward->next, current = current->next;
			back = back->next;
		}
	}
}
