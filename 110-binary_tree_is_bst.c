#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - Helper function for checking BST property recursively
 * @tree: Pointer to the root node of the tree
 * @min: Minimum valid value for the current node
 * @max: Maximum valid value for the current node
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
			is_bst_helper(tree->right, tree->n, max));
}
