#include "sort.h"
/**
 * countSort - sorting tab
 * @ZA: int
 * @size: int
 * @array: array
 * Return: Nothing (void)
 */
void countSort(int ZA, int size, int *array)
{
	int *res = malloc(sizeof(int) * size);
	int i;
	int vara[10] = {0};

	if (res == NULL)
		return;
	for (i = 0; i < size; i++)
		vara[(array[i] / ZA) % 10]++;
	for (i = 1; i < 10; i++)
		vara[i] += vara[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		res[vara[(array[i] / ZA) % 10] - 1] = array[i];
		vara[(array[i] / ZA) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = res[i];
	free(res);
}

/**
 * radix_sort - main FN
 * @array: tab
 * @size: size_t
 * Return: Nothing (void)
 */
void radix_sort(int *array, size_t size)
{
	int x, max;
	size_t i;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	for (x = 1; max / x > 0; x *= 10)
	{
		countSort(x, size, array);
		print_array(array, size);
	}
}
