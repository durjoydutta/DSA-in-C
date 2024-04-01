#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    struct linkedList *prev;
    int data;
    struct linkedList *next;

} node;

node *head;
node *tail;

void addNodeFromFront(int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void addNodeFromBack(int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

int main()
{
    head = malloc(sizeof(node)); // initializing the first node
    head->data = 7;
    head->prev = NULL;
    head->next = NULL;
    tail = head; // head = tail for a single node

    addNodeFromFront(5);
    addNodeFromFront(3);
    addNodeFromBack(9);
    addNodeFromBack(11);
    node *temp = head;
    // printf("\nNodeAddress | nodePrev nodeValue  nodeNext\n");
    while (temp != NULL)
    {
        // printf("%u  |\t%u\t%d\t%u\n", temp, temp->prev, temp->data, temp->next);
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("The head is denoted by : %d\n", head->data);
    printf("The head is denoted by : %d\n", tail->data);
}