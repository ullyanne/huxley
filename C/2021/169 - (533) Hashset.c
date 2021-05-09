#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct hashNode
{
    int key;
    int value;
    struct hashNode* next;
};

struct hashtable
{
    struct hashNode** ht;
    int* entriesNode;
    int entries;
    int size;
};

struct hashtable* createHashtable(int size)
{
    struct hashtable* hashTable = (struct hashtable*) malloc(sizeof(struct hashtable));
    
    hashTable->ht = (struct hashNode**) malloc(size * sizeof(struct hashNode*));
    hashTable->entriesNode = (int*) calloc(size, sizeof(int));
    hashTable->entries = 0;
    hashTable->size = size;

    for(int i = 0; i < size; i++)
        hashTable->ht[i] = NULL;

    return hashTable;
}

struct hashNode* createHashnode(int key, int value)
{
    struct hashNode* node = (struct hashNode*) malloc(sizeof(struct hashNode));
    node->key = key;
    node->value = value;
    node->next = NULL;

    return node;
}

int hash(int key, int size)
{
    return key%size;
}

void has(struct hashtable* ht, int key)
{
    int h = hash(key, ht->size);

    struct hashNode* current = ht->ht[h];
    int visited = 0;
    
    while(current != NULL)
    {
        visited++;
        if(current->key == key)
        {
            printf("1 ");
            printf("%d\n", visited);
            return;
        }
        current = current->next;
    }

    printf("0 ");
    printf("%d\n", visited);
}

void put(struct hashtable* ht, int key, int value)
{
    struct hashNode* newnode = createHashnode(key, value);
    int h = hash(key, ht->size);
    
    newnode->next = ht->ht[h];
    ht->ht[h] = newnode;
    ht->entriesNode[h] = ht->entriesNode[h]+1;
    ht->entries++;
}

void add(struct hashtable* ht, int key, int value)
{
    struct hashNode* newnode = createHashnode(key, value);
    int h = hash(key, ht->size);
    int visited = 0;

    struct hashNode* current = ht->ht[h];
    
    while(current != NULL)
    {
        visited++;
        if(current->key == key)
        {
            printf("0 ");
            printf("%d\n", visited);
            return;
        }
        
        current = current->next;
    }

    printf("1 ");
    printf("%d\n", visited);

    newnode->next = ht->ht[h];
    ht->ht[h] = newnode;
    ht->entriesNode[h] = ht->entriesNode[h]+1;
    ht->entries++;
}

void removeKey(struct hashtable* ht, int key)
{
    int h = hash(key, ht->size);

    struct hashNode* current = ht->ht[h];
    struct hashNode* prev = NULL;
    int visited = 0;

    while(current != NULL && current->key != key)
    {
        visited++;
        prev = current;
        current = current->next;
    }

    if(current == NULL)
    {
        printf("0 ");
        printf("%d\n", visited);
        return;
    }

    if(prev == NULL)
        ht->ht[h] = current->next;
    else
        prev->next = current->next;

    visited++;
    printf("1 ");
    ht->entriesNode[h] = ht->entriesNode[h]-1;
    ht->entries--;
    printf("%d\n", visited);
}

void print(struct hashtable* ht)
{
    printf("%d %d ", ht->size, ht->entries);

    int maior = 0;

    for(int i = 0; i < ht->size; i++)
    {
        if(ht->entriesNode[i] > maior)
        {
            maior = ht->entriesNode[i];
        }
    }

    printf("%d\n", maior);
}

struct hashtable* rehash(struct hashtable* ht, int* size)
{
    struct hashtable* newht = createHashtable((2* *size)-1);
    struct hashNode* current;
    struct hashNode* ptr;

    for(int i = 0; i < *size; i++)
    {
        current = ht->ht[i];
        while(current != NULL)
        {
            put(newht, current->key, 1);
            ptr = current;
            current = current->next;
            free(ptr);
        }
    }

    *size = (2* *size)-1;

    return newht;
}

int main()
{
    int size = 7;
    double loadFactor;
    struct hashtable* ht = createHashtable(size);

    char command[7];
    int key;
    int opp = 0;

    while(scanf("%s", command) != EOF)
    {
        printf("%d ", opp);

        if(!strcmp("ADD", command))
        {
            scanf("%d", &key);
            add(ht, key, 1);
            loadFactor = (double) ht->entries/ht->size;

            if(loadFactor >= 0.75)
                ht = rehash(ht, &size);
        }
        else if(!strcmp("DEL", command))
        {
            scanf("%d", &key);
            removeKey(ht, key);
        }
        else if(!strcmp("HAS", command))
        {
            scanf("%d", &key);
            has(ht, key);
        }
        else if(!strcmp("PRT", command))
        {
            print(ht);
        }
        opp++;
    }

    free(ht);

    return 0;
}


