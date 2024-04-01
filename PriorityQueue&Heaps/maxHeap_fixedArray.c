#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); // to heapify from the child index that was swapped
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = 0; i <= n-1; i++)
    {
        heapify(arr, n, i);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

int extractMax(int arr[], int *n)
{
    if (*n == 0)
        return -1; // Heap is empty

    int max = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return max;
}

void heapInsert(int arr[], int item, int *n)
{
    (*n)++;
    
    int i = *n - 1; // store the item index in a variable to iterate over

    while (i > 0 && arr[(i - 1) / 2] < item)
    {
        arr[i] = arr[(i-1)/2];
        i = (i-1)/2;
    }

    arr[i] = item;
}

void printTree(int arr[], int n, int index, int space)
{
    if (index >= n)
        return;

    space += 10;

    printTree(arr, n, 2 * index + 2, space);

    for (int i = 0; i <= space; i++)
        printf(" ");

    printf("%d\n", arr[index]);

    printTree(arr, n, 2 * index + 1, space);
}

int main()
{
    int arr[] = {34, 56, 78, 23,29, 40,63, 59};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int choice, item;

    printf("\n1. Build Max Heap taking array as input.\n");
    printf("2. Extract and remove Max element.\n");
    printf("3. Display heap as tree.\n");
    printf("4. Display heap as an array representation.\n");
    printf("5. Insert element into the heap\n");
    printf("6. Exit the program.\n\n");

    while (choice != 6)
    {
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            buildHeap(arr, n);
            printf("Heap built successfully!\n");
            break;

        case 2:
            if (n > 0)
            {
                int max = extractMax(arr, &n);
                printf("Extracted maximum element: %d\n", max);
            }
            else
            {
                printf("Heap is empty. No maximum element to extract.\n");
            }
            break;

        case 3:
            if (n < 1)
                printf("Heap is empty!\n");
            else
            {
                printf("Heap (tree format):\n");
                printTree(arr, n, 0, 0);
            }
            break;
        case 4:
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 5:
            printf("Enter the element to be inserted into the heap: ");
            scanf("%d", &item);
            heapInsert(arr, item, &n);
            printf("\nThe item %d is inserted successfully.", item);
            break;
        case 6:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
