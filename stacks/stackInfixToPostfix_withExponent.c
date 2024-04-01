#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>  // Include math.h for pow function

#define MAX 100 // max expression size
char infix[MAX];
char postfix[MAX];
int top = -1;
int stack[MAX]; // Change the type to int

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("\nStack is full!");
        return;
    }
    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("\nThe stack is empty!");
        exit(0);
    }
    return stack[top--];
}

int precedence(char operator)
{
    if (operator == '^')  // Exponentiation operator
    {
        return 3;
    }
    else if (operator == '*' || operator == '/')
    {
        return 2;
    }
    else if (operator == '+' || operator == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infixToPostfix(int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            char popped = pop();
            while (popped != '(')
            {
                postfix[j++] = popped;
                popped = pop();
            }
        }
        else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-' || infix[i] == '^')
        {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        else
        {
            postfix[j++] = infix[i];
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }
}

int eval()
{
    int operand1, operand2;
    int res;
    int size = strlen(postfix);
    for (int i = 0; i < size; i++)
    {
        char symbol = postfix[i];
        if (isdigit(symbol))
        {
            push(symbol - '0');
        }
        else
        {
            operand2 = pop();
            operand1 = pop();
            switch (symbol)
            {
            case '+':
                res = operand1 + operand2;
                break;
            case '-':
                res = operand1 - operand2;
                break;
            case '*':
                res = operand1 * operand2;
                break;
            case '/':
                res = operand1 / operand2;
                break;
            case '^':
                res = (int)pow(operand1, operand2);  // Use pow function for exponentiation
                break;
            }
            push(res);
        }
    }
    return pop();
}

int main()
{
    printf("\nEnter your infix expression: ");
    scanf("%99s", infix); // Limit the input to prevent buffer overflow
    printf("\nThe given infix expression is : %s", infix);

    int size = strlen(infix);
    infixToPostfix(size);
    printf("\nThe postfix expression is : %s", postfix);

    int res = eval();
    printf("\nThe evaluation of the postfix expression is: %d", res);

    return 0;
}
