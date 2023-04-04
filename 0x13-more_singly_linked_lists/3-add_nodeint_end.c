#include "lists.h"

/**
 * add_nodeint_end - A function that adds a new node to the end of list
 * @head: A pointer to list structure
 * @n: An integer data to put into the new node
 * Return: The address of the new element, or NULL on failure
*/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *latest_point, *prov;

	latest_point = malloc(sizeof(listint_t));
	if (latest_point == NULL)
		return (NULL);

	latest_point->n = n;
	if (*head == NULL)
	{
		latest_point->next = *head;
		*head = latest_point;
	}
	else
	{
		latest_point->next = NULL;
		prov = *head;
		while (prov->next)
		prov = prov->next;
		prov->next = latest_point;
	}
	return (latest_point);
}
