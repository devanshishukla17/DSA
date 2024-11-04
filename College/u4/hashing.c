/*

It is a technique used in dsa for efficient retrievel data.
~Converting an input/key into a 'fixed numerical value'-->hash value/hash code using hash function
~on an input/key when you apply hash function you get hash value/hash code
~the hash code that is generated is used as an index in a hash table(array like structure)
-->which actually stores the data.
~hashing ensures that different input/keys map to unique indexes(hashcode) allowing constant time complexity
-->O(1)[order of 1]
~insertiom,deletion or hashing operation.

EG.
keys to be inserted-24,52,91,67,48,83 HF--> *K mod 10 / *K mod n / mid square function / folding function

Collision in a hash table is when ek value already hai uss index pe and ek aur value insert karna hai
which has the same hash value-->can be resolved by-->

COLLISION RESOLUTION TECHNIQUES
-->OPEN ADDRESSING(closed hashing)
        1) LINEAR PROBING
        2) QUADRATIC PROBING
        3) DOUBLE HASHING
-->SEPERATE CHAINING(open hashing)
        
-->REHASHING(hash again)(dynamic resizes the hash table)

SEPERATE CHAINING-->basically creating linked list for every index
Key: 24,19,32,44
HF: K mod 6
~there is collision at 2nd index for 32 and 44
~every time there is collision you just add the new node at the start of the linked list
(make it the head node)

LINEAR PROBING-->This technique avoids collision by placing the data to the next available space in sequence

Generic: K mod n(if it's the HF)
 ((k mod n)+i)%n  i=0 initial;i=no of collsions

REAL TIME USES OF HASHING:

1) database indexing
2) password verification
3) caching
4) distributed networks: load balancing
5) compiler symbol table
6) network routing
7) blockchain and cryptography

*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
// For the nodes in SLL
typedef struct node
{
    int data;
    struct node *next;
}NODE;
// structure for the hash table
typedef struct hashtable{
    int count;
    struct node *head;
}HT;
NODE* createNode(int key)
{
    NODE *nn = (NODE*)malloc(sizeof(NODE));
    nn->data = key;
    nn->next = NULL;
    return nn;
}
void insert(int key,HT *hashtable)
{
    int hash_func = key % SIZE;
    NODE *nn = createNode(key);
    nn->next = hashtable[hash_func].head; // add a node to the head of the SLL
    hashtable[hash_func].head = nn;
    hashtable[hash_func].count++;
}

void display(HT *hashtable)
{
    for(int i=0;i<SIZE;i++)
    {
        if(hashtable[i].count != 0)
        {
            printf("\n Index[%d]:",i);
            NODE *t = hashtable[i].head;
            while(t)
            {
                printf("%d->",t->data);
                t = t->next;
            }
            printf("NULL");
        }
    }
    printf("\n");
}
void search(int key, HT *hashtable)
{
   int hash_func = key % SIZE;
   int pos = 1;
   NODE *t = hashtable[hash_func].head;
   while(t)
   {
    if(t->data == key)
    {
        printf("\n Element found at index [%d], position [%d]\n",hash_func,pos);
        return;
    }
    t = t->next;
    pos++;
   }
   printf("\nElement not found");
}

void delete_data(int key,HT *hashtable)
{

}

int main()
{
    HT hashtable[SIZE] = {0}; // Initialize the hash table with zero counts and NULL heads
    insert(10,hashtable);
    insert(20,hashtable);
    insert(15,hashtable);
    insert(30,hashtable);
    insert(47,hashtable);
    insert(65,hashtable);
    display(hashtable);

    search(20,hashtable);
    delete_data(10,hashtable); // home work
    display(hashtable);
}



