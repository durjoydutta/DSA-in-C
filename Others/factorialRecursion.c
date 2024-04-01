// factorial of a number using recursion
#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    return num * factorial(num - 1);
}

int main()
{
    int n;
    printf("Enter an integer value: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Number should be positive\n");
        return 0;
    }
    printf("\nThe factorial of %d is : %d\n", n, factorial(n));
    return 0;
}