#include "binary_trees.h"
/**
 * binary_tree_node - add a head
 *
 * @parent: pointeur
 * @value: int
 * Return: pointeur (mean true)
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nouveau;

	nouveau = malloc(sizeof(binary_tree_t) * 1);
	if (nouveau == NULL)
	{
		return (NULL);
	}
	nouveau->parent = parent;
	nouveau->left = NULL;
	nouveau->right = NULL;
	nouveau->n = value;
	return (nouveau);
}