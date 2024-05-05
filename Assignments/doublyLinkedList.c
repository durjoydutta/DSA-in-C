#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXVAL 100 // maximum value of item that will be inserted in the linkedlist
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

void displayList()
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

void deleteFirstElement()
{
    if (!head) // when empty
    {
        printf("No elements present in the linked list!\n");
        return;
    }
    if (!head->next) // when single item present
    {
        head = NULL;
        tail = NULL;
        free(head);
        free(tail);
        return;
    }
    int deletedVal = head->data;
    node *temp = head;
    temp->next->prev = temp->prev;
    head = temp->next;
    free(temp);
    printf("The first element with value %d is deleted.\n", deletedVal);
}

void printFreqOfElements()
{
    if (!head)
    {
        printf("No elements present in the linked list!\n");
        return;
    }

    node *current = head;
    int frequency[MAXVAL + 1] = {0}; // Assuming elements are in the range 0 to 100

    // Count frequency of each element
    while (current != NULL)
    {
        frequency[current->data]++;
        current = current->next;
    }

    // Print frequency of each element
    printf("\nFrequency of elements in the linked list:\n");
    printf("Element\tFrequency\n");
    for (int i = 0; i <= MAXVAL; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%d\t%d\n", i, frequency[i]);
        }
    }
}

void insertElementAtThird(int val)
{
    if (!head || !head->next) // when list is empty or only one element
    {
        printf("\nCan't insert element at third position if less than two nodes are present in the list!");
        return;
    }
    else if (!head->next->next) // when only two items are present
    {
        insertAtBack(val);
    }
    else
    {
        node *temp = head->next;
        node *newNode = createNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    printf("\nInserted the node with value %d at third position.", val);
}

int main()
{
    int n, val, choice, newElement;

    printf("\n\nChoose among the following operations to perform on a doubly linked list::");
    printf("\n1. Insert n (randomly generated) Elements  in the Linked List\n");
    printf("2. Display the full list\n");
    printf("3. Delete first element from the list\n");
    printf("4. Print the frequency of each element in the list.\n");
    printf("5. Insert a new element at third position in the list.\n");
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
                val = rand() % (MAXVAL + 1); // values to be randomly generated between 0 and 50
                insertAtBack(val);
            }
            break;
        case 2:
            displayList();
            break;
        case 3:
            deleteFirstElement();
            break;
        case 4:
            printFreqOfElements(MAXVAL);
            break;
        case 5:
            printf("\nEnter the node element to be inserted (between 0 and %d) : ", MAXVAL);
            scanf("%d", &newElement);
            insertElementAtThird(newElement);
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