#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right)
{
    int i = left;
    int pivot = arr[right];
    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
            count++;
        }
    }
    swap(&arr[i], &arr[right]);
    count++;

    return i;
}

// Function to perform quicksort
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int partition_index = partition(arr, left, right);
        quickSort(arr, left, partition_index - 1);
        quickSort(arr, partition_index + 1, right);
    }
}

int *genRandomArray(int start, int end, int size)
{
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
    return arr;
}

void printArrToFile(char *fileName, int *arr, int size)
{
    FILE *file = fopen(fileName, "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);
}
int main()
{
    int start, end;
    char randomFile[50];
    char sortedFile[50];

    int size[] = {1000, 5000, 10000};
    int n = sizeof(size) / sizeof(size[0]);

    printf("\nEnter the starting number:");
    scanf("%d", &start);
    printf("\nEnter the ending number: ");
    scanf("%d", &end);

    printf("\nElements\tComparisons\n");
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int len = size[i];
        int *arr = genRandomArray(start, end, len);

        sprintf(randomFile, "randomArray_%d.txt", len);
        sprintf(sortedFile, "sortedArray_%d.txt", len);

        printArrToFile(randomFile, arr, len);
        count = 0;
        quickSort(arr, 0, len - 1); // use with any sorting algorithms
        printArrToFile(sortedFile, arr, len);
        printf("\n%d\t%d\n", len, count);
        free(arr);
    }
    return 0;
}