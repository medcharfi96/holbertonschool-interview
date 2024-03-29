#include "search_algos.h"

/**
 * looking - recursion de div
 * @array: tab
 * @begin: int
 * @last: int
 * @value: int
 * Return: int(mean true)
 */
int looking(int *array, int begin, int last, int value)
{
	int mid, i;

	printf("Searching in array: ");
	for (i = begin; i < last; i++)
		printf("%i, ", array[i]);
	printf("%i\n", array[i]);

	mid = ((last - begin) / 2) + begin;

	if (array[mid] == value && array[mid - 1] != value)
		return (mid);

	if (begin == last)
		return (-1);

	if (array[mid] >= value)
		return (looking(array, begin, mid, value));

	if (array[mid] < value)
		return (looking(array, mid + 1, last, value));

	return (-1);
}


/**
 * advanced_binary - recherche de nbr
 * @array: tableau
 * @size: int
 * @value: int
 * Return: int(mean true)
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (looking(array, 0, (int)(size - 1), value));
}
