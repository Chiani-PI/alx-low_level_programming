#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t lists
 * @h: A linked list of the type listint_t to be covered
 *
 * Return: The total number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t numeral = 0;

	while (h)
	{
		numeral++;
		h = h->next;
	}
	return (numeral);
}
