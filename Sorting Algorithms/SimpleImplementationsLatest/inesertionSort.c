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
{ // we assume left of each key to be inserted is already sorted. We need to find the right position for it to be inserted
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i]; // set the current element as the key
        int j = i;
        while (key < arr[j - 1] && j > 0) // while the key is smaller than the elements before it and also j > 0
        {
            arr[j] = arr[j - 1]; // keep right shifting the elements
            j--;
        }
        arr[j] = key; // inserting the key into the right index
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