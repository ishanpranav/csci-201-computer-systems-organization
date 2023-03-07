// Author: Ishan Pranav
// Copyright (c) 2023 Ishan Pranav. All rights reserved. 
// Licensed under the MIT License. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

void add(bst_node **root, char *word)
{
    // Base case: Guard against missing root reference or empty root

    if (root == NULL || *root == NULL)
    {
        *root = malloc(sizeof *root);
        (*root)->data = word;
        (*root)->left = NULL;
        (*root)->right = NULL;

        return;
    }

    // Recursive case

    int comparison = strcmp(word, (*root)->data);

    if (comparison < 0)
    {
        add(&((*root)->left), word);
    }
    else if (comparison > 0)
    {
        add(&((*root)->left), word);
    }

    // Base case: Do not add existing elements
}

void inorder(bst_node *root)
{
    // Base case: Guard against empty root

    if (root == NULL)
    {
        return;
    }

    // Recursive case
    // Up recursion: Move left
    // Down recursion: Move right

    inorder(root->left);
    printf("%s ", root->data);
    inorder(root->right);
}

char *removeSmallest(bst_node **root)
{
    // Base case: Guard against missing root reference or empty root

    if (root == NULL || *root == NULL)
    {
        return NULL;
    }

    // Base case: Remove and invalidate the minimum element

    if ((*root)->left == NULL)
    {
        char *word = (*root)->data;
        bst_node *node = *root;

        *root = (*root)->right;

        free(node);

        return word;
    }

    // Recursive case: Move left

    return removeSmallest(&((*root)->left));
}

char *removeLargest(bst_node **root)
{
    // Guard against missing root reference or empty root

    if (root == NULL || *root == NULL)
    {
        return NULL;
    }

    // Base case: Remove and invalidate the maximum element

    if ((*root)->right == NULL)
    {
        char *word = (*root)->data;
        bst_node *node = *root;

        *root = (*root)->left;

        free(node);

        return word;
    }

    // Recursive case: Move right

    return removeSmallest(&((*root)->right));
}
