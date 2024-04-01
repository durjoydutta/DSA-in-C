// to do - enqueue, dequeue , count of elements, status of queue with elements and index
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5

int circQueue[MAX_QUEUE_SIZE];

int rear = -1, front = -1;

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
    int nextRearIndex = (rear + 1) % MAX_QUEUE_SIZE;
    if (nextRearIndex == front)
    {
        return 1;
    }
    return 0;
}

void enqueue(int item)
{
    if (isFull())
    {
        printf("\nThe queue is currently full!");
        return;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
    }
    circQueue[rear] = item;
    printf("Inserted the element %d into the queue at index %d\n", item, rear);
}

void dequeue()
{
    int item, pos;

    if (isEmpty())
    {
        printf("\nThe queue is currently empty!");
        return;
    }
    else if (front == rear) // when only 1 element present
    {
        pos = front;
        item = circQueue[front];
        front = -1;
        rear = -1;
    }
    else
    {
        pos = front;
        item = circQueue[front];
        front = (front + 1) % MAX_QUEUE_SIZE;
    }
    printf("Removed the item %d at index %d from the queue\n", item, pos);
}

int queueCount()
{
    int count;
    if (isEmpty())
        count = 0;
    else
        count = (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE + 1;
    printf("Currently the queue has %d out of a maximum of %d elements\n", count, MAX_QUEUE_SIZE);
}

int queueStatus()
{
    int i = front;

    if (isEmpty())
    {
        printf("\nThe queue is currently empty!");
    }
    printf("The circular queue is currently : ");

    printf("[ ");
    do
    {
        printf("%d ", circQueue[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;

    } while (i != (rear + 1) % MAX_QUEUE_SIZE);
    printf("]");

    printf("\nFront => %d \t\t Rear => %d", circQueue[front], circQueue[rear]);
    printf("\nFront Index => %d \t Rear Index => %d\n", front, rear);
    queueCount();
}
int main()
{
    int userChoice, num, item;

    // choices for queue operations
    printf("///Circular Queue Operations///\n\n");
    printf("\nChoose a number b/w 1 and 5:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Count of elements in Queue\n");
    printf("4. Status of queue\n");
    printf("5. Exit\n\n");
    printf("The maximum queue size is : %d\n", MAX_QUEUE_SIZE);

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &userChoice);
        switch (userChoice)
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
            queueCount();
            break;
        case 4:
            queueStatus();
            break;
        case 5:
            exit(0);
        default:
            printf("Please try again by entering a valid choice.\n");
        }
    } while (userChoice != 5);
}