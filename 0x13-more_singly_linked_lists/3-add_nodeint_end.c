#include "lists.h"

/**
 * add_nodeint_end - Function adds a new node at the end of a listint_t list
 * @head: The pointer to the first elem on the list
 * @n: The data to be inserted into the new element
 *
 * Return: Tthe address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *fresh;
	listint_t *brief = *head;

	fresh = malloc(sizeof(listint_t));
	if (!fresh)
		return (NULL);

	fresh->n = n;
	fresh->next = NULL;

	if (*head == NULL)
	{
		*head = fresh;
		return (fresh);
	}

	while (brief->next)
		brief = brief->next;

	brief->next = fresh;

	return (fresh);
}
