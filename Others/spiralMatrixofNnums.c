#include <stdio.h>
#include <stdlib.h>

int getInputFromUser()
{   
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
}

void fillSpiralMatrix(int n, int matrix[n][n])
{
    int num = 1; //starting value of numbers to be filled
    int left = 0; int top = 0; // initial left and top index of matrix
    int right = n - 1; int bottom = n - 1; // initial right and bottom index of the matrix

    while (left <= right && top <= bottom)
    {
        // fill the top row left to right
        for (int i = left; i <= right; i++)
        {
            matrix[top][i] = num++;

        }
        top++; //shift top down by 1
        // fill the right col next top to bottom
        for (int i = top; i <= bottom; i++)
        {
            matrix[i][right] = num++;
        }
        right--; // shift right left by 1
        // fill the bottom row from right to left
        for (int i = right; i >= left; i--)
        {
            matrix[bottom][i] = num++;
        }
        bottom--; // shift bottom up by 1
        // fill the left row from bottom to top
        for (int i = bottom; i >= top; i--)
        {
            matrix[i][left] = num++;
        }
        left++; // shift left right by 1
    }
}

void printMatrix(int n, int matrix[n][n])
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}


int main()
{
    int n = getInputFromUser();

    int matrix[n][n];

    fillSpiralMatrix(n, matrix);
    printMatrix(n, matrix);
    
    return 0;
}

