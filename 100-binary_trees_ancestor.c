#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that checks an ancestor
 * @first: First node
 * @second: Second node
 * Return: the node of the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	left = first->parent;
	right = second->parent;

	if (left == NULL || first == right || (!left->parent && right))
	{
		return (binary_trees_ancestor(first, right));
	}
	else if (right == NULL || left == second || (!right->parent && left))
	{
		return (binary_trees_ancestor(left, second));
	}
	return (binary_trees_ancestor(left, right));
}
