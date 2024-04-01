#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;

node *tail()
{
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void addNodeFront(int value) // new nodes will be added from the front (will become new head)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void addNodeBack(int value) // new nodes will be added from the front (will become new head)
{
    node *currTail;
    node *newTail = malloc(sizeof(node));
    newTail->data = value;
    newTail->next = NULL;
    if (head == NULL)
    {
        head = newTail;
        return;
    }
    else
    {
        currTail = tail();
        currTail->next = newTail;
    }
}

void displayNodes()
{
    node *temp = head;
    int count = 0;
    if (head == NULL)
    {
        printf("\nThe list is currently empty!");
        return;
    }
    while (temp != NULL)
    {
        printf("%d | %d \n", count, temp->data);
        temp = temp->next;
        count++;
    }
}

void findNode(int value)
{
    int index;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("\nThe node %d is present at index %d", value, index);
            return;
        }
        index++;
        temp = temp->next;
    }
    printf("\nThe node %d is not present in the list.", value);
}

void removeNode(int value)
{
    if (head == NULL)
    {
        printf("\nThe list is currently empty!");
        return;
    }
    else if (head->data == value)
    {
        head = head->next;
        printf("The node %d at index 0 was removed.", value);
        return;
    }

    node *prev = NULL;
    node *curr = head;
    int index = 0;

    while (curr != NULL && curr->data != value)
    {
        index++;
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL)
    {
        prev->next = curr->next;
        printf("The node %d at index %d was removed.", value, index);
        return;
    }
    printf("The node %d was not found in the list.", value);
}

void reverseList()
{
    node *prev = NULL;
    node *curr = head;
    node *after = NULL;

    while (curr != NULL)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    head = prev;
    printf("\nThe linked list is reversed.");
}

void operationMenu()
{
    int choice, frontVal, endVal, n1, n2, searchVal, removeVal;

    printf("\n\nChoose among the following Linked List operations::");
    printf("\n1. Insert from front.\n");
    printf("2. Insert at End\n");
    printf("3. Search\n");
    printf("4. Display\n");
    printf("5. Head Node\n");
    printf("6. Tail Node\n");
    printf("7. Delete a node\n");
    printf("8. Reverse the linked list.\n");
    printf("9. Exit\n");

    while (1)
    {

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("\nEnter the number of nodes you want to insert from the front: ");
            scanf("%d", &n1);

            srand(time(NULL));
            for (int i = 0; i < n1; i++)
            {
                frontVal = rand() % 101;
                addNodeFront(frontVal);
            }
            break;

        case 2:
            printf("\nEnter the number of nodes you want to insert from the tail: ");
            scanf("%d", &n2);
            srand(time(NULL));
            for (int i = 0; i < n2; i++)
            {
                endVal = rand() % 101;
                addNodeBack(endVal);
            }
            break;

        case 3:
            printf("\nEnter the node value you want to search: ");
            scanf("%d", &searchVal);
            findNode(searchVal);
            break;

        case 4:
            displayNodes();
            break;

        case 5:
            if (head == NULL)
            {
                printf("\nThe list is currently empty.");
                break;
            }
            printf("\nThe head node value is: %d", head->data);
            break;

        case 6:
            if (head == NULL)
            {
                printf("\nThe list is currently empty.");
                break;
            }
            int tailVal = tail()->data;
            printf("\nThe tail node value is : %d", tailVal);
            break;

        case 7:
            printf("\nEnter the node value you want to remove: ");
            scanf("%d", &removeVal);
            removeNode(removeVal);
            break;
        case 8:
            reverseList();
            break;
        case 9:
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }
}

int main()
{
    int value, n, searchVal, removeVal;

    operationMenu();
    return 0;
}