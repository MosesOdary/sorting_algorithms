#include "sort.h"



/**
 * SwapListNodes - Swap two nodes in a list.
 *
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void SwapListNodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}


/**
 * insertion_sort_list - sort list of integers in ascending order
 *
 * @list: The list
 *
Time Complexity: O(n^2)
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *i = NULL;
	listint_t *insertNode = NULL;
	listint_t *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		insertNode = i->prev;
		while (insertNode != NULL && i->n < insertNode->n)
		{
			SwapListNodes(list, &insertNode, i);
			print_list((const listint_t *)*list);
		}
	}
}
