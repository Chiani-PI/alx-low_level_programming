#include "lists.h"

/**
 * add_nodeint - Function adds a new node at the beginning of a listint_t list
 * @head: The pointer which points to the first node inside the list
 * @n: The data to be inserted into the fresh node
 *
 * Return: Tthe address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *fresh;

	fresh = malloc(sizeof(listint_t));
	if (!fresh)
		return (NULL);

	fresh->n = n;
	fresh->next = *head;
	*head = fresh;

	return (fresh);
}
