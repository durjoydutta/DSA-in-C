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
    newNode->next = head;
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

void insertNodeAtIndex(int index)
{
    if (index < 0)
    {
        printf("Enter valid positive integer value!");
        return;
    }
    if (index == 0)
    {
        insertNodeFromHead(1);
        return;
    }
    int pos = 1;
    srand(time(NULL));
    int value = rand() % 101;
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    node *temp = head;

    while (temp != NULL && temp != tail)
    {
        if (pos == index)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("\nList index greater than number of nodes!");
    return;
}

void displayNode()
{
    if (head == NULL)
    {
        printf("\nThe list is currently empty!\n");
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    printf("\nHead Pointer: %d | %u", head->data, head);
    printf("\nTail Pointer: %d | %u", tail->data, tail);
}

void displayMid() // display mid in O(n) time
{
    node *slowPtr = head;
    node *fastPtr = head;
    if (head == NULL)
    {
        printf("\nList is empty!!\n");
        return;
    }
    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    printf("\nThe n/2th node of the list is : %d\n", slowPtr->data);
}

int main()
{
    int nodeNumsHead, nodeNumsTail;
    int insertIndex;
    int choice;

    printf("\nChoose one option from below: \n");
    printf("1. Insert Node from head\n");
    printf("2. Insert Node from tail\n");
    printf("3. Enter node at N-th index\n");
    printf("4. Display nodes\n");
    printf("5. Print Middle Node in linear time\n");
    printf("6. Exit");

    while (choice != 6)
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
            printf("\nEnter the index of the new node to be inserted: ");
            scanf("%d", &insertIndex);
            insertNodeAtIndex(insertIndex);
            break;
        case 4:
            displayNode();
            break;
        case 5:
            displayMid();
            break;
        case 6:
            printf("\nExiting the program...\n");
            break;
        default:
            printf("Please choose a valid option.\n");
        }
    }

    return 0;
}