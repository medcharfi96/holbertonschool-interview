#include "binary_trees.h"

/**
 * treekos - check
 * @n: int
 * @tree: pointeur
 * @F: int
 * Return: int(mean true)
 */

int treekos(int n, const binary_tree_t *tree, int F)
{
	int R_L = 1, R_R = 1;

	if (tree->left)
		R_L = treekos(n, tree->left, F);
	if (tree->right)
		R_R = treekos(n, tree->right, F);

	if (F && tree->n >= n)
		return (0);
	else if (!F && tree->n <= n)
		return (0);

	return (R_L * R_R);
}
/**
 * bntr_bst - check is Binary search tree
 * @tree: pointeur
 * Return: int(mean true)
 */
int bntr_bst(const binary_tree_t *tree)
{
	int R_L = 1, R_R = 1;

	if (!tree)
		return (0);

	if (tree->left)
	{
		if (!treekos(tree->n, tree->left, 1))
			return (0);
		R_L = bntr_bst(tree->left);
	}
	else
		return (1);

	if (tree->right)
	{
		if (!treekos(tree->n, tree->right, 0))
			return (0);
		R_R = bntr_bst(tree->right);
	}
	else
		return (1);

	return (R_R * R_L);
}

/**
 * giv_h - calcule hight
 * @t: pointeur
 * Return: int(mean true)
 */

size_t giv_h(const binary_tree_t *t)
{
	int l_height1;
	int r_height1;

	if (!t)
		return (0);

	if (t->left)
		l_height1 = 1 + giv_h(t->left);
	else
		l_height1 = 0;
	if (t->right)
		r_height1 = 1 + giv_h(t->right);
	else
		r_height1 = 0;

	if (l_height1 > r_height1)
		return (l_height1);
	else
		return (r_height1);
}

/**
 * chek_b - check  hight
 * @t: pointeur
 * Return: int(maen true)
 */
int chek_b(const binary_tree_t *t)
{
	int L = 0, R = 0;

	if (t != NULL)
	{
		if (t->right)
			R = giv_h(t->right);
		if (t->left)
			L = giv_h(t->left);

		return (L - R);
	}
	else
		return (0);
}

/**
 * binary_tree_is_avl - main fn
 * @tree: pointeur
 * Return: 1 (mean true)
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int R_L = 1, R_R = 1;

	if (!tree)
		return (0);

	if (!bntr_bst(tree))
		return (0);
	if (chek_b(tree) != -1 && chek_b(tree) != 1 &&
	chek_b(tree) != 0)
		return (0);
	if (tree->right)
		R_R = binary_tree_is_avl(tree->right);
	if (tree->left)
		R_L = binary_tree_is_avl(tree->left);

	return (R_L * R_R);
}