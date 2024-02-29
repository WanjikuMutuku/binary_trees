#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	size_t height = binary_tree_height(tree);
	size_t level;

	for (level = 1; level <= height + 1; level++)
		binary_tree_levelorder_recursive(tree, func, level);
}

/**
 * binary_tree_height - Computes the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return ((left_height > right_height ? left_height : right_height) + 1);
}
/**
 * binary_tree_levelorder_recursive - Helper function for level-order traversal
 * @tree: Pointer to the current node in the tree
 * @func: Pointer to a function to call for each node
 * @level: The current level being visited
 */
void binary_tree_levelorder_recursive(const binary_tree_t *tree,
		void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_levelorder_recursive(tree->left, func, level - 1);
		binary_tree_levelorder_recursive(tree->right, func, level - 1);
	}
}
