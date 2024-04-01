#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int data;
    struct linkedList *next;

} node;

node *head;

void createNode() // create nodes from head of linked list
{
    int num, value;
    head = NULL;
    printf("Enter the number of nodes : ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        node *newNode = (node *)malloc(sizeof(node));
        printf("\nEnter the value of node: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = head;

        head = newNode;
    }
}

int countNodes()
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int search(int target)
{
    int index = 0;

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            printf("\nThe number %d is present at node index %d.", target, index);
            return 1;
        }
        index++;
        temp = temp->next;
    }
    printf("\nThe number %d is not in the linked list.\n", target);
    return 0;
}

void insertNodeFromHead(int value)
{
    node *newHead = (node *)malloc(sizeof(node));
    newHead->data = value;
    newHead->next = head;

    head = newHead;
    printf("%d inserted at the front.", value);
}

void insertNodeFromTail(int value)
{
    node *newTail = (node *)malloc(sizeof(node));
    node *temp = head;

    newTail->data = value;
    newTail->next = NULL;

    if (head == NULL)
    {
        head = newTail;
        printf("%d inserted at the end.", value);
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newTail;
    printf("%d inserted at the end.", value);
}

void printNodes()
{
    node *temp = head;
    printf("\nNodeAddress | nodeValue  nodeNext\n");
    while (temp != NULL)
    {
        if (temp->next == 0)
        {
            printf("%u\t%d\tNULL\n", temp, temp->data);
            break;
        }
        printf("%u\t%d\t%u\n", temp, temp->data, temp->next);
        temp = temp->next;
    }
}

void deleteNode(int value)
{
    if (head == NULL)
    { // if empty
        printf("The linked list is empty.\n");
        return;
    }

    // Check if the value in first node
    if (head->data == value)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        printf("Node with value %d deleted.\n", value);
        return;
    }

    node *prev = head;
    node *temp = prev->next;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            prev->next = temp->next;
            free(temp);
            printf("Node with value %d deleted.\n", value);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("The given value is not in the linked list.\n");
}

void reverseList()
{
    node *prev = NULL;
    node *current = head;
    node *after;

    while (current != NULL)
    {
        after = current->next;
        current->next = prev;
        prev = current;
        current = after;
    }
    head = prev;

    printf("The linked list is reversed.\n");
}

int main()
{

    int choice, data, target, count, deleteValue;

    createNode();

    printf("\n\nChoose among the following Linked List operations::");
    printf("\n1. Insert from front.\n");
    printf("2. Insert at End\n");
    printf("3. Search\n");
    printf("4. Display\n");
    printf("5. Count Nodes\n");
    printf("6. Delete a node\n");
    printf("7. Reverse the linked list.\n");
    printf("8. Exit\n");

    while (1)
    {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter data to insert at the front: ");
            scanf("%d", &data);
            insertNodeFromHead(data);
            break;

        case 2:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            insertNodeFromTail(data);
            break;

        case 3:
            printf("\nEnter the number you want to search for: ");
            scanf("%d", &target);
            search(target);
            break;

        case 4:
            printNodes();
            break;

        case 5:
            count = countNodes();
            printf("\nThe linked list has %d nodes.\n", count);
            break;

        case 6:
            printf("\nEnter the number you want to delete: ");
            scanf("%d", &deleteValue);
            deleteNode(deleteValue);
            break;
        case 7:
            reverseList();
            break;
        case 8:
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}