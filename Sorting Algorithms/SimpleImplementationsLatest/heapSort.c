#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

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
    {
        largest = left;
        count++;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
        count++;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); // to heapify from the child index that was swapped
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n = 10;
    srand(time(NULL));
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 101;
    }
    printf("\nUnsorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    heapSort(arr, n);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
