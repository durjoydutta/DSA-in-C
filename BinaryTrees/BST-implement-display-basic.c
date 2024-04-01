#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *root = NULL;

void createNode(node** root, int value)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL)
    {
        *root = newNode;
        return;
    }

    if (value <= (*root)->data)
    {
        createNode(&((*root)->left), value);
    }
    else
    {
        createNode(&((*root)->right), value);
    }
}

void printNodes(node *root)
{
    if (root == NULL)
    {
        // printf("\nNULL");
        return;
    }
    printf("\n%d", root->data);
    printNodes(root->left);
    printNodes(root->right);
}

int main()
{
    createNode(&root, 15);
    createNode(&root, 20);
    createNode(&root, 10);
    createNode(&root, 45);
    createNode(&root, 18);
    printNodes(root);
    return 0;
}
