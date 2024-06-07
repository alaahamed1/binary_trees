#include "binary_trees.h"

/**
 * custom_binary_tree_depth - Measures the depth of a node in a binary tree
 * @node: Pointer to the node to measure the depth
 *
 * Return: Depth of the node
 */
int custom_binary_tree_depth(const binary_tree_t *node)
{
	int depth = 0;

	while (node)
	{
		depth++;
		node = node->parent;
	}

	return depth;
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 *  or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	int depth_first = custom_binary_tree_depth(first);
	int depth_second = custom_binary_tree_depth(second);

	const binary_tree_t *a_first = first;
	const binary_tree_t *a_second = second;

	while (depth_first > depth_second)
	{
		a_first = a_first->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		a_second = a_second->parent;
		depth_second--;
	}

	while (a_first && a_second)
	{
		if (a_first == a_second)
			return ((binary_tree_t *)a_first);

		a_first = a_first->parent;
		a_second = a_second->parent;
	}

	return (NULL);
}
