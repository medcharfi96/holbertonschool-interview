#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *check_cycle - fonction de verification de cycle
 *@list: int list
 *Return: 1(mean  true)
 */

int check_cycle(listint_t *list)
{
	listint_t *list_f, *list_s;

	if (list->next == NULL)
		return (0);

	list_f = list;
	list_s = list;

	while (list_s != NULL && list_s->next && list_f != NULL)
	{
		list_s = list_s->next->next;
		list_f = list_f->next;
		if (list_s == list_f)
			return (1);
	}
	return (0);
}
