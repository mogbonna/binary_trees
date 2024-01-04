#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	count = 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
	return (count);
}

/**
  * binary_tree_is_complete - function that checks if a binary tree is complete
  * @tree: is a pointer to the root node of the tree to check
  *
  * Return: if complete (1), is not complete or Tree is NULL (0)
  */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t index = 0, number_nodes;

	if (tree == NULL)
		return (0);

	number_nodes = binary_tree_size(tree);
	return (iscomplete(tree, number_nodes, index));
}

/**
  * iscomplete - function that checks if a binary tree is complete
  * @tree: is a pointer to the root node of the tree to check
  * @number_nodes: the number of nodes of the binary tree
  * @index: the position of a node in a binary tree
  *
  * Return: if complete (1), is not complete or Tree is NULL (0)
  */
int iscomplete(const binary_tree_t *tree, size_t number_nodes, size_t index)
{
	if (tree == NULL)
		return (1);

	if (index >= number_nodes)
		return (0);

	return (iscomplete(tree->left, number_nodes, index * 2 + 1) &&
		iscomplete(tree->right, number_nodes, index * 2 + 2));
}
