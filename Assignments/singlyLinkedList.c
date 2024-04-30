#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node // struct def for a singly ll
{
    int data;
    struct Node *next;
} node;

node *head = NULL;
node *tail = NULL; // initial head and tail of the ll points to NULL as empty

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNodesFromTail(int value)
{
    node *newNode = createNode(value);
    if (!head) // if list is empty
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
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

void deleteSecondLast()
{
    if (!head || !head->next) // if empty or only single element present
    {
        printf("Not enough elements to delete second last!\n");
        return;
    }

    // If there are only two elements
    if (head->next->next == NULL)
    {
        free(head);
        head = tail;
        return;
    }

    node *temp = head;
    while (temp->next->next != tail) // traverse to the third last element
    {
        temp = temp->next;
    }
    node *toBeDeleted = temp->next;
    temp->next = tail;

    printf("Deleted the second last element %d\n", toBeDeleted->data);
    free(toBeDeleted); // freeing the memory of the deleted element
}

void reverseLinkedList()
{
    if (!head)
    {
        printf("No elements present in the linked list to reverse!\n");
        return;
    }

    node *prev = NULL;
    node *curr = head; // we need three pointers to reassign each element's next pointers and then traverse through the list
    node *after = NULL;

    while (curr)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    tail = head; // reassign the head and tail pointers after reversing
    head = prev;
}

void printMiddleElement()
{
    if (!head)
    {
        printf("No elements present in the linked list!\n");
        return;
    }

    node *slowPTR = head;
    node *fastPTR = head;

    while (fastPTR != NULL && fastPTR->next != NULL)
    {
        slowPTR = slowPTR->next;
        fastPTR = fastPTR->next->next;
    }

    printf("The middle element of the linked list is: %d\n", slowPTR->data);
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
                insertNodesFromTail(val);
            }
            break;
        case 2:
            displayNode();
            break;
        case 3:
            deleteSecondLast();
            break;
        case 4:
            reverseLinkedList();
            break;
        case 5:
            printMiddleElement();
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