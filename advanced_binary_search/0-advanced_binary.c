#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints an array
 * @array: Array to print
 * @size: Size of the array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);

		if (i < size - 1)
			printf(", ");
	}

	printf("\n");
}

/**
 * advanced_binary_recursive - Searches recursively for a value
 * @array: Array to search
 * @left: Left boundary
 * @right: Right boundary
 * @value: Value to search
 *
 * Return: Index of the first occurrence, or -1
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array + left, right - left + 1);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] != value)
			return ((int)mid);

		return (advanced_binary_recursive(array, left, mid - 1, value));
	}

	if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, right, value));

	return (advanced_binary_recursive(array, left, mid, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array
 * @array: Array to search
 * @size: Size of the array
 * @value: Value to search
 *
 * Return: Index of the first occurrence, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
