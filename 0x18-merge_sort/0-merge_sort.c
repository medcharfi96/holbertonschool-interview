#include "sort.h"

/**
 * merging - fonde é sous tablea *
 * @array: TABLEAU
 * @sous_tab: sous_tab
 * @debut: int
 * @mid: INT
 * @fin: int
 * Return: Nothing(void)
 */
void merging(int *array, int *sous_tab, int debut, int mid, int fin)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + debut, mid - debut);
	printf("[right]: ");
	print_array(array + mid, fin - mid);

	for (i = debut, j = mid, k = 0; i < mid && j < fin; k++)
		if (array[i] < array[j])
			sous_tab[k] = array[i++];
		else
			sous_tab[k] = array[j++];
	while (i < mid)
		sous_tab[k++] = array[i++];
	while (j < fin)
		sous_tab[k++] = array[j++];
	for (i = debut, k = 0; i < fin; i++)
		array[i] = sous_tab[k++];

	printf("[Done]: ");
	print_array(array + debut, fin - debut);
}

/**
 * sub_tri - division de tableau
 * @array: tableau
 * @sous_tab: sous_tab
 * @debut: int
 * @fin: int
 * Return: Nothing(void)
 */
void sub_tri(int debut, int fin, int *array, int *sous_tab)
{
	int mid, taille;

	taille = fin - debut + 1;
	if (taille > 2)
	{
		mid = (fin - debut) / 2 + debut;
		sub_tri(debut, mid, array, sous_tab);
		sub_tri(mid, fin, array, sous_tab);
		merging(array, sous_tab, debut, mid, fin);
	};
}

/**
 * merge_sort - le tri
 * @array: tableau
 * @size: int
 * Return: Nothing(void)
 */
void merge_sort(int *array, size_t size)
{
	int *sous_tab;

	if (size < 2 || array == NULL)
		return;
	sous_tab = malloc(sizeof(int) * size);
	sub_tri(0, size, array, sous_tab);
	free(sous_tab);
}
