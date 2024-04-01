//stack operations

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
int stack[MAX_SIZE];
int top = -1; // initial top position when stack is empty

void stackPush(int pushSize)
{
    int value;
    if (top == MAX_SIZE - 1)
    {
        printf("\nERROR 404: STACK IS FULL!!\n");
        return;
    }
    int usableSize = MAX_SIZE - top - 1;
    int diff = pushSize - usableSize;
    if (diff > 0) // if pushSize greater than capacity, we only push max possible size of items
    {
        int pushableSize = pushSize - diff;
        printf("\nItem size %d is greater than stack  %d\n", pushSize, MAX_SIZE);
        printf("Pushing first %d items.\n", pushableSize);
        stackPush(pushableSize);
        return; 
    }
    srand(time(NULL));
    for (int i = 0; i < pushSize; i++)
    {
    value = rand() % 101;
    stack[++top] = value;
    printf("\nPushed item %d onto the top of stack.\n", value);
    }
}

void stackPop(int popSize)
{
    if (top != -1 && popSize > top + 1) // more items to pop than currenty available
    {
        printf("\nPopping max possible items as only %d items are in the stack.\n",top + 1);
        popSize = top + 1; // just pop max possible items
    }
    int count = 0;
    while (count != popSize && top != -1)
    {
        printf("\nPopped the item %d from the stack.\n", stack[top]);
        top--;
        count++;
    }
    if (top == -1)
    {
        printf("\nThe stack is empty, can't pop more items!!\n");
        return;
    }    
}

void stackDisplay()
{
    if (top == -1)
    {
        printf("\nThe stack is currently empty!\n");
        return;
    }
    printf("\n\t%d ", stack[top]);
    printf(" < -- TOP\n");
    for (int i = top-1; i >= 0; i--)
    {
        printf("\t%d\n", stack[i]);
    }
}


int main()
{   
    int choice, pushSize, popSize;
    printf("\n<<<<STACK OPS>>>>\n");
    printf("\n1. Push Items onto Stack --->>>\n");
    printf("\n2. Pop Items from Stack --->>>\n");
    printf("\n3. Display stack\n");

    while (choice != 4)
    {        
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter how many items you want to push:");
                scanf("%d", &pushSize);
                stackPush(pushSize);
                break;
            case 2:
                printf("\nEnter how many items you want to pop:");
                scanf("%d", &popSize);
                stackPop(popSize);
                break;
            case 3:
                stackDisplay();
                break;
            case 4:
                printf("\nExiting the program....");
                exit(0);
            default:
                printf("Enter valid choice!!"); 
        }

    }
    return 0;
}

