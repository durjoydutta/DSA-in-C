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

void insertionSort(int arr[], int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i;
        while (arr[j] < arr[j-1] && j > 0)
        {
            arr[j] = arr[j-1];
            j--;
        }
        swap(&arr[j], &key);
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
    insertionSort(arr, 0, n - 1);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}