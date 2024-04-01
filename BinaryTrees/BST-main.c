#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *root = NULL;

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        node *newNode = malloc(sizeof(node));
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        root = newNode;
    }
    else if (key <= (root)->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
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

void levelOrder(node *root)
{
    if (!root)
    {
        return;
    }
    node **q = malloc(1000 * sizeof(node));
    int front = -1;
    int rear = -1;
    q[++rear] = root;
    while (front != rear)
    {
        node *temp = q[++front];
        printf("%d\t%d\t%d\n", front, rear, temp->data);
        if (temp->left != NULL)
        {
            q[++rear] = temp->left;
        }
        if (temp->right != NULL)
        {
            q[++rear] = temp->right;
        }
    }
    free(q);
}

int search(node *root, int val)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data == val)
    {
        return 1;
    }
    else if (val < root->data)
    {
        return search(root->left, val);
    }
    else if (val > root->data)
    {
        return search(root->right, val);
    }
}

int predecessor(node *root, int x) // to find predecessor of x node
{
    node *pred = NULL;
    while (root != NULL)
    {
        if (root->data >= x)
        {
            root = root->left;
        }
        else
        {
            pred = root;
            root = root->right;
        }
    }

    if (pred == NULL)
    {
        return 0;
    }

    return pred->data;
}

int successor(node *root, int x) // to find predecessor of x node
{
    node *succ = NULL;

    while (root != NULL)
    {
        if (root->data <= x)
        {
            root = root->right;
        }
        else
        {
            succ = root;
            root = root->left;
        }
    }

    if (succ == NULL)
    {
        return 0;
    }

    return succ->data;
}

node *delete(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    else if (val < root->data)
    {
        root->left = delete (root->left, val);
    }
    else if (val > root->data)
    {
        root->right = delete (root->right, val);
    }
    else
    {                                                  // when root == val
        if (root->left == NULL && root->right == NULL) // when the node to be deleted is leaf node
        {                                              // leaf node
            free(root);
            root = NULL;
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
            root->right = delete (root->right, temp->data); // delete the duplicate value
        }
    }
    return root;
}

int height(node *root)
{
    if (!root)
    {
        return -1; // when null node is found
    }
    int lH = 1 + height(root->left);  // height of left subtree
    int rH = 1 + height(root->right); // height o right subtree

    return (lH > rH) ? lH : rH;
}

int minKey(node *root) // using iterative approach
{
    if (root == NULL)
    {
        printf("\nBST is empty!");
        return -1;
    }
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int maxKey(node *root) // using recursive approach
{
    if (root == NULL)
    {
        printf("\nBST is empty!");
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return maxKey(root->right);
}

int main()
{
    int num, searchKey, searchRes, insertKey, choice;
    int minVal, maxVal, delVal;

    // BST operation menu
    printf("\nChoose one option from below: \n");
    printf("1. Create Binary Search Tree with N nodes (your choice of N)\n");
    printf("2. Insert a node in the tree\n");
    printf("3. Display tree nodes in pre-order\n");
    printf("4. Display tree nodes in in-order\n");
    printf("5. Display tree nodes in post-order\n");
    printf("6. Display tree nodes in level-order\n");
    printf("7. Search for a key\n");
    printf("8. Delete a key\n");
    printf("9. Height of the binary tree\n");
    printf("10. Find min and max elements\n");
    printf("11. Predecessor of a key\n");
    printf("12. Successor of a key\n");
    printf("13. Exit\n");

    while (choice != 13)
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
            printf("PreOrder: ");
            preOrder(root);
            printf("\n");
            break;
        case 4:
            printf("\n");
            printf("InOrder: ");
            inOrder(root);
            printf("\n");
            break;
        case 5:
            printf("\n");
            printf("PostOrder: ");
            postOrder(root);
            printf("\n");
            break;
        case 6:
            printf("\n");
            printf("LevelOrder: ");
            levelOrder(root);
            printf("\n");
            break;
        case 7:
            printf("\nEnter the key you want to search for: ");
            scanf("%d", &searchKey);
            searchRes = search(root, searchKey);
            if (searchRes == 1)
            {
                printf("\nThe key %d is found in the BST.", searchKey);
            }
            else
            {
                printf("\nThe key %d is not found.", searchKey);
            }
            break;
        case 8:
            printf("\nEnter the element you want to delete: ");
            scanf("%d", &delVal);
            root = delete (root, delVal);
            break;
        case 9:
            int tHeight = height(root);
            printf("\nThe height of the binary search tree is: %d", tHeight); // tHeight - 1 so that when only root node present the height is 0 and so on
            break;
        case 10:
            minVal = minKey(root);
            maxVal = maxKey(root);
            printf("\nMin: %d | Max: %d", minVal, maxVal);
            break;
        case 11:
            printf("\nEnter the element you want to find predecessor for: ");
            scanf("%d", &searchKey);
            int pred = predecessor(root, searchKey);
            printf("\nThe predecessor of the key %d is : %d", searchKey, pred);
            break;
        case 12:
            printf("\nEnter the element you want to find successor for: ");
            scanf("%d", &searchKey);
            int succ = successor(root, searchKey);
            printf("\nThe successor of the key %d is : %d", searchKey, succ);
            break;
        case 13:
            printf("\nExiting the program...\n");
            break;
        default:
            printf("Please choose a valid option.\n");
        }
    }

    return 0;
}
