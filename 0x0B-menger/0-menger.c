#include "menger.h"

/**
 * menger - afichage 2D
 * @level: int
 *
 * Return: /0(mean true)
*/

void menger(int level)
{
	int i, j, taille, hauteur, larguere;
	char style;

	i = 0;
	j = 0;
	if (level < 0)
	{
		return;
	}
	else if (level == 0)
	{
		printf("#\n");
		return;
	}
	if (level > 0)
	{
	taille = pow(3, level);
	}

	while (i < taille)
	{
		j = 0;
		while (j < taille)
		{
			larguere = j;
			hauteur = i;
			style = '#';
			while (hauteur > 0)
			{
				if (hauteur % 3 == 1 && larguere % 3 == 1)
					style = ' ';
				hauteur = hauteur / 3;
				larguere = larguere / 3;
			}
			printf("%c", style);
			j++;
		}
		printf("\n");
		i++;
	}
}