#include "sort.h"


/**
 * swap_forward - This swaps the indexes forward as in normal
 * bubble sort
 * @current: The pointer to the current index in the iteration
 * @head: The head of the doubly linked list
 */

void swap_forward(listint_t **current, listint_t **head)
{
	listint_t *pholder;

	pholder = (*current)->next;
	if ((*current)->prev)
		((*current)->prev)->next = pholder;
	else
		*head = pholder;
	if (pholder->next)
		(pholder->next)->prev = *current;
	pholder->prev = (*current)->prev;
	(*current)->next = pholder->next;
	(*current)->prev = pholder;
	pholder->next = *current;
	print_list(*head);
}

/**
 * swap_backward - This swaps the indexes backward after initial
 * bubble sort
 * @current: The pointer to the current index in the iteration
 * @head: The head of the doubly linked list
 */
void swap_backward(listint_t **current, listint_t **head)
{
	listint_t *pholder;

	pholder = (*current)->prev;
	if (pholder->prev)
		(pholder->prev)->next = *current;
	else
		*head = *current;
	((*current)->next)->prev = pholder;
	pholder->next = (*current)->next;
	(*current)->prev = pholder->prev;
	(*current)->next = pholder;
	pholder->prev = *current;
	print_list(*head);
}



/**
 * cocktail_sort_list - This implement a cocktail
 * sort using doubly ljnked list
 * @list: The doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr, *shaker;
	size_t size = 0, sorted, i;

	if (list == NULL)
		return;
	ptr = *list;
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	if (size < 2)
		return;
	shaker = *list;
	for (i = 0; i < size; i++)
	{
		sorted = 0;
		while (shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_forward(&shaker, list);
				sorted = 1;
				continue;
			}
			shaker = shaker->next;
		}
		if (!sorted)
			return;
		shaker = shaker->prev;
		while (shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_backward(&shaker, list);
				continue;
			}
			shaker = shaker->prev;
		}
	}
}
