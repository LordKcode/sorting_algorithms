#include "sort.h"

/**
 * cocktail_sort_list - This implement a cocktail
 * sort using doubly ljnked list
 * @list: The doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr, *shaker, *pholder;
	int sorted = 0;

	if (*list == NULL)
		return;
	ptr = *list;
	shaker = *list;
	while (ptr->next)
	{
		sorted = 0;
		while (shaker->next)
		{
			pholder = shaker->next;
			if (shaker->n > pholder->n)
			{
				if (shaker->prev)
					(shaker->prev)->next = pholder;
				else
					*list = pholder;
				if (pholder->next)
					(pholder->next)->prev = shaker;
				pholder->prev = shaker->prev;
				shaker->next = pholder->next;
				shaker->prev = pholder;
				pholder->next = shaker;
				sorted = 1;
				print_list(*list);
				continue;
			}
			shaker = shaker->next;
		}
		if (!sorted)
			return;
		shaker = shaker->prev;
		while (shaker->prev)
		{
			pholder = shaker->prev;
			if (shaker->n < pholder->n)
			{
				if (pholder->prev)
					(pholder->prev)->next = shaker;
				else
					*list = shaker;
				(shaker->next)->prev = pholder;
				pholder->next = shaker->next;
				shaker->prev = pholder->prev;
				shaker->next = pholder;
				pholder->prev = shaker;
				print_list(*list);
				continue;
			}
			shaker = shaker->prev;
		}
		ptr = ptr->next;
	}
}
