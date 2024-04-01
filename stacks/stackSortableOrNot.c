#include <stdio.h>
#include <stdlib.h>

// Function to sort the array using a stack
// We have an input array from user. We use a stack to try and sort the array, by push/pop operations.
// We pop the items from the stack and store them in another OUTPUT array. 
int* stackSort(int arr[], int n) {
    int *output = (int *)malloc(n * sizeof(int)); // to store the sorted array after stack sorting
    int stack[n];
    int stackIndex = 0;
    int outputIndex = 0;

    stack[stackIndex++] = arr[0]; // Push the first element

    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] <= arr[i]) {
            // If the current element is less than or equal to the previous one,
            // push it onto the stack
            stack[stackIndex++] = arr[i + 1];
        } else {
            // If the current element is greater than the previous one,
            // pop from the stack and append to the output
            output[outputIndex++] = stack[--stackIndex];
            stack[stackIndex++] = arr[i + 1];
        }
    }

    // Pop any remaining elements from the stack
    while (stackIndex > 0) {
        output[outputIndex++] = stack[--stackIndex];
    }

    return output;
}


// Function to check if the OUTPUT array obtained from stackSort func is sorted
int isSorted(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (array[i] > array[i+1]) {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Get the array elements from the user
    printf("Enter the array elements separated by space: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using stackSort function
    int* finalArr = stackSort(arr, n);

    // Check if the array is sorted
    int result = isSorted(finalArr, n);

    // Display the result
    printf("\nGiven array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nAfter stack sorting the array, we get: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", finalArr[i]);
    }

    if (result == 1) {
        printf("\n\nThe given array is stack sortable.\n");
    } else {
        printf("\n\nThe given array is not stack sortable.\n");
    }


    free(finalArr);
    return 0;
}
