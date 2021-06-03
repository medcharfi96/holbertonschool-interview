#include "lists.h"

/**
 * find_listint_loop - fonctionde  trouver une boucle
 * @head: pointeur
 * Return: pointeur(mean true)
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *premier, *deux;

	if (head == NULL)
		return (0);

	premier = head->next;
	deux = head->next->next;
	while (premier && deux && deux->next)
	{
		premier = premier->next;
		deux = deux->next->next;
		if (premier == deux)
		{
			while (premier != deux)
			{
				premier = premier->next;
				deux = deux->next;
			}
			return (deux);
		}
	}
	return (0);
}
