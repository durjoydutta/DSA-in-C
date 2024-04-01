#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_KEY LONG_MAX // max key size of long int
#define load_factor 0.7  // load factor = keyCount / HashTable length

int count;

// linkedlist node struct for each slot
typedef struct Node // defines the key value paired linkedlist node which points to the next node with same hash value
{
    int key;
    struct Node *next;
} node;
// hashtable struct that will contain the array of pointers of the slot nodes
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

node *createSlot(long int key) // helper function to create a new node while inserting a key
{
    node *newNode = malloc(sizeof(node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void insert(hashTable *ht, long int key, int m) // insert a key into the hash table
{
    long int index = hash(key, m);
    node *temp = ht->table[index];

    count = 1;
    if (temp == NULL) // means the required slot in the table is free
    {
        ht->table[index] = createSlot(key);
        return;
    }
    else // if keys already present in slot we insert this node to the end of ll
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        temp->next = createSlot(key);
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

int main()
{
    int maxChainLength, sumOfCounts;
    float avgCount;
    int nValues[] = {1000, 5000, 10000, 25000, 50000};
    int n = sizeof(nValues) / sizeof(nValues[0]);

    srand(time(NULL));
    printf("\n\t=====Hashing By Chaining=====\n\n");
    printf("KeyCount\tAvgCount\tMaxChainLength\n");

    for (int j = 0; j < n; j++)
    {
        int keyCount = nValues[j]; // no of keys to be inserted
        count = 0;
        sumOfCounts = 0;
        maxChainLength = 0;
        const long int m = keyCount / load_factor; // hashTable size will vary depending upon keycount
        hashTable *ht = initHashTable(m);          // creates a hashtable pointed by ht

        for (int i = 0; i < keyCount; i++)
        {
            long int randKey = rand() % MAX_KEY + 1;
            insert(ht, randKey, m);
            sumOfCounts += count;

            if (count > maxChainLength)
            {
                maxChainLength = count;
            }
        }

        free(ht);
        avgCount = (float)sumOfCounts / keyCount;
        printf("%d\t\t%.2f\t\t%d\n", keyCount, avgCount, maxChainLength);
    }

    return 0;
}