#include <stdio.h>
#include "lists.h"

/**
 * print_list - Function prints all the elements of a list_t list
 * @h: The pointer to the list_t list to be printed
 *
 * Return: The number of node
 */
size_t print_list(const list_t *h)
{
	size_t s = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
			h = h->next;
			s++;
	}

	return (s);
}
