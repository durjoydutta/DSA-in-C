#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse(char string[]){

    int len = strlen(string);
    char* reversed = (char*)malloc((len + 1) * sizeof(char));
    
    int i = 0;
    while (i < len) {
        reversed[i] = string[len- i -1];
        i++;
    }

    reversed[i] = '\0'; //null terminating the reversed string

    return reversed;
}


int main(){
    char input[100];
    printf("Enter a string to reverse: \n");
    //scanf("%s", input);
    fgets(input, sizeof(input), stdin);

    char* result = reverse(input);
    printf("%s", result);

    free(result);
    return 0;
}

