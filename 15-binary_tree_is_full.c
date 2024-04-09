#include "binary_trees.h"

/**
 * is_full_recursive - checks if tree is full recursively
 *
 * @tree: pointer to the root of the node to check
 * Return: 0 if tree is full, else 1
 */

int is_full_recursive(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left && tree->right)
		return (is_full_recursive(tree->left) && is_full_recursive(tree->right));

	return (0);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
