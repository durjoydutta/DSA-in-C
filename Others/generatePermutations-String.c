#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0; // count no. of permutations

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void genPerms(char *arr, int low, int high)
{
    if (low > high)
    {
        printf("\n");
        for (int i = 0; i <= high; i++)
        {
            printf("%c", arr[i]);
        }
        count++;
        return;
    }

    for (int i = low; i <= high; i++)
    {
        // we are swapping by reference instead of value to actually change the array
        swap(&arr[low], &arr[i]);     // to swap the first item with the consecutive items
        genPerms(arr, low + 1, high); // to swap rest of the elements recursively in similar way
        swap(&arr[low], &arr[i]);     // backtrack by undoing the swap and restore the original array
    }
}

int main()
{
    char str[100];
    int len, low, high;
    // creating the original array of size n
    printf("\nEnter string of n characters: ");
    scanf("%s", str);
    len = strlen(str);
    low = 0;
    high = len - 1;
    // generating the permutations and printing them
    genPerms(str, low, high);
    printf("\nThe number of permutations generated is : %d\n", count);

    return 0;
}