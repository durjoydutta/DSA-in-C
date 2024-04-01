#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int count = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int low, int high)
{
    for (int i = low; i <= high - 1; i++)
    {
        bool flag = false;
        for (int j = low; j <= high - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                count++;
                flag = true;
            }
        }
        if (!flag)
            return;
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
        bubbleSort(arr, 0, len - 1); // use with any sorting algorithms
        printArrToFile(sortedFile, arr, len);
        printf("\n%d\t%d\n", len, count);
        free(arr);
    }
    return 0;
}