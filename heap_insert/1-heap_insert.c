#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_insert - Insère une valeur dans un arbre binaire max heap.
 * @root: Double pointeur vers la racine de l'arbre.
 * @value: Valeur à insérer.
 * Return: Pointeur vers le nœud inséré, ou NULL en cas d'échec.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;	 /* Créer un node vide nommée new*/
	heap_t *current; /* Créer un node pour se déplacer*/
	int n;			 /* Variable qui prend le nombre de node à partir du nœud actuel */

	current = *root; /* initialise current sur la racine de l'arbre */

	if ((*root) == NULL)
	{
		*root = createNode(value);
		return (*root);
	}

	n = count_nodes(current) + 1;
	new = createNode(value); /* alloue de la mémoire à new */

	new = find_and_attach_parent(current, new, n);
	heap_t *result = new; /* save le nœud original */
	/* cherche le nœud qui contient la valeur */

	while (result->parent != NULL && value > result->parent->n)
	{
		result = result->parent;
	}

	swap(new);
	return (result);
}

/**
 * find_and_attach_parent - Trouve le parent et
 * attache le nouveau nœud à la bonne place.
 * @current: Pointeur vers le nœud courant.
 * @new: Pointeur vers le nouveau nœud à insérer.
 * @n: Nombre total de nœuds après insertion.
 * Return: Pointeur vers le nœud inséré.
 */
heap_t *find_and_attach_parent(heap_t *current, heap_t *new, int n)
{
	int bits_size = 0; /* Nombre de bits nécessaires pour représenter n */
	int temp = n;	   /* variable temporaire de valeur n (nombre de nodes)*/

	while (temp > 0)
	{
		bits_size++;
		temp = temp >> 1;
	}

	for (int i = bits_size - 2; i >= 1; i--)
	{
		int bit = (n >> i) & 1; /* Récupère le i-ème bit de n */

		if (bit == 0)
		{
			current = current->left; /* Aller à gauche si bit = 0 */
		}
		if (bit == 1)
		{
			current = current->right; /* Aller à droite si bit = 1 */
		}
	}
	int last_bit = (n >> 0) & 1;

	if (last_bit == 0)
	{
		current->left = new;
		new->parent = current;
	}
	else
	{
		current->right = new;
		new->parent = current;
	}

	return (new);
}

/**
 * swap - Remonte le nœud inséré pour maintenir la propriété du max heap.
 * @new: Pointeur vers le nœud nouvellement inséré.
 * Return: 1 (succès).
 */
int swap(heap_t *new)
{
	while (new->parent != NULL && new->n > new->parent->n)
	{
		int temp = new->n;

		new->n = new->parent->n;
		new->parent->n = temp;
		new = new->parent;
	}
	return (1);
}

/**
 * createNode - Crée un nouveau nœud pour l'arbre binaire.
 * @value: Valeur à stocker dans le nœud.
 * Return: Pointeur vers le nouveau nœud, ou NULL en cas d'échec.
 */
heap_t *createNode(int value)
{
	heap_t *new;

	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/**
 * count_nodes - Compte le nombre de nœuds dans un arbre binaire.
 * @node: Pointeur vers la racine de l'arbre ou du sous-arbre.
 * Return: Nombre total de nœuds.
 */
int count_nodes(heap_t *node)
{
	if (node == NULL)
		return (0);
	return (1 + count_nodes(node->left) + count_nodes(node->right));
}
