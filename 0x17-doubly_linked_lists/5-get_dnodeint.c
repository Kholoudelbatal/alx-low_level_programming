#include "lists.h"

/**
 * get_dnodeint_at_index - get dnode at index
 * @head: current head adress
 * @index: node index
 *
 * Return: node  adress at index
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}
	return (NULL);
}
