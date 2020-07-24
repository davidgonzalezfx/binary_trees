#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate right
 * @tree: binary tree
 * Return: pointer to new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *aux;

	if (!tree || !tree->left)
		return (tree);

	aux = tree->left;
	tree->parent = aux;
	aux->parent = tree->parent;

	tree->left = aux->right;
	if (tree->left)
		tree->left->parent = tree;

	aux->right = tree;

	return (aux);
}
