#include "sort.h"
/**
 * swap_list - swap
 * @a: node
 * @b: node
 * Return: void
 */
void swap_list(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

}
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	tmp = (*list)->next;

	while (tmp)
	{
		current = tmp;
		tmp = tmp->next;

		while (current && current->prev)
		{
			if (current->prev->n > current->n)
			{
				swap_list(current->prev, current);
				if (current->prev == NULL)
					*list = current;
				print_list((const listint_t *) *list);
			}
			else
				current = current->prev;
		}
	}
}
