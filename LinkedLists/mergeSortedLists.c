#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
} node;

node *createNode(int val)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

node *insertNodeFromHead(node *head, int val)
{
    node *newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

node *merge(node *head1, node *head2)
{
    node *mergedHead = NULL;
    node *temp1 = head1;
    node *temp2 = head2;

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->data < head2->data)
    {
        mergedHead = insertNodeFromHead(mergedHead, head1->data);
        temp1 = head1->next;
    }
    else
    {
        mergedHead = insertNodeFromHead(mergedHead, head2->data);
        temp2 = head2->next;
    }

    node *curr = mergedHead;
    while (temp1 && temp2)
    {
        if (temp1->data < temp2->data)
        {
            curr->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            curr->next = temp2;
            temp2 = temp2->next;
        }
        curr = curr->next;
    }
    while (temp1)
    {
        curr->next = temp1;
        temp1 = temp1->next;
        curr = curr->next;
    }
    while (temp2)
    {
        curr->next = temp2;
        temp2 = temp2->next;
        curr = curr->next;
    }
    return mergedHead;
}

void displayNodes(node *head)
{
    if (head == NULL)
    {
        printf("Empty!\n");
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    free(temp);
}

node *createListFromUserInput(node *head, int size)
{
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter list item %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        head = insertNodeFromHead(head, arr[size - i - 1]);
    }
    free(arr);
    return head;
}

int main()
{
    int n1, n2;
    node *mergedHead;

    node *head1 = NULL; // head of first linked list
    node *head2 = NULL; // head of second linked list

    // create First List
    printf("\nEnter the size of the first list: ");
    scanf("%d", &n1);
    head1 = createListFromUserInput(head1, n1);
    printf("\nThe first list is:");
    displayNodes(head1);
    // create Second List
    printf("\n\nEnter the size of the second list: ");
    scanf("%d", &n2);
    head2 = createListFromUserInput(head2, n2);
    displayNodes(head2);

    // merge two sorted lists
    mergedHead = merge(head1, head2);
    printf("\nThe merged sorted list is : ");
    displayNodes(mergedHead);

    free(head1);
    free(head2);
    free(mergedHead);
    return 0;
}