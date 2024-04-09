#include "binary_trees.h"

/**
 *  binary_tree_balance - measures the balance factor of a binary tree
 *
 *  @tree: a pointer to the root node of the tree
 *  Return: 0 if tree is null
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binarytree_height(tree->left) - binarytree_height(tree->right));
}

/**
 * binarytree_height - measures the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree
 * Return: 0 if is NULL
 */

size_t binarytree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL)
		return (0);

	l = binarytree_height(tree->left);
	r = binarytree_height(tree->right);

	return (1 + (l > r ? l : r));
}
