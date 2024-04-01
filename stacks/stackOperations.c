// take user inputs to check and manipulate different stack operations

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10  // defining the max size of the stack
int stack[MAX_SIZE]; // initializing the stack
int top = -1;        // initial stack top position

void stackPush(int element)
{ // push an element into the top of stack
    if (top == MAX_SIZE - 1)
    {
        printf("The stack is full.\n");
    }
    else
    {
        top++;
        stack[top] = element;
        printf("Pushed the element %d on top of the stack.\n", element);
    }
}

void stackPop()
{ // pop the top of stack
    if (top == -1)
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("popped the top element %d.\n", stack[top--]);
    }
}

int stackTop()
{ // to display the current top element of the stack
    if (top == -1)
    {
        printf("The stack is empty.\n");
        return -1;
    }
    printf("The current top of stack is: %d\n", stack[top]);
}

int isEmpty()
{
    if (top == -1)
    {
        printf("The stack is empty.\n");
        return -1;
    }
    printf("The stack is not empty.\n");
    printf("The stack has %d/%d elements.\n", top + 1, MAX_SIZE);
}

int isFull()
{
    if (top == MAX_SIZE - 1)
    {
        printf("The stack is full.\n");
        return -1;
    }
    printf("The stack is not full.\n");
    printf("The stack currently has %d/%d elements.\n", top + 1, MAX_SIZE);
}

void stackDisplay()
{ // display all elements of the stack from bottom to top
    if (top == -1)
    {
        printf("The stack is empty.\n");
        return;
    }
    printf("The current stack elements are: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int choice, item;
    // printing out different choices for user to perform
    printf("\nChoose a number b/w 1 and 5:\n\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Is the stack empty?\n");
    printf("4. Is the stack full?\n");
    printf("5. Current top\n");
    printf("6. Display the stack\n");
    printf("7. Exit\n\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an integer element to push: ");
            scanf("%d", &item);
            stackPush(item);
            break;
        case 2:
            stackPop();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            isFull();
            break;
        case 5:
            stackTop();
            break;
        case 6:
            stackDisplay();
            break;
        case 7:
            printf("Exiting the program..\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
