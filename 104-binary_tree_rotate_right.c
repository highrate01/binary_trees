
#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp, *move;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	move = tree->left;
	temp = move->right;
	move->right = tree;
	tree->left = temp;

	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = move;
	move->parent = temp;

	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = move;
		else
			temp->right = move;
	}
	return (move);
}
