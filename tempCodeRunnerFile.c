#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int index, int size)
{
    int largest = index;
    int left = index * 2 + 1;
    int right = 2 * index + 2;

    if (arr[left] > arr[largest] && left < size)
    {
        largest = left;
    }
    if (arr[right] > arr[largest] && right < size)
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(&arr[index], &arr[largest]);
        heapify(arr, largest, size);
    }
}

void buildHeap(int *arr, int size)
{
    for (int i = size/2 - 1; i >= 0; i--)
    {
        heapify(arr, i, size);
    }
}

void heapSort(int *heap, int size)
{
    for (int i = 0; i < size; i++)
    {
        swap(&heap[0], &heap[size - i - 1]);
        heapify(heap, 0, size - i - 1);
    }
}

int extractMax(int *heap, int *size)
{
    int max = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, 0, *size - 1);
    return max;
}

void heapInsert(int *heap, int val, int *size)
{
    (*size)++;
    int i = *size - 1;
    while (i > 0 && val > heap[i/2 - 1])
    {
        heap[i] = heap[i/2 - 1];
        i = i/2 - 1;
    }
    heap[i] = val;
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
    buildHeap(arr, n);
    printf("\nUnsorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int max = extractMax(arr, &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    heapInsert(arr, 75, &n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}