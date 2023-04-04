#include "lists.h"

/**
 * free_listint -  A function that frees a linked list
 * @head: A pointer to a listint_t structure
 * Return: Nothing
 */

void free_listint(listint_t *head)
{
	listint_t *prov;

	while (head)
	{
		prov = head;
		head = head->next;
		free(prov);
	}
	free(head);
}
