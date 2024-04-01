#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int data;
    struct linkedList *next;

} node;

node *head;

void insertNodeFromBack(int value)
{
    node *temp;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next; // traverse the list until the current tail is found
    }
    temp->next = newNode; // connect the previous tail with the new node
}

node *tailPTR()
{
    node *temp = head;
    if (head == NULL)
    {
        return head;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

void addElementUsingTailPTR(int value)
{   
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    tailPTR()->next = newNode;
}

void printNodes()
{
    node *temp = head;
    printf("\nNodeAddress | nodeValue  nodeNext\n");
    while (temp != NULL)
    {
        if (temp->next == 0)
        {
            printf("%u  |\t%d\tNULL\n", temp, temp->data);
            break;
        }
        printf("%u  |\t%d\t%u\n", temp, temp->data, temp->next);
        temp = temp->next;
    }
}

int main()
{
    int data;
    int num = 5;
    for (int i = 0; i < num; i++)
    {
        printf("\nEnter value for node index %d: ", i);
        scanf("%d", &data);
        insertNodeFromBack(data);
    }

    printNodes();

    printf("The head node has the value %d.\n", head->data);
    node *tail = tailPTR();
    printf("The tail node has the value %d.\n", tail->data);

    addElementUsingTailPTR(5);
    printNodes();

    node *tail1 = tailPTR();
    printf("The tail node has the value %d.\n", tail1->data);
}