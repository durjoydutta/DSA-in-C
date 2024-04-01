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

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int *temp = malloc((high - low + 1) * sizeof(int));
    int k = 0;

    while (i <= mid && j <= high)
    {
        count++;
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
        mergeSort(arr, 0, len - 1); // use with any sorting algorithms
        printArrToFile(sortedFile, arr, len);
        printf("\n%d\t%d\n", len, count);
        free(arr);
    }
    return 0;
}