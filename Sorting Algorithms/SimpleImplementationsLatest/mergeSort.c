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

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int *temp = malloc((high - low + 1) * sizeof(int));
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int l = low; l <= high; l++)
    {
        arr[l] = temp[l - low];
    }

    free(temp);
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    mergeSort(arr, 0, n - 1);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}