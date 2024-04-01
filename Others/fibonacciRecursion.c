// fibonacci
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int num){
    if (num <= 0){
        return -1;
    }
    else if (num == 1) {
        return 0;
    }
    else if (num == 2) {
        return 1;
    }

    return fibonacci(num-1) + fibonacci(num-2);
}

int main() {
    int num , result;

    do {
    printf("Enter the element number: ");
    scanf("%d", &num);

    result = fibonacci(num);

    if (result == -1) {
        printf("Please enter a positive integer.\n");
    }
    } while (result == -1);

    printf("The %dth fibonacci number is: %d", num, result);
    
    return 0;
}