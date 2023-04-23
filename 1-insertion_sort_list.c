#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a linked list using insertion sort
 *
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *tmp, *curr, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	iterator = (*list)->next;
	while (iterator)
	{
		curr = iterator;
		prev = iterator->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			tmp = prev->prev;
			prev->prev = curr;
			prev->next = curr->next;
			curr->prev = tmp;
			curr->next = prev;

			if (prev->next)
			{
				prev->next->prev = prev;
			}

			if (tmp)
			{
				tmp->next = curr;
			}
			else
			{
				*list = curr;
			}

			prev = tmp;
			print_list(*list);
		}
		iterator = iterator->next;
	}
}
