#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    int res;
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    int a0 = 0; int a1 = 1;
    for (int i = 2; i <= n; i++)
    {
        res = a0 + a1;
        a0 = a1;
        a1 = res;
    }
    return res;
}

int main()
{
    int num;
    printf("\nEnter the number: ");
    scanf("%d", &num);
    for (int i =0; i <= num; i++)
        printf("%d ", fibonacci(i));
    return 0;
}