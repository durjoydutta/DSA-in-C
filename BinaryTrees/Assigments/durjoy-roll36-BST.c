#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *root = NULL;

node *insert(int key, node *root)
{
    if (root == NULL)
    {
        node *newNode = malloc(sizeof(node));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return newNode;
    }
    else if (key <= root->data)
    {
        root->left = insert(key, root->left);
    }
    else
    {
        root->right = insert(key, root->right);
    }

    return root;
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int minKey(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}

int maxKey(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

node *search(int key, node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(key, root->left);
    }
    else
    {
        return search(key, root->right);
    }
}

int main()
{
    int num, searchKey, insertKey, choice;
    int minVal, maxVal;
    node *searchRes = NULL;

    // BST operation menu
    printf("\nChoose one option from below: \n\n");
    printf("1. Insert a node in the tree\n");
    printf("2. Display tree nodes in pre-order\n");
    printf("3. Display tree nodes in in-order\n");
    printf("4. Display tree nodes in post-order\n");
    printf("5. Search for a key\n");
    printf("6. Find min and max elements\n");
    printf("7. Exit\n");

    while (choice != 7)
    {
        printf("\nEnter you choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the element you want to insert: ");
            scanf("%d", &insertKey);
            root = insert(insertKey, root);
            break;
        case 2:
            printf("\n");
            printf("Pre-Order: ");
            preOrder(root);
            printf("\n");
            break;
        case 3:
            printf("\n");
            printf("In-Order: ");
            inOrder(root);
            printf("\n");
            break;
        case 4:
            printf("\n");
            printf("Post-Order: ");
            postOrder(root);
            printf("\n");
            break;
        case 5:
            printf("\nEnter the key you want to search for: ");
            scanf("%d", &searchKey);
            searchRes = search(searchKey, root);
            if (searchRes == NULL)
            {
                printf("\nThe key %d is not found in the BST.", searchKey);
            }
            else
            {
                printf("\nThe key %d is found at %u", searchKey, searchRes);
            }
            break;
        case 6:
            minVal = minKey(root);
            maxVal = maxKey(root);
            printf("\nMin: %d | Max: %d\n", minVal, maxVal);
            break;
        case 7:
            printf("\nExiting the program...\n");
            break;
        default:
            printf("Please choose a valid option.\n");
        }
    }

    return 0;
}