#include <stdio.h>
#include <stdlib.h>
int count = 0; // count no. of permutations
// int res[1000]; // array to store all possible permutations

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void genPerms(int *arr, int low, int high)
{
    if (low > high)
    {
        for (int i = 0; i <= high; i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
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
    int n, low, high;
    // creating the original array of size n
    printf("\nEnter the length of the number to generate permutations: ");
    scanf("%d", &n);
    int *nums = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }
    low = 0;
    high = n - 1;
    // generating the permutations and printing them
    genPerms(nums, low, high);
    printf("\nThe number of permutations generated is : %d\n", count);
    free(nums);
    return 0;
}