#include <limits.h>
#include "binary_trees.h"
/**
 * bst_checker - Checks if Binary tree is a valid BST
 * based on a min and max
 * @tree: pointer to the root node of the tree to check
 * @min: Minimum value allowed for n in the current node
 * @max: Maximum value allowed for n in the current node
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int bst_checker(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min)
		return (0);

	if (tree->n > max)
		return (0);

	return (bst_checker(tree->left, min, (tree->n) - 1)
		* bst_checker(tree->right, (tree->n) + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bst_checker(tree, INT_MIN, INT_MAX));
}
