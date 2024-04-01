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

node *insert(int key, node *root)
{
	if (root == NULL)
	{
		node *newNode = (node *)malloc(sizeof(node));
		newNode->data = key;
		newNode->left = newNode->right = NULL;
		root = newNode;
		return root;
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

node *search(int key, node *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (key == root->data)
	{
		return root;
	}
	else if (key < root->data)
	{
		search(key, root->left);
	}
	else
	{
		search(key, root->right);
	}
}

node *delete(int key, node *root)
{
	if (root == NULL)
	{
		return root;
	}
	else if (key < root->data)
	{
		root->left = delete (key, root->left);
	}
	else if (key > root->data)
	{
		root->right = delete (key, root->right);
	}
	else // when root->data == key
	{
		if (root->left == NULL && root->right == NULL) // when the node to be deleted is leaf node
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL) // only right child present
		{
			node *temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL) // only left child present
		{
			node *temp = root;
			root = root->left;
			free(temp);
		}
		else // when both child are present
		{	 // we replace the root with the min of the right sub tree
			node *temp = root->right;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			root->data = temp->data;						// copy the value of the node to curr root
			root->right = delete (temp->data, root->right); // delete the duplicate node using recursion
		}
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

int height(node *root)
{
	int h;

	if (root == NULL)
	{
		return 0;
	}
	int lHeight = height(root->left);
	int rHeight = height(root->right);

	if (rHeight >= lHeight)
	{
		return 1 + rHeight;
	}
	else
	{
		return 1 + lHeight;
	}
}

int *genRandomKeysToArr(int num)
{
	int *arr = (int *)malloc(num * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		int randomVal = rand() % 101;
		arr[i] = randomVal;
	}

	return arr;
}

int main()
{
	int key, choice, N, tHeight;
	int *randomArr;

	printf("\nChoose from the below options: \n\n");
	printf("1. Insert N random keys in the BST\n");
	printf("2. Search for a key in the BST\n");
	printf("3. Delete a key from the BST\n");
	printf("4. Print Pre-Order Traversal\n");
	printf("5. Print In-Order Traversal\n");
	printf("6. Height of the binary tree.\n");
	printf("7. Exit the program.\n");

	while (choice != 7)
	{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\nEnter the number of random keys you want to insert: ");
			scanf("%d", &N);
			randomArr = genRandomKeysToArr(N); // storing the random keys in a dynamic array
			for (int i = 0; i < N; i++)
			{
				root = insert(randomArr[i], root); // inserting the randomly generated keys to the BST
			}
			printf("\n%d random keys have been inserted into the Binary Search Tree.", N);
			free(randomArr);
			break;
		case 2:
			printf("\nEnter the key you want to search for: ");
			scanf("%d", &key);
			node *keyAddr = search(key, root);
			if (keyAddr == NULL)
			{
				printf("\nThe key %d was not found in the BST.", key);
			}
			else
			{
				printf("The key %d was found at address %u", key, keyAddr);
			}
			break;
		case 3:
			printf("\nEnter the key you want to delete: ");
			scanf("%d", &key);

			if (search(key, root) == NULL)
			{
				printf("\nThe key %d was not found in the BST.", key);
			}
			else
			{
				root = delete (key, root);
				printf("The key %d was deleted from the BST", key);
			}
			break;
		case 4:
			if (root == NULL)
			{
				printf("\nThe tree is empty!\n");
				break;
			}
			printf("\nPre-Order Traversal: ");
			preOrder(root);
			printf("\n");
			break;
		case 5:
			if (root == NULL)
			{
				printf("\nThe tree is empty!\n");
				break;
			}
			printf("\nIn-Order Traversal: ");
			inOrder(root);
			printf("\n");
			break;
		case 6:
			tHeight = height(root);
			printf("\nThe height of the binary search tree is: %d", tHeight - 1); // tHeight - 1 so that when only root node present the height is 0 and so on
			break;
		case 7:
			printf("\nExiting the program..\n");
			break;
		default:
			printf("\nEnter a valid choice\n");
			break;
		}
	}
	return 0;
}
