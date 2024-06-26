#include "binary_trees.h"

/**
 * is_full_recursive - Recursively checks if a tree is full.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is full, otherwise 0.
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((tree->left == NULL && tree->right != NULL) ||
		(tree->left != NULL && tree->right == NULL))
		return (0);

	return (is_full_recursive(tree->left) && is_full_recursive(tree->right));
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is full, otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_full_recursive(tree));
}
