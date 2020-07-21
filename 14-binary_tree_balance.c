#include "binary_trees.h"

/**
 *
 *
 *
 */

size_t binary_tree_height(const binary_tree_t *tree)
{

}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the balance factor
 * Return: The balance factor, If tree is NULL, return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if(!tree)
		return 0;
	return(binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
