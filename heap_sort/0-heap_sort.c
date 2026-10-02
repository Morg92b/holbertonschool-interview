#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @array: Array containing the integers
 * @size: Size of the complete array
 * @first: Index of the first integer
 * @second: Index of the second integer
 */
static void swap_ints(int *array, size_t size, size_t first, size_t second)
{
	int tmp;

	if (first == second)
		return;

	tmp = array[first];
	array[first] = array[second];
	array[second] = tmp;
	print_array(array, size);
}

/**
 * sift_down - Restores the max-heap property from a root node downward
 * @array: Array to sift
 * @size: Size of the complete array
 * @heap_size: Size of the active heap
 * @root: Root index to sift down from
 */
static void sift_down(int *array, size_t size, size_t heap_size, size_t root)
{
	size_t largest, left, right;

	while (1)
	{
		largest = root;
		left = (2 * root) + 1;
		right = (2 * root) + 2;

		if (left < heap_size && array[left] > array[largest])
			largest = left;
		if (right < heap_size && array[right] > array[largest])
			largest = right;

		if (largest == root)
			return;

		swap_ints(array, size, root, largest);
		root = largest;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i, heap_size;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, size, i - 1);

	for (heap_size = size; heap_size > 1; heap_size--)
	{
		swap_ints(array, size, 0, heap_size - 1);
		sift_down(array, size, heap_size - 1, 0);
	}
}
