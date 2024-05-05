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

node *createNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

void insertAtBack(int val)
{
    node *newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail = newNode;
    }
}

void displayList()
{
    if (!head)
    {
        printf("No elements present in the linked list!\n");
        return;
    }
    node *temp = head;
    printf("\nThe circular doubly linked list is: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\nHead:\t%d\n", head->data);
    printf("Tail:\t%d\n", tail->data);
}

int main()
{
    int n, val, choice;

    printf("\n\nChoose among the following operations to perform on a circular doubly linked list::\n");

    printf("\n1. Insert n (randomly generated) Elements  in the Linked List\n");
    printf("2. Display the full list\n");
    printf("3. Exit\n");

    while (choice != 3)
    {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the number of elements you want to insert: ");
            scanf("%d", &n);
            srand(time(NULL));
            for (int i = 0; i < n; i++)
            {
                val = rand() % 101;
                insertAtBack(val);
            }
            break;
        case 2:
            displayList();
            break;
        case 3:
            printf("Exiting the program..\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }
}