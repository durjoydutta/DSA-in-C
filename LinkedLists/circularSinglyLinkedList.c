#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;
node *tail = NULL;

void insertNodeifEmpty(node *newNode) // used to initialize both head and tail for first entry
{
    newNode->next = newNode;
    head = newNode;
    tail = head;
}

void createNodeHead(int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    if (head == NULL) // if empty
    {
        insertNodeifEmpty(newNode);
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    head = newNode;
}

void createNodeTail(int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    if (head == NULL) // if empty
    {
        insertNodeifEmpty(newNode);
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void insertNodeFromHead(int nodeNumsHead)
{
    int value;
    srand(time(NULL));
    for (int i = 0; i < nodeNumsHead; i++)
    {
        value = rand() % 101;
        createNodeHead(value);
        printf("Inserted %d at the beginning\n", value);
    }
}

void insertNodeFromTail(int nodeNumsTail)
{
    int value;
    srand(time(NULL));
    for (int i = 0; i < nodeNumsTail; i++)
    {
        value = rand() % 101;
        createNodeTail(value);
        printf("Inserted %d at the end\n", value);
    }
}

void displayNode()
{
    if (head == NULL)
    {
        printf("\nThe list is currently empty!\n");
        return;
    }

    node *temp = tail->next;
    printf("Address| Node | Next\n");
    do
    {
        printf("%u | %d | %u \n", temp, temp->data, temp->next);
        temp = temp->next;
    } while (temp != tail->next);

    printf("\nHead Pointer: %d", head->data);
    printf("\nTail Pointer: %d", tail->data);
}
int main()
{
    int nodeNumsHead, nodeNumsTail;
    int choice;

    printf("\nChoose one option from below: \n");
    printf("1. Insert Node from head\n");
    printf("2. Insert Node from tail\n");
    printf("3. Display nodes\n");
    printf("4. Exit");

    while (choice != 4)
    {
        printf("\nEnter you choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter no. of nodes to enter from head: ");
            scanf("%d", &nodeNumsHead);
            insertNodeFromHead(nodeNumsHead);
            break;
        case 2:
            printf("\nEnter no. of nodes to enter from tail: ");
            scanf("%d", &nodeNumsTail);
            insertNodeFromTail(nodeNumsTail);
            break;
        case 3:
            displayNode();
            break;
        case 4:
            printf("\nExiting the program...\n");
            break;
        default:
            printf("Please choose a valid option.\n");
        }
    }

    return 0;
}