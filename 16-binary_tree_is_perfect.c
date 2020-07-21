#include "binary_trees.h"
/**
 * power - calculates the power exponent of the base
 * @base: base of the power
 * @exponent: exponent of the power
 * Return: The power
 */
int power(int base, int exponent)
{
	int result = 1;

	for (; exponent > 0; exponent--)
	{
		result = result * base;
	}
	return (result);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: binary tree
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
		size_t left = 0;
		size_t right = 0;

		if (!tree)
			return (0);
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		if (tree->right)
			right = 1 + binary_tree_height(tree->right);
		return ((left > right) ? left : right);
}

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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is a binary tree perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_height, tree_size, perfect_size;

	if (!tree)
		return (0);

	tree_height = binary_tree_height(tree);
	tree_size = binary_tree_size(tree);
	perfect_size = (power(2, tree_height + 1)) - 1;
	if (tree_size == perfect_size)
		return (1);
	return (0);
}
