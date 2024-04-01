#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int *genArrayToFile(int start, int end, int num)
{
    // Create an array to store pseudo-random numbers
    int *randomNumbers = (int *)malloc(num * sizeof(int));
    if (randomNumbers == NULL)
    {
        printf("Memory allocation failed!");
        return NULL;
    }

    for (int i = 0; i < num; i++)
    {
        randomNumbers[i] = rand() % abs(end - start + 1) + start;
    }

    FILE *file = fopen("randomArray.txt", "w");
    if (file == NULL)
    {
        printf("Error generating the file!");
        return NULL;
    }
    for (int i = 0; i < num; i++)
    {

        fprintf(file, "%d, ", randomNumbers[i]);
    }
    fclose(file);
    printf("Array is printed to file 'randomArray.txt'. \n");

    return randomNumbers;
}

void printSortedArrayToFile(int arr[], int num)
{
    FILE *file = fopen("sortedArray.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < num; i++)
    {
        fprintf(file, "%d, ", arr[i]);
    }

    fclose(file);
    printf("Sorted array is printed to file.\n");
}

int main()
{
    int start, end, num;

    printf("Enter the starting number: \n");
    scanf("%d", &start);
    printf("Enter the ending number: \n");
    scanf("%d", &end);
    printf("Enter the length of array: \n");
    scanf("%d", &num);

    int *array = genArrayToFile(start, end, num);
    // mergeSort(array,start, num - 1); //use with any sorting algorithms
    printSortedArrayToFile(array, num);
    free(array);
    return 0;
}
