#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} PolyNode;

typedef struct AvailNode
{
    PolyNode *node;
    struct AvailNode *next;
} AvailNode;

PolyNode *createNode(int coeff, int exp)
{
    PolyNode *newNode = (PolyNode *)malloc(sizeof(PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

AvailNode *createAvailNode(PolyNode *node)
{
    AvailNode *newAvailNode = (AvailNode *)malloc(sizeof(AvailNode));
    newAvailNode->node = node;
    newAvailNode->next = NULL;
    return newAvailNode;
}

void insertNode(PolyNode **head, int coeff, int exp)
{
    PolyNode *newNode = createNode(coeff, exp);

    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        PolyNode *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
}

void insertAvailNode(AvailNode **availList, PolyNode *node)
{
    AvailNode *newAvailNode = createAvailNode(node);

    if (*availList == NULL)
    {
        *availList = newAvailNode;
    }
    else
    {
        AvailNode *last = *availList;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newAvailNode;
    }
}

void displayPolynomial(PolyNode *head)
{
    if (head == NULL)
    {
        printf("Polynomial is empty.\n");
        return;
    }

    PolyNode *current = head;
    do
    {
        printf("%dx^%d ", current->coeff, current->exp);
        current = current->next;
        if (current != head)
        {
            printf("+ ");
        }
    } while (current != head);

    printf("\n");
}

void displayAvailList(AvailNode *availList)
{
    if (availList == NULL)
    {
        printf("Avail list is empty.\n");
        return;
    }

    AvailNode *current = availList;
    while (current != NULL)
    {
        printf("(%dx^%d) ", current->node->coeff, current->node->exp);
        current = current->next;
        if (current != NULL)
        {
            printf("-> ");
        }
    }

    printf("\n");
}

PolyNode *addPolynomials(PolyNode *A, PolyNode *B)
{
    PolyNode *result = NULL;
    PolyNode *tempA = A;
    PolyNode *tempB = B;

    while (tempA != NULL || tempB != NULL)
    {
        int coeffA = (tempA != NULL) ? tempA->coeff : 0;
        int expA = (tempA != NULL) ? tempA->exp : -1;
        int coeffB = (tempB != NULL) ? tempB->coeff : 0;
        int expB = (tempB != NULL) ? tempB->exp : -1;

        if (expA > expB)
        {
            insertNode(&result, coeffA, expA);
            if (tempA != NULL)
            {
                tempA = tempA->next;
            }
        }
        else if (expA < expB)
        {
            insertNode(&result, coeffB, expB);
            if (tempB != NULL)
            {
                tempB = tempB->next;
            }
        }
        else
        {
            int sumCoeff = coeffA + coeffB;
            if (sumCoeff != 0)
            {
                insertNode(&result, sumCoeff, expA);
            }
            if (tempA != NULL)
            {
                tempA = tempA->next;
            }
            if (tempB != NULL)
            {
                tempB = tempB->next;
            }
        }

        // Added break condition to avoid infinite loop
        if (tempA == A && tempB == B)
        {
            break;
        }
    }

    return result;
}

PolyNode *subtractPolynomials(PolyNode *A, PolyNode *B)
{
    PolyNode *result = NULL;
    PolyNode *tempA = A;
    PolyNode *tempB = B;

    while (tempA != NULL || tempB != NULL)
    {
        int coeffA = (tempA != NULL) ? tempA->coeff : 0;
        int expA = (tempA != NULL) ? tempA->exp : -1;
        int coeffB = (tempB != NULL) ? tempB->coeff : 0;
        int expB = (tempB != NULL) ? tempB->exp : -1;

        if (expA > expB)
        {
            insertNode(&result, coeffA, expA);
            if (tempA != NULL)
            {
                tempA = tempA->next;
            }
        }
        else if (expA < expB)
        {
            insertNode(&result, -coeffB, expB);
            if (tempB != NULL)
            {
                tempB = tempB->next;
            }
        }
        else
        {
            int diffCoeff = coeffA - coeffB;
            if (diffCoeff != 0)
            {
                insertNode(&result, diffCoeff, expA);
            }
            if (tempA != NULL)
            {
                tempA = tempA->next;
            }
            if (tempB != NULL)
            {
                tempB = tempB->next;
            }
        }

        // Added break condition to avoid infinite loop
        if (tempA == A && tempB == B)
        {
            break;
        }
    }

    return result;
}

PolyNode *multiplyPolynomials(PolyNode *A, PolyNode *B)
{
    PolyNode *result = NULL;
    PolyNode *tempA = A;

    while (tempA != NULL)
    {
        PolyNode *tempB = B;

        while (tempB != NULL)
        {
            int coeffA = tempA->coeff;
            int expA = tempA->exp;
            int coeffB = tempB->coeff;
            int expB = tempB->exp;

            int prodCoeff = coeffA * coeffB;
            int sumExp = expA + expB;

            insertNode(&result, prodCoeff, sumExp);

            tempB = tempB->next;
        }

        tempA = tempA->next;

        // Added break condition to avoid infinite loop
        if (tempA == A)
        {
            break;
        }
    }

    return result;
}

void freeAvailList(AvailNode **availList)
{
    while (*availList != NULL)
    {
        AvailNode *temp = *availList;
        *availList = (*availList)->next;
        free(temp);
    }
}

void freePolynomial(PolyNode **head)
{
    if (*head == NULL)
    {
        return;
    }

    PolyNode *current = *head;
    PolyNode *next;

    do
    {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);

    *head = NULL;
}

void generateRandomPolynomial(PolyNode **polynomial, int order)
{
    for (int i = order; i >= 0; --i)
    {
        int coeff = rand() % 10; // Random coefficient between 0 and 9
        int exp = i;
        insertNode(polynomial, coeff, exp);
    }
}

int main()
{
    srand(time(NULL)); // Seed for random number generation

    PolyNode *polynomialA = NULL;
    PolyNode *polynomialB = NULL;
    AvailNode *availList = NULL;

    int orderA, orderB;

    printf("Enter the order for Polynomial A: ");
    scanf("%d", &orderA);
    generateRandomPolynomial(&polynomialA, orderA);

    printf("Enter the order for Polynomial B: ");
    scanf("%d", &orderB);
    generateRandomPolynomial(&polynomialB, orderB);

    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Add Polynomials (A, B)\n");
        printf("2. Subtract Polynomials (A, B)\n");
        printf("3. Multiply Polynomials (A, B)\n");
        printf("4. Display Polynomial (A)\n");
        printf("5. Display Polynomial (B)\n");
        printf("6. Display Avail List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Add Polynomials (A, B)
            displayPolynomial(addPolynomials(polynomialA, polynomialB));
            break;
        case 2:
            // Subtract Polynomials (A, B)
            displayPolynomial(subtractPolynomials(polynomialA, polynomialB));
            break;
        case 3:
            // Multiply Polynomials (A, B)
            displayPolynomial(multiplyPolynomials(polynomialA, polynomialB));
            break;
        case 4:
            // Display Polynomial (A)
            displayPolynomial(polynomialA);
            break;
        case 5:
            // Display Polynomial (B)
            displayPolynomial(polynomialB);
            break;
        case 6:
            // Display Avail List
            displayAvailList(availList);
            break;
        case 7:
            // Exit
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    // Free the circular singly linked lists
    freePolynomial(&polynomialA);
    freePolynomial(&polynomialB);

    // Free the Avail list
    freeAvailList(&availList);

    return 0;
}
