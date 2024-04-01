#include <stdio.h>
#include <stdlib.h>


int maxNum(int n1,int n2) {

    printf("Enter First Number: \n");
    scanf("%d", &n1);
    printf("Enter Second Number: \n");
    scanf("%d", &n2);

    if (n1 > n2) {
        printf("The number %d is greater than number %d", n1,n2);
    }
    else if (n1 == n2) {
        printf("The numbers %d and %d are equal.",n1,n2);
    }
    else printf("The number %d is greater than number %d",n2, n1);
}

int main() {
    int num1, num2;

    maxNum(num1, num2);

    return 0;
}