#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkPrime(int num)
{
    if (num <= 1)
    {
        return 0; // not prime
    }

    int high = sqrt(num);

    for (int i = 2; i <= high; i++) // we can also use the condition i*i <= num (less lines of code and simpler)
    {
        if (num % i == 0)
        {
            return 0; // is not prime
        }
    }

    return 1; // is prime
}

int main()
{
    int num;
    printf("\nEnter your number to check if prime or not >>>> ");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        if (checkPrime(i) == 1)
        {
            printf("\nThe number %d is prime", i);
        }
        else
        {
            printf("\nThe number %d is not prime", i);
        }
    }
    return 0;
}