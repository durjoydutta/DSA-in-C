#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }

    int res = 1;
    for (int i = 2; i <= num; i++)
    {
        res *= i;
    }
    return res;
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