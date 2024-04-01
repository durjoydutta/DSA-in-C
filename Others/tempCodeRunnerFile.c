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