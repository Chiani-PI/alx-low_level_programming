#include "lists.h"

/**
 * reverse_listint - Function reverses a linked listint_t list
 * @head: A pointer to the 1st node within the linked listint_t list
 *
 * Return: A pointer to the 1st node within the newly reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;

	return (*head);
}
