#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOAD_FACTOR 0.7

typedef struct HashTable
{
    int *table;
} hashTable;

hashTable *createHashTable(int size)
{
    hashTable *ht = malloc(sizeof(hashTable));
    ht->table = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        ht->table[i] = 0;
    }

    return ht;
}

unsigned int hash(int key, int m) // hash function
{
    return key % m;
}

void hashInsert(hashTable *hTable, int key, int m)
{
    unsigned int hashIndex = hash(key, m);
    int i = 0;

    while (i != m)
    {
        int h_k = (hashIndex + i) % m; // linear probing as collision resolution technique

        if (hTable->table[h_k] == 0)
        {
            hTable->table[h_k] = key;
            return;
        }
        else
        {
            i++; // if not found then increment the hash function and check next index
        }
    }
}

int hashSearch(hashTable *hTable, int key, int m)
{
    unsigned int hashIndex = hash(key, m);
    int i = 0;

    if (hTable->table[hashIndex] == 0) // if no key present at the original hashindex then return not found
    {
        return -1;
    }

    while (i != m)
    {
        int h_k = (hashIndex + i) % m;

        if (hTable->table[h_k] == key)
        {
            return h_k;
        }
        else
        {
            i++;
        }
    }
    return -1;
}

hashTable *removeKey(hashTable *hTable, int key, int m)
{
    int index = hashSearch(hTable, key, m);

    if (index != -1)
    {
        hTable->table[index] = 0;
        printf("\nThe key %d was deleted from the hashtable", key);
        return hTable;
    }
    printf("\nThe key %d was not found", key);
}

void printHashTable(hashTable *hTable, int m)
{
    printf("\nIndex\tKey\tHashValue\n");
    for (int i = 0; i < m; i++)
    {
        int key = hTable->table[i];
        printf("%d\t%d\t%d\n", i, key, hash(key, m));
    }
}

int main()
{
    int key, searchKey, searchRes, delKey;
    int keyCount = 10;
    int m = keyCount / LOAD_FACTOR;

    hashTable *ht = createHashTable(m);
    srand(time(NULL));
    for (int i = 0; i < keyCount; i++)
    {
        key = (rand() % 100) + 1;
        hashInsert(ht, key, m);
        // printf("%d ", key);
    }
    printf("\n");
    printHashTable(ht, m);

    printf("\nEnter the key you want to search for: ");
    scanf("%d", &searchKey);
    searchRes = hashSearch(ht, searchKey, m);

    if (searchRes == -1)
    {
        printf("The key %d was not found!", searchKey);
    }
    else
    {
        printf("The key %d was found at index %d in the hash table.", searchKey, searchRes);
    }

    printf("\nEnter the key you want to delete: ");
    scanf("%d", &delKey);
    removeKey(ht, delKey, m);

    printHashTable(ht, m);

    free(ht->table); // Free allocated mem. for table
    free(ht);        // Free allocated mem. for hashTable struct
    return 0;
}