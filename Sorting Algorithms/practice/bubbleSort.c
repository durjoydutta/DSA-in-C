#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false; // refers to swap status
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = true; // swap occurs so flag true
            }
        }
        if (!flag)
            return; // extra check to not repeat same thing again and again when already sorted
    }
}

int main()
{
    int n = 10;
    int item;
    int *arr = malloc(n * sizeof(int));
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
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}