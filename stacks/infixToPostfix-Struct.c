#include <stdio.h>
#include <stdlib.h>
#include <string.h> //to use strlen
#include <ctype.h>  // to use isdigit

#define MAX_SIZE 100 // allowed max size of postfix expression
char infix[MAX_SIZE];
char postfix[MAX_SIZE];

// defining the stack struct
typedef struct Stack
{
    int top;
    int *arr;
} stack;

stack *createStack()
{
    stack *newStack = malloc(sizeof(stack));
    newStack->top = -1;
    newStack->arr = malloc(MAX_SIZE * sizeof(int));
    return newStack;
}

int isEmpty(stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(stack *st)
{
    if (st->top == MAX_SIZE - 1)
    {
        return 1;
    }
    return 0;
}

void push(stack *st, int val)
{
    if (!isFull(st))
    {
        st->arr[++st->top] = val;
        return;
    }
    printf("\nStack Overflow!\n");
    return;
}

int pop(stack *st)
{
    if (!isEmpty(st))
    {
        int poppedItem = st->arr[st->top--];
        return poppedItem;
    }
    // printf("\nStack Underflow!\n");
    return -1;
}

int precedence(char symbol)
{
    if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

void inToPost(char *exp)
{
    char symbol;
    int len = strlen(exp);     // length of given infix expression
    stack *st = createStack(); // stack to push/pop the operators
    int j = 0;                 // index to append symbols into postfix string
    for (int i = 0; i < len; i++)
    {
        symbol = exp[i];
        if (symbol == '(')
        {
            push(st, symbol);
        }
        else if (symbol == ')')
        {
            char popped = pop(st);
            while (popped != '(')
            {
                postfix[j++] = popped;
                popped = pop(st);
            }
        }
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        {
            while (!isEmpty(st) && precedence(symbol) <= precedence(st->arr[st->top]))
            {
                postfix[j++] = pop(st);
            }
            push(st, symbol);
        }
        else // when the symbol is a digit
        {
            postfix[j++] = symbol;
        }
    }
    while (!isEmpty(st))
    {
        postfix[j++] = pop(st);
    }
    free(st->arr);
    free(st);
}
int evalPostfix(char *exp)
{
    int res;
    char symbol;

    int len = strlen(exp);     // length of given postfix expression
    stack *st = createStack(); // creating a stack to push/pop the intermediate operands and final result

    for (int i = 0; i < len; i++)
    {
        symbol = exp[i];
        if (isdigit(symbol)) // if symbol is digit we push it onto stack
        {
            push(st, symbol - '0'); // convert the ascii to int val
        }
        else // if symbol is an operator
        {
            int op2 = pop(st);
            int op1 = pop(st);
            switch (symbol)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            default:
                printf("\nPlease check your expression and try again!\n");
                exit(0);
            }
            push(st, res);
        }
    }
    int finalRes = pop(st);
    free(st->arr);
    free(st);
    return finalRes;
}

int main()
{
    printf("\nEnter a infix expression (without whitespace): ");
    scanf("%s", infix);

    inToPost(infix);
    printf("\nThe postfix expression of the given infix: %s", postfix);

    int eval = evalPostfix(postfix);
    printf("\nThe value of the above expression is: %d", eval);

    return 0;
}