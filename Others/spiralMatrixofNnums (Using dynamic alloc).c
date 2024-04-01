// spiral matrix
#include <stdio.h>
#include <stdlib.h>

int** fillSpiralMatrix(int n)
{
    int left = 0;
    int top  = 0;
    int right = n - 1;
    int bottom = n - 1;
    int **arr = malloc((n*n) * sizeof(int)); // initializing a n*n square matrix
    for (int i = 0; i < n; i++) 
    {
        arr[i] = malloc(n * sizeof(int)); 
    }

    int num = 1; // initial number to be inserted into the 2d array spirally and incremented

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            arr[top][i] = num++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            arr[i][right] = num++;
        }
        right--;
        for (int i = right; i >= left; i--)
        {
            arr[bottom][i] = num++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            arr[i][left] = num++;
        }
        left++;
    }

    return arr;
}

void printMatrix(int **array, int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            printf("%d ", array[row][col]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    int **spiralMatrix;

    printf("\nEnter the number of rows/columns for the square spiral matrix: ");
    scanf("%d", &n);

    spiralMatrix = fillSpiralMatrix(n);
    printMatrix(spiralMatrix, n);
    
    return 0;
}