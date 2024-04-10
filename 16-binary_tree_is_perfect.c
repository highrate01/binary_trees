#include "binary_trees.h"
int binary_tree_is_perfect(const binary_tree_t *tree);
size_t tree_depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth,
                        size_t level);
/**
 * is_leaf - checks if a node is a leaf
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * tree_depth - checks the depth of a node in a binary tree
 *
 * @tree: a pointer to the node to measure the depth
 * Return: Return depth
 */
size_t tree_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + tree_depth(tree->parent) : 0);
}

/**
 * get_leaf - Returns leaf of the binary tree
 *
 * @tree: pointer to the root of a node to find the leaf
 * Return: pointer to the leaf node
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - checks if a binary tree is perfect recursively
 *
 * @tree: pointer to the root of the node to check
 * @leaf_depth: the dept of the leaf
 * @level: leavel of current node
 * Return: 1 if the tree is perect, else 0
 */

int is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth,
			size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1)
		&& is_perfect_recursive(tree->right, leaf_depth, level + 1));
}
/**
 * binary_tree_is_perfect - checks if binary tree is perect
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is Null
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, tree_depth(get_leaf(tree)), 0));
}
