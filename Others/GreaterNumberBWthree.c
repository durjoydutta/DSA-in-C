#include <stdio.h>
#include <stdlib.h>


int maxNum(int n1,int n2 , int n3) {

    printf("Enter First Number: \n");
    scanf("%d", &n1);
    printf("Enter Second Number: \n");
    scanf("%d", &n2);
    printf("Enter Third Number: \n");
    scanf("%d", &n3);

    if (n1 > n2) {
        if (n1 > n3) {
            printf("The number %d is the largest number.", n1);
        }
        else printf("The number %d is the largest number.",n3);
    }
    else if (n1 < n2) {
        if (n2 > n3) {
            printf("The number %d is the largest number.",n2);
        }
        else printf("The number %d is the largest number.",n3);
    }
   else if (n1 == n2) {
        if (n1 > n3) {
            printf("The number %d is the largest number.", n1);
        }
        else if (n1 < n3) {
            printf("The number %d is the largest number.", n3);
        }
        else printf("The numbers %d, %d, and %d are equal",n1, n2, n3);        
   }
}

int main() {
    int num1, num2, num3;

    maxNum(num1, num2, num3);

    return 0;
}