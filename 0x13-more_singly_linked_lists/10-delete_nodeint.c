#include "lists.h"

/**
 * delete_nodeint_at_index - Function deletes the node at index index
 * of a listint_t linked list
 * @head: A pointer to the 1st elem within the list
 * @index: The index of the node that is to be deleted
 *
 * Return: 1 success, else -1 on fail
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *brief = *head;
	listint_t *present = NULL;
	unsigned int j = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(brief);
		return (1);
	}

	while (j < index - 1)
	{
		if (!brief || !(brief->next))
			return (-1);
		brief = brief->next;
		j++;
	}

	present = brief->next;
	brief->next = present->next;
	free(present);

	return (1);
}
