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

void insertNodeifEmpty(int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->next = newNode;
    head = newNode;
    tail = newNode;
}

void insertNodeFront(int value)
{
    if (head == NULL)
    {
        insertNodeifEmpty(value);
        return;
    }
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->next = tail->next;
    tail->next = newNode;
    head = newNode;
}

void displayNode()
{
    if (head == NULL)
    {
        printf("\nempty!!");
        return;
    }

    node *temp = head;
    printf("\n");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\nhead pointer: %d", head->data);
    printf("\ntail pointer: %d\n", tail->data);
}

void reverseList()
{
    node *prev = tail;
    node *curr = head;
    node *aftr = NULL;

    while (aftr != head)
    {
        aftr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = aftr;
    }

    tail = head;
    head = prev;
}
int main()
{
    int val;
    printf("\nEnter value to insert from front :");
    scanf("%d", &val);
    for (int i = 1; i <= val; i++)
    {
        insertNodeFront(i);
    }
    displayNode();
    reverseList();
    displayNode();
    // printf("\n%d", tail->next->data);
    return 0;
}