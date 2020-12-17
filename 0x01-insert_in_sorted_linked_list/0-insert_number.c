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
		return (NULL);
	}
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
		new->next = *head;
		*head = new;
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
	new->next = tmp;
	tmp2->next = new;

	return (new);
}