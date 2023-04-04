#include "lists.h"

/**
 * free_listint2 - A function that frees a list and sets head to NULL
 * @head: A pointer to listint_t structure
 * Return: Nothing.
*/
void free_listint2(listint_t **head)

{
	listint_t *prov;


	if (head == NULL)
		return;

	prov = *head;
	while (*head)
	{
		prov = *head;
		(*head) = (*head)->next;
		free(prov);
	}
	*head = NULL;
}
