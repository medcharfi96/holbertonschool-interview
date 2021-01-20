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
	while(pd->next != NULL)
	{
		i++;
		pd = pd->next;
	}
	return (i);
}

/**
 * copy_list - copy list in a array
 * @d: pointer to head of list
 * @len: lenght of list
 * Return: tab(mean true)
 */

int * copy_list(listint_t **d, int len)
{
	listint_t *ras = *d;
	int i = 0;
	int arry[len];

	while(i < len)
	{
		arry[i] = ras->n;
		ras = ras->next;
	}
	return (arry);
}
/**
 * s_palindrome - check  if is palindrome
 * @head: pointer to head of list
 * Return: 1(mean true)
 */

int is_palindrome(listint_t **head)
{
	int i = 0;
	int len = longueur_list(head);
	int tab[len];
	int bol = 1;

	if (len == 1)
	{
		return (0);
	}
	tab = copy_list(head, len);
	while (i <= len/2 && bol == 1)
	{
		if (tab[i] != tab[len - i - 1])
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