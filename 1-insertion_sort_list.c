#include "sort.h"

/**
	* swap_nodes - swaps nodes doubly linked list
	* @head: doubly linked list head pointer
	* @lhs: first node to swap
	* @rhs: second node to swap
	*/
void swap_nodes(listint_t **head, listint_t **lhs, listint_t *rhs)
{
	(*lhs)->next = rhs->next;
	if (rhs->next)
		rhs->next->prev = *lhs;

	rhs->prev = (*lhs)->prev;
	rhs->next = *lhs;

	if ((*lhs)->prev)
		(*lhs)->prev->next = rhs;
	else
		*head = rhs;

	(*lhs)->prev = rhs;
	*lhs = rhs->prev;
}

/**
	* insertion_sort_list - insertion sort of doubly linked list
	* @list: source list to be sorted
	*/
void insertion_sort_list(listint_t **list)
{
	listint_t *next, *prev, *current;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		prev = current->prev;
		while (prev && current->n < prev->n)
		{
			swap_nodes(list, &prev, current);
			print_list(*list);
		}
		current = next;
	}
}
