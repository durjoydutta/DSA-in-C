#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) // low = left most index || high = right most index
{
    int i, j, pivot;
    i = low - 1;
    // pivot = rand() % (high - low) + low;
    pivot = high;
    for (j = low; j < high; j++)
    {
        if (arr[j] <= arr[pivot])
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[pivot];
    arr[pivot] = temp;

    return i + 1; // return partition index
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(arr, low, high);
        quickSort(arr, low, partition_index - 1);
        quickSort(arr, partition_index + 1, high);
    }
}

int *genUnsortedArrayToFile(int start, int end, int size)
{
    char *fileName = "unsortedArray.txt";
    int *unsortedArr = (int *)malloc(sizeof(int) * size);

    if (unsortedArr == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return NULL;
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        unsortedArr[i] = rand() % abs(end - start + 1) + start; // creating random numbers within given range
    }

    FILE *unsortedFile = fopen(fileName, "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(unsortedFile, "%d\n", unsortedArr[i]);
    }
    fclose(unsortedFile);

    printf("\nThe unsorted array of pseudo random sizebers is generated in file : <%s>.\n", fileName);
    return unsortedArr;
}

void printSortedArrayToFile(int arr[], int size)
{
    char *fileName = "sortedArray.txt";

    FILE *sortedFile = fopen(fileName, "w");
    int i = 0;
    for (i = 0; i < size; i++)
    {
        fprintf(sortedFile, "%d\n", arr[i]);
    }
    fclose(sortedFile);

    printf("\nThe sorted array is printed in file : <%s>.\n", fileName);
}

int main()
{
    int start, end, size;

    printf("\nEnter the starting number:");
    scanf("%d", &start);
    printf("\nEnter the ending number: ");
    scanf("%d", &end);
    printf("\nEnter the length of array: ");
    scanf("%d", &size);

    int *arr = genUnsortedArrayToFile(start, end, size); // generating <size> random sizebers between start-end
    quickSort(arr, 0, size - 1);                         // sorting the array using quicksort
    printSortedArrayToFile(arr, size);                   // printing the sorted array to file
    free(arr);
    return 0;
}
