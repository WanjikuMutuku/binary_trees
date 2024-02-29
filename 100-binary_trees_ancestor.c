#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor1 = first;
	const binary_tree_t *ancestor2 = second;

	while (ancestor1 != ancestor2)
	{
		if (ancestor1 == NULL)
			ancestor1 = second;
		else
			ancestor1 = ancestor1->parent;
		if (ancestor2 == NULL)
			ancestor2 = first;
		else
			ancestor2 = ancestor2->parent;
	}
	return ((binary_tree_t *)ancestor1);
}
