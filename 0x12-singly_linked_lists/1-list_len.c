#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Function returns the number of elements in a linked list_t list
 * @h: The pointer to the linked list_t list
 *
 * Return: The number of elements in pointer h
 */
size_t list_len(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		a++;
		h = h->next;
	}
	return (a);
}
