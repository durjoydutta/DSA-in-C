#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

float stack[MAX];
int top = -1;
char infix[MAX], postfix[MAX];

void push(float item)
{
    if (top == MAX - 1)
    {
        printf("Stack is full.\n");
        exit(0);
    }
    stack[++top] = item;
}

float pop()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
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
    return 0;
}

int isSpaceTabNewLine(char c) // to check for whitespace tab and \n in the infix expression
{
    if (c == ' ' || c == '\t' || c == '\n')
    {
        return 1;
    }
    return 0;
}

void inToPost() // func to convert infix to postfix (store operators in stack)
{
    int i, j = 0;
    char symbol;

    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];

        if (!isSpaceTabNewLine(symbol))
        {
            switch (symbol)
            {
            case '(': // if we get ( we push it onto stack
                push(symbol);
                break;
            case ')': // if we get ) we pop all elements until we get the (
                char poppedItem;
                while ((poppedItem = pop()) != '(')
                {
                    postfix[j++] = poppedItem;
                }
                break;
            case '*':
            case '/': // we use the precedence func for these cases
            case '+':
            case '-':
                while (top != -1 && precedence(stack[top]) >= precedence(symbol))
                {
                    postfix[j++] = pop(); // pop the higher preceding operators out of stack and onto postfix
                }
                push(symbol); // most important line , not only do we pop the higher preceding operators
                              // but also the current operator into the stack after popping them
                break;
            default:
                postfix[j++] = symbol; // for normal operands(a,b,c...) just add them to postfix as no order change
                break;
            }
        }
    }
    while (top != -1) // top pop the rest of the operators from the stack to postfix
    {
        postfix[j++] = pop();
    }
}

float evalPost() // to evaluate the postfix expression (store operands in stack)
{
    int i;
    float result, operand1, operand2;
    char symbol;

    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        if (symbol >= '0' && symbol <= '9')
        {
            push(symbol - '0'); // to push int value instead of char
        }
        else
        {
            operand2 = pop();
            operand1 = pop();

            switch (symbol)
            {
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            }
        }
    }
    result = pop(); // pop the final element off the stack -> result
    return result;
}

int main()
{
    float eval;
    printf("\nEnter the infix expression: ");
    // scanf("%s", infix);
    fgets(infix, MAX, stdin);

    // convert infix to postfix
    inToPost();
    printf("\nThe equivalent postfix expression is: %s", postfix);

    // evaluate postfix expression
    eval = evalPost();
    printf("\nAfter evaluating the postfix expression we get: %.2f", eval);

    return 0;
}