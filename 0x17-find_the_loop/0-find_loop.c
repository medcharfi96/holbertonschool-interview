#include "lists.h"

/**
 * find_listint_loop - fonctionde  trouver une boucle
 * @head: pointeur
 * Return: pointeur(mean true)
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first, *second;

	if (head == NULL)
		return (0);

	first = head->next;
	second = head->next->next;
	while (first && second && second->next)
	{
		first = first->next;
		second = second->next->next;
		if (first == second)
		{
			while (first != second)
			{
				first = first->next;
				second = second->next;
			}
			return (first);
		}
	}
	return (0);
}
