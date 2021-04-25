#include "sort.h"

/**
 * swap - swaping between 2
 * @array: array of int
 * @a: int
 * @b: int
 */

void swap(int *array, size_t a, size_t b)
{
	int aux;

	aux = array[a];
	array[a] = array[b];
	array[b] = aux;
}

/**
 * heap - dscription
 * @array: array
 * @size: int
 * @i: int
 * @length: int
 *
 */

void heap(int *array, int size, int i, int length)
{
	int Maxi = i;
	int ymin = 2 * i + 2;
	int ysar = 2 * i + 1;


	if (array[Maxi] < array[ymin] && ymin < size)
		Maxi = ymin;

	if (array[Maxi] < array[ysar] && ysar < size)
		Maxi = ysar;

	if (Maxi != i)
	{
		swap(array, array[Maxi], array[i]);
		print_array(array, length);
		heap(array, size, Maxi, length);
	}
}

/**
 * heap_sort - sorting
 * @array: array
 * @size: int
 *
 */
void heap_sort(int *array, size_t size)
{
	int maxi;

	if (array == NULL || size <= 1)
		return;
	for (maxi = ((size - 1) / 2) ; maxi >= 0; maxi--)
		heap(array, size, maxi, size);
	for (maxi = (size - 1); maxi > 0; maxi--)
	{
		if (array[0] >= array[maxi])
		{
			swap(array, array[maxi], array[0]);
			print_array(array, size);
		}
		heap(array, maxi, 0, size);
	}
}