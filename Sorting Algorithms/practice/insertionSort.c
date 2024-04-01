#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i;
        while (key < arr[j - 1] && j > low)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

int main()
{
    int n = 10;
    int item;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        item = rand() % 101;
        arr[i] = item;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}