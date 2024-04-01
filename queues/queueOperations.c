#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5
int queue[MAX_QUEUE_SIZE];

int rear = -1, front = -1;

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

// to check if the queue is empty
int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

// to check if the queue is full
int isFull()
{
    if (rear == MAX_QUEUE_SIZE - 1)
    {
        return 1;
    }
    return 0;
}

// to insert element into the queue
void enqueue(int item)
{ // elements will be inserted to the rear of the queue
    if (isFull())
    {
        printf("The queue is currently full!\n");
        return;
    }

    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else // all other cases
    {
        rear++;
    }
    queue[rear] = item;
    printf("Inserted the element %d into the queue at position %d\n", item, rear);
}

void dequeue()
{
    int item, pos;

    if (isEmpty())
    {
        printf("The queue is currently empty!");
        return;
    }
    else if (front == rear) // when only one item is present in queue
    {
        pos = front;
        item = queue[front];
        front = -1;
        rear = -1;
    }
    else
    {
        pos = front;
        item = queue[front++];
    }
    printf("Removed the item %d at index %d from the queue\n", item, pos);
}

void displayQueue()
{
    if (isEmpty())
    {
        printf("The queue is empty!");
        return;
    }
    printf("The queue elements are :\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t%d\n", i, queue[i]);
    }
    printf("\n");
}

void reverseQueue()
{
    if (isEmpty())
    {
        printf("The queue is empty!");
        return;
    }
    int currFront = front;
    int currRear = rear;
    while (currFront < currRear)
    {
        swap(&queue[currFront], &queue[currRear]);
        currFront++;
        currRear--;
    }
}

int queueFront()
{ // to display the current top element of the stack
    if (isEmpty())
    {
        printf("The queue is empty!");
        return -1;
    }
    printf("The current front of the queue is: %d\n", queue[front]);
}

int queueRear()
{ // to display the current top element of the stack
    if (isEmpty())
    {
        printf("The queue is empty!");
        return -1;
    }
    printf("The current rear of the queue is: %d\n", queue[rear]);
}

int queueCount()
{
    int currCount;

    if (isEmpty())
        currCount = 0;
    else
        currCount = rear - front + 1; // As rear >= front

    printf("Currently the queue has %d out of a maximum of %d elements\n", currCount, MAX_QUEUE_SIZE);
}

int main()
{
    int choice, item, num;

    // choices for queue operations
    printf("\nChoose a number b/w 1 and 7\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display the Queue\n");
    printf("4. Display front element\n");
    printf("5. Display rear element\n");
    printf("6. Current count of elements\n");
    printf("7. Reverse the queue\n");
    printf("8. Exit\n\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter how many elements you want to enqueue: ");
            scanf("%d", &num);
            srand(time(NULL));
            for (int i = 0; i < num; i++)
            {
                item = rand() % 101;
                enqueue(item);
            }
            break;
        case 2:
            dequeue();
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            queueFront();
            break;
        case 5:
            queueRear();
            break;
        case 6:
            queueCount();
            break;
        case 7:
            reverseQueue();
            break;
        case 8:
            printf("Exiting the program..\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}