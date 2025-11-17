#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

Node* head = NULL;

Node* createNode(int val) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int val) {
    Node* newNode = createNode(val);
    if (!newNode) {
        printf("Failed to insert node in Linked List\n");
        return;
    }
    
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted node with value %d in the linked list successfully!\n", val);
}

void deleteNode(int val) {
    if (!head) {
        printf("Create a new linked list first!\n");
        return;
    }
    Node* dummy = malloc(sizeof(Node));
    dummy->next = head;
    Node* temp = dummy;
    while (temp->next) {
        if (temp->next->val == val) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            free(del);
            head = dummy->next;
            free(dummy);
            printf("Node with value %d is deleted\n", val);
            return;
        }
        temp = temp->next;
    }
    free(dummy);
    printf("No node with value %d is found\n", val);
}

void printLL() {
    if (!head) {
        printf("Create a new linked list first!\n");
        return;
    }
    Node* temp = head;
    while (temp) {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int input = -1;
    printf("1. Insert new node at end\n");
    printf("2. Print linked list\n");
    printf("3. Delete a node from LL\n");
    while (true) {
        printf("Choose one operation from the list above: ");
        scanf("%d", &input);
        switch(input) {
            case 1: 
                int insertVal;
                printf("Insert value to insert: ");
                scanf("%d", &insertVal);
                insertAtEnd(insertVal);
                break;
            case 2:
                printLL();
                break;
            case 3:
                int delVal;
                printf("Insert value to delete: ");
                scanf("%d", &delVal);
                deleteNode(delVal);
                break;            
        }
    }
    return 0;
}
