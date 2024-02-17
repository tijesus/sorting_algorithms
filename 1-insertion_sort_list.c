#include "sort.h"

/**
 * swap - Swaps two nodes in a doubly linked list.
 * @head: A pointer to the head of the doubly linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: A pointer to the second node to swap.
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*head = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - insertion sorting algorithm implementation
 * @list: list of insertion
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		prev = current->prev;

		while (prev != NULL && current->n < prev->n)
		{
			swap(list, prev, current);
			print_list(*list);
			prev = current->prev;
		}
	}
}
