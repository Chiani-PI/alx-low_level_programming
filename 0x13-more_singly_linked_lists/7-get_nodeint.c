#include "lists.h"

/**
 * get_nodeint_at_index - Function returns the nth node of listint_t linkd list
 * @head: The first node in the listint_t linked list
 * @index: The index of the node, starting at 0
 *
 * Return: pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j = 0;
	listint_t *brief = head;

	while (brief && j < index)
	{
		brief = brief->next;
		j++;
	}

	return (brief ? brief : NULL);
}
