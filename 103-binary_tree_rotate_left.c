#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp_root = tree->parent;
	binary_tree_t *tmp_child;

	if (!tree)
		return (NULL);

	if (!tree->right)
		return (tree);

	tree->parent = tree->right;
	tree->right->parent = tmp_root;

	if (tree->right->left)
	{
		tmp_child = tree->right->left;
		tmp_child->parent = tree;
		tree->right->left = tree;
		tree->right = tmp_child;
	}
	else
	{
		tree->right->left = tree;
		tree->right = NULL;
	}
		
	return (tree->parent);

}