#include "lists.h"

/**
 * find_listint_loop - fonctionde  trouver une boucle
 * @head: pointeur
 * Return: pointeur(mean true)
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *premier, *deux, *jamil;

	if (head == NULL)
		return (0);

	premier = head->next;
	deux = head->next->next;
	jamil = head;
	while (premier && deux && deux->next)
	{
		premier = premier->next;
		deux = deux->next->next;
		if (premier == deux)
		{
			while (jamil != deux)
			{
				jamil = jamil->next;
				deux = deux->next;
			}
			return (jamil);
		}
	}
	return (0);
}
