#include "lists.h"

/**
 * find_listint_loop - Function finds the loop in a listint_t linked list
 * @head: listint_t linked list to be searched for
 *
 * Return: The address of the node where the loop starts, or NULL
 * if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *unhurried = head;
	listint_t *hurry = head;

	if (!head)
		return (NULL);
	while (unhurried && hurry && hurry->next)
	{
		hurry = hurry->next->next;
		unhurried = unhurried->next;
		if (hurry == unhurried)
		{
			unhurried = head;
			while (unhurried != hurry)
			{
				unhurried = unhurried->next;
				hurry = hurry->next;
			}
			return (hurry);
		}
	}
	return (NULL);
}
