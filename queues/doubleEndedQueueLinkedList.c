#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node; // struct for linked list node

typedef struct Deque
{
    Node *front;
    Node *rear;
} Deque; // struct for double ended queue

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

Deque *createDeque()
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    if (deque != NULL)
    {
        deque->front = NULL;
        deque->rear = NULL;
    }
    return deque;
}

void insertFront(Deque *deque, int data)
{
    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    if (deque->front == NULL)
    {
        deque->front = newNode;
        deque->rear = newNode;
    }
    else
    {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }

    printf("Inserted %d at the front.\n", data);
}

void insertEnd(Deque *deque, int data)
{
    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    if (deque->rear == NULL)
    {
        deque->front = newNode;
        deque->rear = newNode;
    }
    else
    {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }

    printf("Inserted %d at the end.\n", data);
}

void removeFromFront(Deque *deque)
{
    if (deque->front == NULL)
    {
        printf("Deque is empty. Cannot remove from the front.\n");
        return;
    }

    Node *temp = deque->front;
    int data = temp->data;

    if (deque->front == deque->rear)
    {
        deque->front = NULL;
        deque->rear = NULL;
    }
    else
    {
        deque->front = temp->next;
        deque->front->prev = NULL;
    }

    free(temp);

    printf("Removed %d from the front.\n", data);
}

void removeFromEnd(Deque *deque)
{
    if (deque->rear == NULL)
    {
        printf("Deque is empty. Cannot remove from the end.\n");
        return;
    }

    Node *temp = deque->rear;
    int data = temp->data;

    if (deque->front == deque->rear)
    {
        deque->front = NULL;
        deque->rear = NULL;
    }
    else
    {
        deque->rear = temp->prev;
        deque->rear->next = NULL;
    }

    free(temp);

    printf("Removed %d from the end.\n", data);
}

void displayDeque(Deque *deque)
{
    if (deque->front == NULL)
    {
        printf("Deque is empty.\n");
        return;
    }

    Node *current = deque->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    Deque *deque = createDeque();
    int choice, data;

    printf("\nMenu:\n");
    printf("1. Insert at Front\n");
    printf("2. Insert at End\n");
    printf("3. Remove from Front\n");
    printf("4. Remove from End\n");
    printf("5. Display Deque\n");
    printf("6. Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the front: ");
            scanf("%d", &data);
            insertFront(deque, data);
            break;
        case 2:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            insertEnd(deque, data);
            break;
        case 3:
            removeFromFront(deque);
            break;
        case 4:
            removeFromEnd(deque);
            break;
        case 5:
            printf("Deque: ");
            displayDeque(deque);
            break;
        case 6:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    free(deque);

    return 0;
}
