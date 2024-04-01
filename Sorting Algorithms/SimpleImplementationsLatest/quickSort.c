#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pii = partition(arr, low, high);
        quickSort(arr, low, pii - 1);
        quickSort(arr, pii + 1, high);
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
    quickSort(arr, 0, n - 1);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}