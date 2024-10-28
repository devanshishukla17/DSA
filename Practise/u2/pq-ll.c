#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct priorityq
{
    int data;
    int p;
    struct priorityq *link;
} PQ;

PQ *front = NULL;

PQ *create_node(int data,int priority)
{
    PQ *temp = (PQ *)malloc(sizeof(PQ));
    temp->data = data;
    temp->p = priority;
    temp->link = NULL;
}

void enqueue(int data, int priority)
{
    PQ *temp = create_node(data,priority);
    if(front == NULL)
        front = temp;
    else
    {
        PQ *pres = front;
        while(pres->link != NULL && pres->link->p > priority)
            pres=pres->link;
        temp->link = pres->link;
        pres->link = temp;  
    }
}

int dequeue()
{
    if(front == NULL)
    {
        printf("the queue is empty\n");
        return 0;
    }
    else
    {
        PQ *p = front;
        int data = p->data;
        front = front->link;
        free(p);
        return data;
    }
}

void display()
{
    if(front == NULL)
    {
        printf("the queue is empty\n");
    }
    else
    {
        PQ *temp  = front;
        while(temp != NULL)
        {
            printf("%d value of priority %d\n",temp->data,temp->p);
            temp = temp->link;
        }
    }
}