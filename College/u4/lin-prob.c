#include <stdio.h>
#define SIZE 10

typedef struct node
{
    int data;
    int flag; // 0: empty, 1: occupied
} NODE;


void display(NODE *hashTable)
{
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i].flag == 1)
        {
            printf("Index %d: %d\n", i, hashTable[i].data);
        }
        else
        {
            printf("Index %d: EMPTY\n", i);
        }
    }
    printf("\n");
}

void  initializeHashTable(NODE *hashTable)
{
    for(int i = 0;i<SIZE;i++)
    {
        hashTable[i].data = 0;
        hashTable[i].flag = 0;
    }
}

void insert(int key,NODE *hashTable)
{
    int i = 0;
    int hash = ((key % SIZE)+i) % SIZE;
    while(hashTable[hash].flag != 0 && i < SIZE)
    {
        i++; // number of collisions
        hash = ((key % SIZE)+i) % SIZE; // new hash value ; i is incremented
    }
    if(hashTable[hash].flag == 0)
    {
        hashTable[hash].data = key;
        hashTable[hash].flag = 1;
        printf("The data %d is inserted at %d\n",key,hash);
    }
    else
    {
        printf("\nData cannot be inserted");
    }
}

void search(int key, NODE* hashTable)
{
    int i = 0;
    int hash = ((key % SIZE) + i) % SIZE;
    
    while (hashTable[hash].flag != 0 && i < SIZE)
    {
        if (hashTable[hash].data == key)
        {
            printf("The data %d is found at index %d\n", key, hash);
            return;
        }
        i++;
        hash = ((key % SIZE) + i) % SIZE; 
    }    
    printf("key not found");
}


int main()
{
    NODE hashTable[SIZE];
    initializeHashTable(hashTable);

    insert(5, hashTable);
    insert(15, hashTable);
    insert(25, hashTable);
    insert(49, hashTable);
    insert(59, hashTable);
    display(hashTable);

    search(15, hashTable); // Should find the data
    search(35, hashTable); // Should not find the data

    return 0;
}