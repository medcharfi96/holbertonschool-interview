#include "binary_trees.h"

/**
 * heap_extract - extract
 * @root: pointeur
 * Return: int(mean true)
 */
int heap_extract(heap_t **root)
{
	int count, n, size;
	heap_t **tab;

	if (root == NULL || *root == NULL)
		return (0);
	n = (*root)->n;
	size = taille_arb(*root);
	tab = malloc(1024 * sizeof(heap_t *));
	if (tab == NULL)
		return (0);
	for (count = 0; count < size; count++)
		tab[count] = NULL;
	vers_tab(tab, *root, 0);
	if (tab[size - 1] == (*root))
	{
		free(tab);
		free(*root);
		*root = NULL;
		return (n);
	}
	(*root)->n = tab[size - 1]->n;
	if (tab[size - 1]->parent->left == tab[size - 1])
		tab[size - 1]->parent->left = NULL;
	else
		tab[size - 1]->parent->right = NULL;
	free(tab[size - 1]);
	free(tab);
	reconstruire(*root);
	return (n);
}

/**
 * taille_arb - taille de larbe
 * @root: pointeur
 * Return: int(mean true)
 */
int taille_arb(heap_t *root)
{
if (!root)
	return (0);
	else
		return (taille_arb(root->left) + 1 + taille_arb(root->right));

}
/**
 * vers_tab - changer vers tableau
 * @tab: tablau
 * @root: pointeur
 * @ind: int
 */
void vers_tab(heap_t **tab, heap_t *root, int ind)
{
	tab[ind] = root;
	if (root)
	{
		vers_tab(tab, root->left, (ind * 2) + 1);
		vers_tab(tab, root->right, (ind * 2) + 2);
	}
}

/**
 * reconstruire - rreconstruire
 * @node: heap_t
 */
void reconstruire(heap_t *node)
{
	int aux;

	if (node->left == NULL)
	{
		return;
	}
	else if (node->right == NULL || node->left->n >= node->right->n)
	{
		if (node->n < node->left->n)
		{
			aux = node->n;
			node->n = node->left->n;
			node->left->n = aux;
		}
		reconstruire(node->left);
	}
	else if (node->left->n < node->right->n)
	{
		if (node->n < node->right->n)
		{
			aux = node->n;
			node->n = node->right->n;
			node->right->n = aux;
		}
		reconstruire(node->right);
	}
}
