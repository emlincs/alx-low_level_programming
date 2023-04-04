#include "lists.h"

/**
 * insert_nodeint_at_index - A function that inserts node at given index
 * @head: A pointer to listint_t structure
 * @idx: The index of the list
 * @n: An integer data for new node
 * Return: The address to new node at specified index, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int k = 1;
	listint_t *latest_node, *prov;

	if (head == NULL)
		return (NULL);

	latest_node = malloc(sizeof(listint_t));
	if (latest_node == NULL)
	return (NULL);
	if (*head == NULL)
	{
		*head = latest_node;
		latest_node->next = NULL;
		latest_node->n = n;
		return (latest_node);
	}

	if (idx == 0)
	{
		latest_node->next = *head;
		latest_node->n = n;
		*head = latest_node;
		return (latest_node);
	}
	prov = *head;
	while (k < idx)
	{
	prov = prov->next;
	++k;
	}
	latest_node->n = n;
	latest_node->next = prov->next;
	prov->next = latest_node;
	return (latest_node);
}
