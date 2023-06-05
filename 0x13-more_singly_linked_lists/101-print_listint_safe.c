#include "lists.h"
#include <stdio.h>

size_t loop_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * loop_listint_len - Function counts the number of rare nodes
 * within the looped listint_t linked list
 * @head: The pointer to the head of listint_t which is to be evaluated
 *
 * Return: For unlooped list 0, else number of the rare nodes in the list
 */
size_t loop_listint_len(const listint_t *head)
{
	const listint_t *turtle, *harre;
	size_t nnodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	turtle = head->next;
	harre = (head->next)->next;

	while (harre)
	{
		if (turtle == harre)
		{
			turtle = head;
			while (turtle != harre)
			{
				nnodes++;
				turtle = turtle->next;
				harre = harre->next;
			}

			turtle = turtle->next;
			while (turtle != harre)
			{
				nnodes++;
				turtle = turtle->next;
			}
			return (nnodes);
		}
		turtle = turtle->next;
		harre = (harre->next)->next;
	}
	return (0);
}

/**
 * print_listint_safe - Function safely prints a linked listint_t list
 * @head: The pointer to the head of the listint_t list
 *
 * Return: The total number of nodes in the listint_t linked list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nnodes, ind = 0;

	nnodes = loop_listint_len(head);

	if (nnodes == 0)
	{
		for (; head != NULL; nnodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (ind = 0; ind < nnodes; ind++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nnodes);
}
