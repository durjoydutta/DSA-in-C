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

void genRandomKeys(int num)
{
	FILE *randKeyFile = fopen("randomKeys.txt", "a");

	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		int randomVal = rand();
		fprintf(randKeyFile, "%d\n", randomVal);
	}

	fclose(randKeyFile);
}

int *randomKeyArr(int num)
{
	FILE *inputFile = fopen("randomKeys.txt", "r");
	int *randomKeys = (int *)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++)
	{
		fscanf(inputFile, "%d", &randomKeys[i]);
	}
	fclose(inputFile);
	return randomKeys;
}

int main()
{
	int key, choice, N, tHeight;
	int *randomArr;

	printf("\nChoose from the below options: \n\n");
	printf("1. Insert N random keys in the BST\n");
	printf("2. Print Pre-Order Traversal\n");
	printf("3. Print In-Order Traversal\n");
	printf("4. Height of the binary tree.\n");
	printf("5. Exit the program.\n");

	while (choice != 5)
	{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			srand(time(NULL));
			printf("Enter the number of random keys you want to insert: ");
			scanf("%d", &N);
			genRandomKeys(N);
			randomArr = randomKeyArr(N);
			for (int i = 0; i < N; i++)
			{
				root = insert(randomArr[i], root);
			}
			free(randomArr);
			break;
		case 2:
			if (root == NULL)
			{
				printf("\nThe tree is empty!\n");
				break;
			}
			printf("\nPre-Order Traversal: ");
			preOrder(root);
			printf("\n");
			break;
		case 3:
			if (root == NULL)
			{
				printf("\nThe tree is empty!\n");
				break;
			}
			printf("\nIn-Order Traversal: ");
			inOrder(root);
			printf("\n");
			break;
		case 4:
			tHeight = height(root);
			printf("\nThe height of the binary search tree is: %d", tHeight - 1);
			break;
		case 5:
			printf("\nExiting the program..\n");
			break;
		default:
			printf("\nEnter a valid choice\n");
			break;
		}
	}
	return 0;
}
