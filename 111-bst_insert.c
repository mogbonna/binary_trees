#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	return bst_insert_recursive(tree, value);
}

/**
 * bst_insert_recursive - Recursive helper function for BST insertion
 * @node: Pointer to the current node
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert_recursive(bst_t **node, int value)
{
	if (*node == NULL)
		{
			*node = binary_tree_node(NULL, value);
			return (*node);
		}

	if (value < (*node)->n)
		return (bst_insert_recursive(&((*node)->left), value));
	else if (value > (*node)->n)
		return (bst_insert_recursive(&((*node)->right), value));

	return (NULL);
}
