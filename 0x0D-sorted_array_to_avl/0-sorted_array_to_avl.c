#include "binary_trees.h"

/**
* sorted_array_to_avl - Function that builds an AVL tree from an array
* @array: is a pointer to the first element of the array to be converted
* @size: is the number of element in the array
* Return: a pointer to the root node of the created AVL tree, otherwise NULL
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *arbre;

	if (array == NULL || size <= 0)
		return (NULL);

	arbre = ajout_noeud(0, NULL, size - 1, array);
	return (arbre);
}


/**
* ajout_noeud - Function that build an AVL tree from an array
* @array: is a pointer to the first element of the array to be converted
* @start: the first element array index
* @end: the last element array to eval
* @parent: is a ponter to the parent of the new node
* Return: binary tree, otherwise NULL
*/
avl_t *ajout_noeud(size_t debut, avl_t *parent, size_t fin, int *array)
{
	size_t milieu;
	avl_t *arbre;

	if (debut > fin)
		return (NULL);

	milieu = (debut + fin) / 2;
	arbre = nvx_noeud(parent, array[milieu]);
	if (arbre == NULL)
		return (NULL);

	if (milieu != fin)
		arbre->right = ajout_noeud(array, milieu + 1, fin, arbre);

	if (milieu != debut)
		arbre->left = ajout_noeud(array, debut, milieu - 1, arbre);

	return (arbre);
}

/**
* nvx_noeud - Function to create a new node
* @parent: is a ponter to the array
* @n: size of the array
* Return: the pointer of the node, otherwise NULL
*/
avl_t *nvx_noeud(avl_t *parent, size_t n)
{
	avl_t *nouveau;

	nouveau = malloc(sizeof(avl_t));

	if (nouveau == NULL)
		return (NULL);

	nouveau->n = n;
	nouveau->right = NULL;
	nouveau->parent = parent;
	nouveau->left = NULL;
	return (nouveau);
}