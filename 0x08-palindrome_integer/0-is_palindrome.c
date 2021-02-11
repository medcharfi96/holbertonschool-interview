#include "palindrome.h"
#include <stdlib.h>


/**
 * is_palindrome - fonction principale
 * @n: int
 * Return: 1(mean true)
*/

int is_palindrome(unsigned long n)
{
	unsigned long new_n, rev, reste;

	new_n = n;
	rev = 0;
	reste = 0;
	while (new_n != 0)
	{
		reste = new_n % 10;
		rev = rev * 10 + reste;
		new_n = new_n / 10;
	}
	if (n == rev)
		return (1);
	return (0);
}