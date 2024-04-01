// Singly Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int data;
    struct linkedList *next;

} node;

node *head = NULL;
node *newNode;

node *createNode()
{
    int i, num, value;

    printf("\nEnter the number of nodes in the linked list: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("\nEnter the value at node %d to be stored: ", i);
        scanf("%d", &value);

        newNode = (node *)malloc(sizeof(node));
        newNode->data = value;
        newNode->next = head;

        head = newNode;
    }

    return head;
}

int main()
{
    int i;
    createNode();

    node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}