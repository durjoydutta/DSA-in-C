#include <stdio.h>
#include <stdlib.h>
#include <string.h> //to use strlen
#include <ctype.h>  // to use isdigit

#define MAX_SIZE 100 // allowed max size of postfix expression

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

int evalPostfix(char *exp, int len)
{
    int res;
    stack *st = createStack(); // creating a stack to push/pop the intermediate operands and final result

    for (int i = 0; i < len; i++)
    {
        char symbol = exp[i];
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
    return finalRes;
}

int main()
{
    char postfix[MAX_SIZE];

    printf("\nEnter a postfix expression to evaluate (without whitespace): ");
    scanf("%s", postfix);
    int len = strlen(postfix); // length of given postfix expression

    if (len > MAX_SIZE)
    {
        printf("\nError size overlimit!\n");
        return -1;
    }

    int eval = evalPostfix(postfix, len);
    printf("\nThe value of the given postfix expression is: %d", eval);

    return 0;
}