// AVL Tree insertion and deletion operations
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} node;

node *root = NULL;

int height(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int lHeight = 1 + height(root->left);
        int rHeight = 1 + height(root->right);

        return max(lHeight, rHeight);
    }
}

int balanceFactor(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return height(root->left) - height(root->right);
}

node *leftRotate(node *root)
{
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = temp;

    return root;
}

node *rightRotate(node *root)
{
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;

    return root;
}

node *createNode(int val)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;

    return newNode;
}

node *balancingByRotation(node *root, int val)
{
    int balF = balanceFactor(root);
    // left heavy
    if (balF > 1)
    {
        if (val < root->left->data) // LL imbalance
        {
            return rightRotate(root);
        }
        else // LR imbalance
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    // right heavy
    if (balF < -1)
    {
        if (val > root->right->data) // RR imbalance
        {
            return leftRotate(root);
        }
        else // RL imbalance
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    root->height = height(root);
    return root; // for already balanced
}

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        root = createNode(val);
    }
    else if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }

    root->height = height(root);
    // balancing by rotation
    root = balancingByRotation(root, val);

    return root;
}

node *search(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    else if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else if (key > root->data)
    {
        return search(root->right, key);
    }
}

node *deleteNode(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else // when root->data == val
    {
        if (root->left == NULL && root->right == NULL) // when the node to be deleted is leaf node
        {                                              // leaf node
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left == NULL) // when the node only has right child
        {                            // only right child present
            node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) // only has left child
        {                             // only left child present
            node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        { // both children present
            // find the minimum value in the right subtree (we can also use the max val in the left sub tree)
            node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data); // recursively delete the duplicate value of right subtree
        }
    }
    root->height = height(root);
    // balancing by rotation
    root = balancingByRotation(root, key);

    return root;
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d\t%d\t%d\n", root->data, root->height, balanceFactor(root));
    inOrder(root->right);
}

void printTree(node *root, int space)
{
    if (!root)
    {
        return;
    }
    space += 10;
    printTree(root->right, space);
    for (int i = 0; i <= space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main()
{
    int num, insertKey, choice, delVal;

    // BST operation menu
    printf("\nChoose one option from below: \n\n");
    printf("1. Create AVL Tree with N nodes (your choice of N)\n");
    printf("2. Insert a node in the tree (one by one)\n");
    printf("3. Display nodes in in-order\n");
    printf("4. Display nodes in 2D tree form\n");
    printf("5. Delete a node\n");
    printf("6. Exit\n");

    while (choice != 6)
    {
        printf("\nEnter you choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            srand(time(NULL));
            printf("\nEnter the number of keys in the BST: ");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                int value = rand() % 101;
                root = insert(root, value);
            }
            break;
        case 2:
            printf("\nEnter the element you want to insert: ");
            scanf("%d", &insertKey);
            root = insert(root, insertKey);
            break;
        case 3:
            printf("\n");
            printf("InOrder Height BalanceFactor\n");
            inOrder(root);
            break;
        case 4:
            printf("\n");
            printf("2D Tree Form: (left to right)\n\n");
            printTree(root, 0);
            break;
        case 5:
            printf("\nEnter the element you want to delete: ");
            scanf("%d", &delVal);
            if (search(root, delVal))
            {
                root = deleteNode(root, delVal);
                printf("\nThe key %d is deleted.\n", delVal);
            }
            else
                printf("\nThe key %d is not present!\n", delVal);
            break;
        case 6:
            printf("\nExiting the program..");
            break;
        default:
            printf("\nChoose a valid option.");
            break;
        }
    }
    return 0;
}