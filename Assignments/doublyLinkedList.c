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
    node *newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBack(int val)
{

    node *newNode = createNode(val);
    if (!head)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void displayNode()
{
    if (!head)
    {
        printf("No elements present in the linked list!\n");
        return;
    }
    node *temp = head;
    printf("\nThe singly linked list is: ");
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Head:\t%d\n", head->data);
    printf("Tail:\t%d\n", tail->data);
}

void displayReverse()
{
    if (!head)
    {
        printf("No elements present in the linked list!\n");
        return;
    }
    node *temp = tail;
    printf("\nThe singly linked list is: ");
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
    printf("Head:\t%d\n", head->data);
    printf("Tail:\t%d\n", tail->data);
}

int main()
{
    int n, val, choice, midElement;

    printf("\n\nChoose among the following operations to perform on a sinlgy linked list::");

    printf("\n1. Insert n (randomly generated) Elements  in the Linked List\n");
    printf("2. Display the full linked list\n");
    printf("3. Delete second last element from the list\n");
    printf("4. Reverse the elements in the linked list.\n");
    printf("5. Print the middle element of the list.\n");
    printf("6. Exit\n");

    while (choice != 6)
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
            displayNode();
            break;
        case 3:
            displayReverse();
            break;
        case 4:
            // reverseLinkedList();
            break;
        case 5:
            // printMiddleElement();
            break;
        case 6:
            printf("Exiting the program..\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }
}