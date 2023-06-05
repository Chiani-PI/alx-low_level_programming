#include "lists.h"

/**
 * print_listint - Function prints all the elem of a linked, listint_t, list
 * @h: The linked list of the type 'listint_t' to be printed
 *
 * Return: The total number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t numeral = 0;

	while (h)
	{
		printf("%d\n", h->n);
		numeral++;
		h = h->next;
	}
	return (numeral);
}
