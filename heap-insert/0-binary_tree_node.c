#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Insert a node in a binary tree with a specific value
 * @parent: parent of the node to create
 * @value: value of the node to create
 * Return: address of the new element or NULL if it fails
 **/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new;

    new = malloc(sizeof(binary_tree_t));
    if (new == NULL)
        return (NULL);

    new->left = NULL;
    new->right = NULL;
    new->parent = parent;
    new->n = value;

    return (new);
}