#include <math.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *prev, *last;

	if (list == NULL)
		return (NULL);
	express = list->express;
	prev = list;
	while (express != NULL && express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		prev = express;
		express = express->express;
	}
	if (express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       prev->index, express->index);
		last = express;
	}
	else
	{
		last = prev;
		while (last->next != NULL)
			last = last->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
		       prev->index, last->index);
	}
	while (prev != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		if (prev == last)
			break;
		prev = prev->next;
	}
	return (NULL);
}
