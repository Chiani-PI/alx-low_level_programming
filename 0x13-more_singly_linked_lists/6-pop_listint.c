#include "lists.h"

/**
 * pop_listint - Function deletes the head node of a linked listint_t list
 * @head: The pointer to the first element in the linked listint_t list
 *
 * Return: The head node’s data (n), otherwise 0 if the linked list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *brief;
	int numeral;

	if (!head || !*head)
		return (0);

	numeral = (*head)->n;
	brief = (*head)->next;
	free(*head);
	*head = brief;

	return (numeral);
}
