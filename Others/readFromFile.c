#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

int main()
{
    FILE *fptr = fopen("numbers.txt", "r");

    if (fptr == NULL)
    {
        printf("Error opening the file!\n");
        return 1;
    }
    int value;
    int i = 0;
    int *myArray = NULL;

    while (fscanf(fptr, "%d", &value) != EOF)
    {
        printf("%d ", value);

        myArray = (int *)realloc(myArray, (i + 1) * sizeof(int));
        myArray[i] = value;
        i++;
    }

    fclose(fptr);
    free(fptr);
    return 0;
}
