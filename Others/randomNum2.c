#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Finding the max number in an array

void main()
{
    int low, high, len;
    low = 0;
    high = 1;
    len = 1000;
    int arraySize = len;

    FILE *file = fopen("randomArray.txt", "w");
    if (file == NULL)
    {
        printf("Error creating the file!");
    }

    int *myArray = (int *)(malloc(arraySize * sizeof(int)));
    if (myArray == NULL)
    {
        printf("Memory allocation failed. Exiting....");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < len; i++)
    {
        int randomNum = rand() % (high - low + 1) + low;
        myArray[i] = randomNum;
        fprintf(file, "%d, ", randomNum);
    }

    fclose(file);

    // counting the number of 1s in the array

    int cout = 0;
    int i = 0;
    while (i < len)
    {
        if (myArray[i] == 1)
        {
            cout += 1;
        }
        i += 1;
    }
    float prob = ((float)cout / len * 100);
    printf("The probability of winning the toss on a sample size of %d is : %.2f.\n", len, prob);

    if (prob > 50)
    {
        printf("It's Tails.");
    }
    else
    {
        printf("It's Heads.");
    }

    // printf("Random array generated in a seperate file.");
    free(myArray);
}