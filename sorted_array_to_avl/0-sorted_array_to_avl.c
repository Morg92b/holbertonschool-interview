#include "binary_trees.h"

/**
 * create_node - Creates a new binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to store in the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
static avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * build_avl - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray (exclusive)
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the created subtree, or NULL on failure
 */
static avl_t *build_avl(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *root;
	size_t mid;

	if (start >= end)
		return (NULL);

	mid = start + (end - start - 1) / 2;

	root = create_node(parent, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = build_avl(array, start, mid, root);
	root->right = build_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, size, NULL));
}
