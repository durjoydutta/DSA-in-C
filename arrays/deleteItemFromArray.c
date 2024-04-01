#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int linearSearch(int arr[], int item, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == item)
        {
            return i;
        }
    }
    return -1;
}

int delItemFromArray(int arr[], int delItem, int *n)
{
    // First search for the index of the item
    int delIndex = linearSearch(arr, delItem, *n);
    printf("%d\n", delIndex);
    // Shift elements to the left to delete the item
    for (int i = delIndex; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*n)--; // Decrement array size

    return delIndex;
}


int main()
{
    int n = 10;
    int myArr[n];
    int item, delIndex;


    srand(time(NULL));
    for (int j = 0; j < n; j++)
    {
        myArr[j] = rand() % 101;
    }
    for (int j = 0; j < n; j++)
    {
        printf("%d ", myArr[j]);
    }
    printf("\nEnter the item in the array you want to delete: ");
    scanf("%d", &item);
    delIndex = delItemFromArray(myArr, item, &n);
    printf("\nLets delete item %d at index %d from the array: \n", item, delIndex);
    for (int j = 0; j < n; j++)
    {
        printf("%d ", myArr[j]);
    }
    return 0;
}