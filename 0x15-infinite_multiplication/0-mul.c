#include <stdio.h>
#include "holberton.h"

/**
 * faute - error and exit
 *
 * Return: 0.
 */
void faute(void)
{
	int i;
	char err[] = "Error\n";

	for (i = 0; i <= 5; i++)
	{
		_putchar(err[i]);
	}
	exit(98);
}

/**
 * test - verifier si le nombre est valide
 * @argv: pointeur
 *
 * Return: int(mean true)
 */
int test(char *argv)
{
	int i = 0;

	while (argv[i] != 0)
	{
		if (argv[i] < 48 || argv[i] > 57)
			faute();
		i++;
	}
	return (i);
}

/**
 * aloc - louer la memoire
 * @l: int
 *
 * Return: pt(mean true)
 */
char *aloc(int l)
{
	char *val;
	int i = 0;

	val = malloc(sizeof(char) * (l + 1));
	if (val == NULL)
		faute();
	while (i <  l)
	{
		val[i] = '0';
		i++;
	}
	val[i] = '\0';
	return (val);
}

/**
 * ins - insertion dans un tableau
 * @res: tab
 * @x: int
 * @pos: int
 * Return: nothing(mean true)
 */
void ins(char *res, int x, int pos)
{
	x = x + (res[pos] - '0');
	while (x > 0)
	{
		res[pos] = (x % 10) + '0';
		x = x / 10;
		if (x == 0)
			break;
		pos--;
		x = x + (res[pos] - '0');
	}
}

/**
 * main - Main function
 * @argc : int
 * @argv: pointeur
 * Return: 0(mean true)
 */
int main(int argc, char *argv[])
{
	int longue, j, i, lg, lg2;
	char *result, *n1, *n2;

	if (argc != 3)
		faute();
	lg = test(argv[1]);
	lg2 = test(argv[2]);
	result = aloc(lg + lg2);
	n1 = argv[1];
	n2 = argv[2];
	for (longue = lg2 - 1; longue >= 0; longue--)
	{
		for (j = lg - 1; j >= 0; j--)
		{
			ins(result, ((n1[longue] - '0') * (n2[j] - '0')), longue + j + 1);
		}
	}
	for (i = 0; result[i] == '0' && result[i + 1]; i++)
	{
		;
	}
	printf("%s\n", &result[i]);
	free(result);
	return (0);
}