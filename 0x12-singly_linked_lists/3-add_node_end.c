#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Function adds a new node at the end of a list_t list
 * @head: A double pointer to list_t
 * @str: String to be inputed into the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newnode;
	list_t *tempo = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	newnode = malloc(sizeof(list_t));

	if (!newnode)
		return (NULL);

	newnode->str = strdup(str);
	newnode->len = len;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}

	while (tempo->next)
		tempo = tempo->next;

	tempo->next = newnode;

	return (newnode);
}
