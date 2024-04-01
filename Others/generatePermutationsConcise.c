#include <stdio.h>
#include <string.h>

// Function to swap two characters in a string
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate all permutations of a string
void generatePermutations(char *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str); // Print the current permutation
    } else {
        for (int i = start; i <= end; i++) {
            // Swap the current character with the character at index 'i'
            swap(&str[start], &str[i]);

            // Recursively generate permutations for the substring str[start+1, end]
            generatePermutations(str, start + 1, end);

            // Backtrack by swapping back to the original arrangement
            swap(&str[start], &str[i]);
        }
    }
}

// Main function
int main() {
    char inputString[50];

    // Input the string from the user
    printf("Enter a string: ");
    scanf("%s", inputString);

    // Calculate the length of the string
    int len = strlen(inputString);

    // Generate and print all permutations
    printf("All permutations of the given string:\n");
    generatePermutations(inputString, 0, len - 1);

    return 0;
}
