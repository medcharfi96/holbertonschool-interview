#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * insert_node - function of inserting in a sorted list
 * @head: pointeur
 * @number: int
 * Return: list(mean  true)
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp2, *tmp;
	listint_t *new;

	tmp2 = tmp = *head;
	if (head == NULL)
		return (NULL);
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
	if (!*head)
	{
		new->next = NULL;
		*head = new;
		return(new);
	}
	if ((*head)->n >= new->n)
	{
		new->next = *head;
		*head = new;
		return(new);
	}
	while (tmp->next && tmp->n < number)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	new->next = tmp;
	tmp2->next = new;
	return (new);
}