#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define MAX_KEY 1000 // max key size of long int

// linkedlist node struct for slots
typedef struct Node // defines the key value paired linkedlist node which points to the next node with same hash value
{
    int key;
    char *value;
    struct Node *next;
} node;
// hashtable struct
typedef struct HashTable
{
    node **table;
} hashTable;

unsigned long int hash(long int key, int m) // hashing function
{
    unsigned long int hashVal = key % m;
    return hashVal;
}

hashTable *initHashTable(int size) // initialize a hashtable of required size
{
    hashTable *ht = malloc(sizeof(hashTable));
    ht->table = malloc(size * sizeof(node)); // create M no. of table for the hash table

    for (int i = 0; i < size; i++)
    {
        ht->table[i] = NULL; // initialize the node of the slots to be null by default
    }

    return ht;
}

node *createSlot(long int key, char *val) // helper function to create a new node while inserting a key
{
    node *newNode = malloc(sizeof(node));
    newNode->key = key;
    newNode->value = val;
    newNode->next = NULL;

    return newNode;
}

void insert(hashTable *ht, long int key, char *val, int m) // insert a key into the hash table
{
    long int index = hash(key, m);
    node *temp = ht->table[index];

    if (temp == NULL) // means the required slot in the table is free
    {
        ht->table[index] = createSlot(key, val);
        return;
    }
    else // if keys already present in slot we insert this node to the end of ll
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createSlot(key, val);
    }
}

node *search(hashTable *ht, int key, int m)
{
    long int index = hash(key, m);

    node *temp = ht->table[index];

    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return temp; // return found
        }

        temp = temp->next;
    }

    return NULL; // return not found after travelling the list associated with the hash index
}

void printTable(hashTable *ht, int size) // to visualize the hashtable
{
    FILE *hashFile = fopen("hashTable.txt", "w");
    fprintf(hashFile, "Hash Table Dump:\n");
    fprintf(hashFile, "Slot\tKeys\tValues\n");
    for (int i = 0; i < size; i++)
    {
        node *temp = ht->table[i];
        fprintf(hashFile, "\n%d:\t", i);
        while (temp != NULL)
        {
            fprintf(hashFile, "[%d\t%s]\t", temp->key, temp->value); // Add newline character here
            temp = temp->next;
        }
    }
    fclose(hashFile);
}

int main()
{
    int choice;
    int keyCount;
    float loadFactor = 0.7;
    int m;
    long int key;
    char value[100];

    hashTable *ht;

    printf("\nHash Table Operations\n");
    printf("1. Insert N random keys into hash table\n");
    printf("2. Insert individual key-value pair\n");
    printf("3. Search for a key\n");
    printf("4. Print the hash table\n");
    printf("5. Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Insert random keys
            printf("Enter the number of random keys to insert: ");
            scanf("%d", &keyCount);
            m = keyCount / loadFactor;

            ht = initHashTable(m); // creates a hashtable pointed by ht

            srand(time(NULL));
            for (int i = 0; i < keyCount; i++)
            {
                int randKey = rand() % MAX_KEY;
                char *str = malloc(6 * sizeof(char)); // Length of string associated with key is 5
                for (int j = 0; j < 5; j++)
                {
                    char randChar = 'a' + rand() % 26;
                    str[j] = randChar;
                }
                str[5] = '\0'; // Null-terminate the string
                insert(ht, randKey, str, m);
            }
            printf("Random keys inserted.\n");
            break;

        case 2:
            // Insert individual key-value pair
            printf("Enter the key: ");
            scanf("%ld", &key);
            printf("Enter the value: ");
            scanf("%s", value);
            insert(ht, key, value, m);
            printf("Key-value pair inserted.\n");
            break;

        case 3:
            // Search for a key
            printf("Enter the key to search: ");
            scanf("%ld", &key);
            node *result = search(ht, key, m);
            if (result != NULL)
                printf("Value found: %s\n", result->value);
            else
                printf("Key not found.\n");
            break;

        case 4:
            // Print the hash table
            printTable(ht, m);
            break;

        case 5:
            // Exit
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}