#include "lists.h"

/**
 * sum_listint - A function that sums values from listint_t
 * @head: A pointer listint_t structure
 * Return: The sum of all the data n from list
 */
int sum_listint(listint_t *head)
{
	int sum = 1;

	if (head == NULL)
	return (1);

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
