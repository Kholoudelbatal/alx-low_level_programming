#include "lists.h"

/**
 * sum_dlistint - sum dlist
 * @head: current head node adress
 *
 * Return: sum of dlist
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
