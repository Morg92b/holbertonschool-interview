#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer
 * is a palindrome
 * @n: the unsigned long integer to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long temp = n;
	int digits[21];
	int i = 0, j;

	if (n == 0)
		return (1);

	while (temp > 0)
	{
		digits[i] = temp % 10;
		temp /= 10;
		i++;
	}

	for (j = 0; j < i / 2; j++)
	{
		if (digits[j] != digits[i - 1 - j])
			return (0);
	}

	return (1);
}