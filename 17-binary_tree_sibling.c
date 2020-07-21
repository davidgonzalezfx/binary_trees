#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: is a pointer to the node to find the sibling
 * Return: a pointer to the sibling node, if node is NULL,
 * the parent is NULL or if node has no sibling, return NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		if (node->parent->right)
			return (node->parent->right);
		else
			return (NULL);
	else
		if (node->parent->left)
			return (node->parent->left);
		else
			return (NULL);
}
