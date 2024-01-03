#include "binary_trees.h"

/**
 * binary_tree_ancestor_helper - Helper function for finding the ancestor
 * @root: Pointer to the root of the binary tree
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, NULL if not found
 */
binary_tree_t *binary_tree_ancestor_helper(const binary_tree_t *root,
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	if (root == NULL || root == first || root == second)
		return ((binary_tree_t *)root);

	left = binary_tree_ancestor_helper(root->left, first, second);
	right = binary_tree_ancestor_helper(root->right, first, second);

	if (left != NULL && right != NULL)
		return ((binary_tree_t *)root);

	return ((left != NULL) ? left : right);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	return (binary_tree_ancestor_helper(first, first, second));
}

