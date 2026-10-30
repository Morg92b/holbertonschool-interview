#include "binary_trees.h"

/**
 * heap_node_count - Counts the nodes in a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes
 */
size_t heap_node_count(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + heap_node_count(tree->left) +
		heap_node_count(tree->right));
}

/**
 * heap_last_node - Finds the last node in level order
 * @root: Pointer to the root node
 * @size: Number of nodes in the heap
 *
 * Return: Pointer to the last node, or NULL
 */
heap_t *heap_last_node(heap_t *root, size_t size)
{
	size_t mask;

	if (!root || !size)
		return (NULL);

	mask = 1;
	while (mask <= size / 2)
		mask <<= 1;

	for (mask >>= 1; mask; mask >>= 1)
	{
		if (size & mask)
			root = root->right;
		else
			root = root->left;
	}

	return (root);
}

/**
 * heap_sift_down - Restores the max heap property downward
 * @node: Pointer to the starting node
 */
void heap_sift_down(heap_t *node)
{
	heap_t *largest;
	int value;

	while (node)
	{
		largest = node;
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;
		if (largest == node)
			break;

		value = node->n;
		node->n = largest->n;
		largest->n = value;
		node = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a max binary heap
 * @root: Double pointer to the root node
 *
 * Return: Extracted value, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *old_root, *last;
	int value;

	if (!root || !*root)
		return (0);

	old_root = *root;
	value = old_root->n;
	last = heap_last_node(old_root, heap_node_count(old_root));
	if (last == old_root)
	{
		*root = NULL;
		free(old_root);
		return (value);
	}

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	last->parent = NULL;
	last->left = old_root->left;
	last->right = old_root->right;
	if (last->left)
		last->left->parent = last;
	if (last->right)
		last->right->parent = last;

	*root = last;
	free(old_root);
	heap_sift_down(*root);
	return (value);
}
