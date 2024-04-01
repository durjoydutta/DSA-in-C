#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    struct Node *next;
} node;

typedef struct AdjList
{
    node **slot;
} list;

list *createAdjList(int size)
{
    list *adjList = malloc(sizeof(list));
    adjList->slot = malloc(size * sizeof(node *));
    for (int i = 0; i < size; i++)
    {
        adjList->slot[i] = NULL;
    }
    return adjList;
}

node *createNode(int val)
{
    node *newNode = malloc(sizeof(node));
    newNode->vertex = val;
    newNode->next = NULL;
    return newNode;
}

void insertInList(list *list, int vertex1, int vertex2)
{
    node *newNode = createNode(vertex2);
    node *temp = list->slot[vertex1];
    if (temp == NULL)
    {
        list->slot[vertex1] = newNode;
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printAdjList(list *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        node *temp = list->slot[i];
        printf("\n%d-> ", i + 1);
        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex + 1);
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("X\n");
        }
    }
}

void outDegree(list *list, int out[], int size)
{
    for (int i = 0; i < size; i++)
    {
        node *temp = list->slot[i];
        while (temp != NULL)
        {
            out[i] += 1;
            temp = temp->next;
        }
    }
}

void inDegree(list *list, int in[], int size)
{
    for (int i = 0; i < size; i++)
    {
        node *temp = list->slot[i];
        while (temp != NULL)
        {
            int currVertIndex = temp->vertex;
            in[currVertIndex] += 1;
            temp = temp->next;
        }
    }
}

int main()
{
    int order;
    int choice;
    int pairs;
    int vertex1;
    int vertex2;

    printf("\nEnter the number of vertices in the graph: ");
    scanf("%d", &order);
    list *adjList = createAdjList(order);
    int *inDeg = malloc(order * sizeof(int));
    int *outDeg = malloc(order * sizeof(int));

    printf("\n1. Insert the pair of vertices with edge bw %d - %d:", 1, order);
    printf("\n2. Print Adjacency List");
    printf("\n3. Count Outdegrees of all vertices");
    printf("\n4. Count Indegrees of all vertices");

    while (choice != 5)
    {
        printf("\n\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter how many pairs you want to insert:");
            scanf("%d", &pairs);
            for (int i = 0; i < pairs; i++)
            {
                printf("\nEnter pair %d of vertices seperated by space:", i + 1);
                scanf("%d %d", &vertex1, &vertex2);
                insertInList(adjList, vertex1 - 1, vertex2 - 1);
            }
            break;
        case 2:
            printAdjList(adjList, order);
            break;
        case 3:
            outDegree(adjList, outDeg, order);
            printf("\nOutDegrees:\n");
            for (int i = 0; i < order; i++)
            {
                printf("%d : %d\n", i + 1, outDeg[i]);
            }
            break;
        case 4:
            inDegree(adjList, inDeg, order);
            printf("\nInDegrees:\n");
            for (int i = 0; i < order; i++)
            {
                printf("%d : %d\n", i + 1, inDeg[i]);
            }
            break;
        case 5:
            printf("\nExiting the program..");
            break;
        }
    }
    return 0;
}