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

	for (i = 0; i < taille; i++)
	{
		for (j = 0; j < taille; j++)
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
		}
		printf("\n");
	}
}