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

void insertionSort(int arr[], int low, int high)
{ // we assume left of each key to be inserted is already sorted. We need to find the right position for it to be inserted
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i]; // set the current element as the key
        int j = i;
        while (key < arr[j - 1] && j > 0) // while the key is smaller than the elements before it and also j > 0
        {
            arr[j] = arr[j - 1]; // keep right shifting the elements
            count++;
            j--;
        }
        arr[j] = key; // inserting the key into the right index
        count++;
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
        insertionSort(arr, 0, len - 1); // use with any sorting algorithms
        printArrToFile(sortedFile, arr, len);
        printf("\n%d\t%d\n", len, count);
        free(arr);
    }
    return 0;
}