#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *genArrayToFile() {
    int start, end, num;

    printf("Enter the starting number: \n");
    scanf("%d", &start);
    printf("Enter the ending number: \n");
    scanf("%d", &end);
    printf("Enter the length of array: \n");
    scanf("%d", &num);

    // Create an array to store pseudo-random numbers
    int *randomNumbers = (int *)malloc(num * sizeof(int));
    if (randomNumbers == NULL) {
        printf("Memory allocation failed!");
        return NULL;
    }

    for (int i = 0; i < num ; i++) {
        randomNumbers[i] = rand() % abs(end-start+1) + start;
    }

    FILE *file = fopen("myArray.txt", "w");
    if (file == NULL) {
        printf("Error generating the file!");
        return NULL;
    }
    for (int i= 0; i< num; i++) {
        
        fprintf(file, "%d, ", randomNumbers[i]);
    }
    fclose(file);
    printf("Array is printed to file 'myArray.txt'. \n");

    return randomNumbers;
}

int main() {
    genArrayToFile();
    return 0;
}

