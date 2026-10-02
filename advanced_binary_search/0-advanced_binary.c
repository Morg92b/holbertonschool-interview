#include "search_algos.h"

/**
 * print_array - prints the sub-array between two indices
 * @array: pointer to the array
 * @low: first index to print
 * @high: last index to print
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_rec - recursive search for the first occurrence of a value
 * @array: pointer to the array
 * @low: lower bound index
 * @high: upper bound index
 * @value: value to search for
 *
 * Return: index of the first occurrence of value, or -1 if not found
 */
int binary_rec(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	print_array(array, low, high);
	mid = low + (high - low) / 2;

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] != value)
			return ((int)mid);
		return (binary_rec(array, low, mid, value));
	}
	if (array[mid] < value)
		return (binary_rec(array, mid + 1, high, value));
	if (mid == 0)
		return (-1);
	return (binary_rec(array, low, mid - 1, value));
}

/**
 * advanced_binary - searches for a value in a sorted array of integers,
 *                   returning the index of its first occurrence
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (binary_rec(array, 0, size - 1, value));
}

