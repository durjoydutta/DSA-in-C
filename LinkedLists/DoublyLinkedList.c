#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node;

node *head = NULL;
node *tail = NULL;

void insertNodeifEmpty(node *newNode) // used to initialize both head and tail for first entry
{
    newNode->prev = NULL;
    newNode->next = NULL;
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
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
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
    newNode->prev = tail;
    newNode->next = NULL;
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
    }
}

void displayNode()
{
    if (head == NULL)
    {
        printf("\nThe list is currently empty!\n");
        return;
    }
    node *temp = head;
    printf("Prev| Node | Address | Next\n");
    while (temp != NULL)
    {
        printf("%u\t%d\t%u\t%u\n", temp->prev, temp->data, temp, temp->next);
        temp = temp->next;
    }
    printf("NULL");

    printf("\nHead Pointer: %d | %u", head->data, head);
    printf("\nTail Pointer: %d | %u", tail->data, tail);
}

void reverseList()
{
    if (head == NULL)
    {
        printf("\nThe list is currently empty!\n");
        return;
    }

    node *before = NULL;
    node *curr = head;
    node *after = NULL;

    while (curr != NULL)
    {
        after = curr->next;
        curr->next = before;
        curr->prev = after;

        before = curr;
        curr = after;
    }
    tail = head;
    head = before;
}

int main()
{
    int nodeNumsHead, nodeNumsTail;
    int choice;

    printf("\nChoose one option from below: \n");
    printf("1. Insert Node from head\n");
    printf("2. Insert Node from tail\n");
    printf("3. Display nodes\n");
    printf("4. Reverse nodes\n");
    printf("5. Exit");

    while (choice != 5)
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
            reverseList();
            break;
        case 5:
            printf("\nExiting the program...\n");
            break;
        default:
            printf("Please choose a valid option.\n");
        }
    }

    return 0;
}