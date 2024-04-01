#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node;

node *head = NULL;
node *tail = NULL;

void insertNodeifEmpty(node *newNode) // used to initialize both head and tail for first entry
{
    newNode->prev = newNode;
    newNode->next = newNode;
    head = newNode;
    tail = head;
}

void createNodeHead(int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    if (head == NULL) // if empty
    {
        insertNodeifEmpty(newNode);
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    newNode->prev = tail;
    head->prev = newNode;
    head = newNode;
}

void createNodeTail(int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    if (head == NULL) // if empty
    {
        insertNodeifEmpty(newNode);
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    newNode->prev = tail;
    head->prev = newNode;
    tail = newNode;
}

void insertNodeFromHead(int nodeNumsHead)
{
    int value;
    srand(time(NULL));
    for (int i = 0; i < nodeNumsHead; i++)
    {
        value = rand() % 101;
        createNodeHead(value);
        printf("\nInserted %d at the beginning\n", value);
    }
}

void insertNodeFromTail(int nodeNumsTail)
{
    int value;
    srand(time(NULL));
    for (int i = 0; i < nodeNumsTail; i++)
    {
        value = rand() % 101;
        createNodeTail(value);
        printf("\nInserted %d at the end\n", value);
    }
}

int checkBeforeDelete() // check if list is empty or only 1 element before deleting
{
    if (head == NULL)
    {
        printf("\nThe list is currenty empty!\n");
        return 1;
    }

    else if (head == tail)
    {
        printf("\nHead deleted. The list is now empty.\n");
        free(head);
        head = NULL;
        tail = NULL;
        return 1;
    }

    return 0;
}
void deleteHead()
{
    if (checkBeforeDelete() == 1)
    {
        return;
    }
    printf("\nRemoved the head node %d\n", head->data);
    node *newHead = head->next;
    tail->next = newHead;
    newHead->prev = head->prev;
    head = newHead;
}

void deleteTail()
{
    if (checkBeforeDelete() == 1)
    {
        return;
    }
    printf("\nRemoved the tail node %d\n", tail->data);
    node *newTail = tail->prev;
    newTail->next = tail->next;
    head->prev = newTail;
    tail = newTail;
}

void deleteAnyIndex(int index)
{
    if (index < 0)
    {
        printf("Enter a valid index!");
        return;
    }
    if (index == 0) // means head
    {
        deleteHead();
        return;
    }
    if (head == NULL)
    {
        printf("The list is empty!");
        return;
    }
    int i = index;
    node *temp = head;
    do
    {
        if (i == 0)
        {
            if (temp == head)
            {
                deleteHead();
                return;
            }
            else if (temp == tail)
            {
                deleteTail();
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
        temp = temp->next;
        i--;
    } while (temp != head);

    printf("List index out of bounds!");
    return;
}

void displayNode()
{
    if (head == NULL)
    {
        printf("\nThe list is currently empty!\n");
        return;
    }

    node *temp = tail->next;
    printf("\nAddress\t    |\tPrev  \t   |  Node|\tNext\n");
    printf("--------------------------------------------\n");
    do
    {
        printf("%u  |  %u  |  %d  |  %u \n", temp, temp->prev, temp->data, temp->next);
        temp = temp->next;
    } while (temp != tail->next);

    printf("\nHead Pointer: %d", head->data);
    printf("\nTail Pointer: %d", tail->data);
}

void reverseList()
{
    if (checkBeforeDelete() > 0)
    {
        return;
    }

    node *curr = head;
    node *temp; // to store the prev pointers

    printf("\nThe list is reversed");

    do
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->next;

    } while (curr != head);

    tail = curr;
    head = curr->next;

    printf("\nHead Pointer: %d", head->data);
    printf("\nTail Pointer: %d", tail->data);
}

int main()
{
    int nodeNumsHead, nodeNumsTail;
    int choice, delIndex;

    printf("\nChoose one option from below: \n");
    printf("1. Insert Node from head\n");
    printf("2. Insert Node from tail\n");
    printf("3. Insert at nth Index\n");
    printf("4. Delete Head\n");
    printf("5. Delete Tail\n");
    printf("6. Delete nth Index\n");
    printf("7. Display nodes\n");
    printf("8. Reverse The list\n");
    printf("9. Exit");

    while (1)
    {
        printf("\nEnter you choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter no. of nodes to enter from head: ");
            scanf("%d", &nodeNumsHead);
            insertNodeFromHead(nodeNumsHead);
            break;
        case 2:
            printf("\nEnter no. of nodes to enter from tail: ");
            scanf("%d", &nodeNumsTail);
            insertNodeFromTail(nodeNumsTail);
            break;
        case 3:
            break;
        case 4:
            deleteHead();
            break;
        case 5:
            deleteTail();
            break;
        case 6:
            printf("\nEnter the node index you want to delete: ");
            scanf("%d", &delIndex);
            deleteAnyIndex(delIndex);
            break;
        case 7:
            displayNode();
            break;
        case 8:
            reverseList();
            break;
        case 9:
            printf("\nExiting the program...\n");
            exit(0);
        default:
            printf("Please choose a valid option.\n");
        }
    }

    return 0;
}