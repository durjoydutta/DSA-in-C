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

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArrayToFile(char *fileName, int arr[], int n)
{
    FILE *filePtr = fopen(fileName, "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(filePtr, "%d\n", arr[i]);
    }
    fclose(filePtr);
}

int main()
{
    int n;

    int sizes[] = {1000, 5000, 10000, 50000};
    int len = sizeof(sizes) / sizeof(sizes[0]);

    for (int j = 0; j < len; j++)
    {
        n = sizes[j];
        int *arr = malloc(n * sizeof(int));
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 10000;
        }

        char randomFileName[50];
        char sortedFileName[50];

        sprintf(randomFileName, "randomArray_%d.txt", n);
        sprintf(sortedFileName, "heapSortedArray_%d.txt", n);

        printArrayToFile(randomFileName, arr, n);
        count = 0;
        heapSort(arr, n);
        printArrayToFile(sortedFileName, arr, n);
        printf("\nThe total number of comparisons for %d elements is : %d\n", n, count);
        free(arr);
    }

    return 0;
}
