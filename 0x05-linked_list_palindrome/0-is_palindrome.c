#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * is_palindrome - check  if is palindrome
 * @head: pointer to head of list
 * Return: 1(mean true)
 *
 */
int is_palindrome(listint_t **head)
{
	int i;
	int j;
	int len;
	int tab[1000];
	int bol;
	listint_t *pd = *head;

	i = 0;
	j = 0;
	bol = 1;
	len = 0;
	while (pd != NULL)
	{
		len++;
		pd = pd->next;
	}
	if (len == 1 || len == 0)
		return (1);
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
		return (0);
	return (1);
}