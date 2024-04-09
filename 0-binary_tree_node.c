#include "binary_trees.h"

/**
 * binary_tree_node - Creating a binary node
 *
 * @parent: node with a pointer to the next node(child)
 * @value: data
 * Return: Null if fail, otherwise a pointer to new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = (binary_tree_t *) malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
