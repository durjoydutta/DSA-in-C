#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    if (operator== '*' || operator== '/')
    {
        return 2;
    }
    else if (operator== '+' || operator== '-')
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
        else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-')
        {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) // if precedence of symbol lower or similar pop the symbols in the stack to the postfix expression
            {
                postfix[j++] = pop();
            }
            push(infix[i]); // push the symbol to the stack either way
        }
        else // when operand directly push them in result
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
            }
            push(res);
        }
    }
    return pop();
}

int main()
{
    printf("\nEnter your infix expression: ");
    scanf("%99[^\n]", infix);

    // Remove leading whitespaces
    char *trimmed_infix = infix;
    while (isspace(*trimmed_infix)) {
        trimmed_infix++;
    }

    // Remove trailing whitespaces
    char *end = trimmed_infix + strlen(trimmed_infix) - 1;
    while (end > trimmed_infix && isspace(*end)) {
        *end-- = '\0';
    }

    printf("\nThe given infix expression is : %s", trimmed_infix);

    int size = strlen(trimmed_infix);
    infixToPostfix(size);
    printf("\nThe postfix expression is : %s", postfix);

    int res = eval();
    printf("\nThe evaluation of the postfix expression is: %d", res);

    return 0;
}

