//DEQueue

/*
normal queue:
1.fifo behaviour
2. operations:
    1.enqueue- inserting an element at rear end
    2.dequeue- deleting an element at the front end
3.applications- cpu task scheduling, handle the resources-memory,hardware,
4. Priority Queue:
    1. priority queue: array and LL;
    2. circular queue: array and LL;


//Double ended queue
1. does not strictly follow fifo.
2. operations are:
    1. inserting a node at the front
    2. inserting a node at the rear
    3. delete a node at the front
    4. delete a node at the rear

--we'll use doubly linked list--
types of Dequeue: 
    1. input restriction DEqueue: inertion is allowed at only one end(front or rear),deletion can be done in both the ned(front and rear)
    2. output restriction DEqueue: deletion is allowed at only one end(front or rear),insertion can be done in both the ned(front and rear)

Application: 
1. sliding window protocol-computer networks;
2. palindrome checking
3. job scheduling- requires both the ends
*/

#include <stdlib.h>
#include <stdio.h>


typedef struct node 
{
    int key;                 
    struct node *next, *prev; 
}NODE;

// Define the structure of the dequeue (double-ended queue)
typedef struct dequeue
{
    NODE *front;  
    NODE *rear;   
}DEQ;


// Function declarations
void qdisplay(DEQ *);                // Display the contents of the deque
void qinsert_head(DEQ *, int);       // Insert a node at the head (front) of the deque
void qinsert_tail(DEQ *, int);       // Insert a node at the tail (rear) of the deque
int qdelete_head(DEQ *);             // Delete a node from the head of the deque
int qdelete_tail(DEQ *);             // Delete a node from the tail of the deque
void init(DEQ *p);                   // Initialize the deque

int main() 
{
    int k, data, ch;
    DEQ dq;
    init(&dq);  // Initialize the deque to be empty

    // Main loop to provide options for inserting, deleting, and displaying the deque
    while (1) {
        // Menu options for the user
        printf("\n1..Insert Head");
        printf("\n2..Insert Tail");
        printf("\n3..Delete Head");
        printf("\n4..Delete Tail");
        printf("\n5..Display");
        printf("\n6..EXIT");
        scanf("%d", &ch);

        switch (ch) 
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &data);
            qinsert_head(&dq, data);  // Insert at the head
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &data);
            qinsert_tail(&dq,data);  // Insert at the tail
            break;
        case 3:
            k = qdelete_head(&dq);  // Delete from the head
            if (k >= 0)
                printf("Element deleted = %d\n", k);
            break;
        case 4:
            k = qdelete_tail(&dq);  // Delete from the tail
            if (k >= 0)
                printf("Element deleted = %d\n", k);
            break;
        case 5:
            qdisplay(&dq);  // Display the deque
            break;
        case 6:
            exit(0);  // Exit the program
        }
    }
}

void init(DEQ *a)
{
    a->front=NULL;
    a->rear=NULL;
}

void qinsert_head(DEQ *a, int data)
{
    NODE* temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->key=data;
    temp->next=NULL;
    temp->prev=NULL;

    if(a->front==NULL)
    {
        a->front=temp;
        a->rear-temp;        
    }
    else
    {
        temp->next=a->front;
        a->front->prev=temp;
        a->front=temp;
    }
} 

void qinsert_tail(DEQ *a, int data)
{
    NODE* temp;
    temp=(NODE*) malloc(sizeof(NODE));
    temp->key=data;
    temp->next=temp->prev=NULL;

    if(a->front==NULL)
    {
        a->front=a->rear=temp;
    }
    else
    {
        a->rear->next=temp;
        temp->prev=a->rear;
        a->rear=temp;
    }
}

int qdelete_head(DEQ *a)
{
    NODE *pres;
    int key;
    if(a->rear==NULL)
    {
        printf("dequeue is empty");
        return -1;
    }

    pres=a->rear;
    key=pres->key;

    if(a->front==a->rear)
    {
        a->front=a->rear=NULL;
    }
    else
    {
        
    }
    
}





  


