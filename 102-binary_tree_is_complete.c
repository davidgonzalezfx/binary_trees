#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: binary tree
 * Return: size = number of nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
		if (!tree)
			return (0);
		return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_complete - biggest index node
 * @tree: binary tree
 * @cnt: index for each node
 * Return: biggest index node
 */
size_t binary_tree_complete(const binary_tree_t *tree, int cnt)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (cnt);

	left = binary_tree_complete(tree->left, 2 * cnt + 1);
	right = binary_tree_complete(tree->right, 2 * cnt + 2);

	return ((left > right) ? left : right);
}

/**
 * binary_tree_is_complete - check if tree is complete binary tree
 * @tree: binary tree
 * Return: 1 if complete - 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size = binary_tree_size(tree);
	int complete = binary_tree_complete(tree, 0);

	if (!tree)
		return (0);

	if (size == complete + 1)
		return (1);
	return (0);
}
