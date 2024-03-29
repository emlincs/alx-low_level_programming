#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * delete_nodeint_at_index - A function that deletes the node at
 * specified index from list
 * @head: A pointer to listint_t structure
 * @index: The index of the node to delete
 * Return: 1 if succeeded, or -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prov, *delpoint;
	unsigned int k = 1;

	if (*head == NULL)
		return (-1);

	prov = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		free(prov);
	}
	else
	{
		while (k < index)
		{
			prov = prov->next;
			if (prov == NULL)
				return (-1);
			++k;
		}
		delpoint = prov;
		delpoint = delpoint->next;
		prov->next = delpoint->next;
		free(delpoint);
	}
	return (1);
}

