#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - function of inserting in a sorted list
 * @head: pointeur
 * @number: int
 * Return: list(mean  true)
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp2 = *head;
	listint_t *tmp = *head;
	listint_t *new;

	if (!head)
	{
		return (0);
	}
	if (head == NULL)
	{
		return (0);
	}
	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	else
	{
		new->next = NULL;
	    new->n = number;
	}

	if ((*head)->n >= new->n)
	{
		new->next = *head;
		*head = new;
	}
	while (tmp->n < number)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	printf("ras zebiiiiiiiiiiiiiiiii");
	printf("%d", tmp->n);
	printf("%d", tmp2->n);

	printf("ras zebiiiiiiiiiiiiiiiii");
	new->next = tmp;
	tmp2->next = new;

	return (new);
}