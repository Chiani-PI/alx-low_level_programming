#include "lists.h"

/**
 * free_listint - Function frees a linked listint_t list
 * @head: The linked listint_t list that is to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *brief;

	while (head)
	{
		brief = head->next;
		free(head);
		head = brief;
	}
}
