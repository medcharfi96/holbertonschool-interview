#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/*
 * longueur_list - give the list lenght
 * @p: copy of head
 * Return: int(mean true)
 *
 */
int longueur_list(listint_t **p)
{
	int i = 1;
	listint_t *pd = *p;

	while (pd->next != NULL)
	{
		i++;
		pd = pd->next;
	}
	return (i);
}

/**
 * s_palindrome - check  if is palindrome
 * @head: pointer to head of list
 * Return: 1(mean true)
 */

int is_palindrome(listint_t **head)
{
	int i = 0;
	int j = 0;
	int len = longueur_list(head);
	int tab[len];
	int bol = 1;

	if (len == 1)
	{
		return (0);
	}
	while (j < len)
	{
		tab[j] = (*head)->n;
		*head = (*head)->next;
		j++;
	}
	while ((i <= len / 2) && bol == 1)
	{
		if (tab[len - i - 1] != tab[i])
		{
			bol = 0;
		}
		else
		{
			i++;
		}
	}
	if (bol == 0)
	{
		return (0);
	}
	return (1);
}