#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct priorityq
{
    int data;
    int p;
} PQ;

PQ pq[max];
int size = 0;

void enqueue(int data, int priority)
{
    if (size == max)
        printf("queue overloaded\n");
    else
    {
        pq[size].data = data;
        pq[size].p = priority;
        size++;

        // sorting the queue based on priority
        for (int i = size - 1; i >0; i--)
        {
            if (pq[i].p > pq[i - 1].p) // if element with index 3 has higher priority than 2...swap them
            {
                PQ temp = pq[i];
                pq[i] = pq[i - 1];
                pq[i - 1] = temp;
            }
        }
    }
}

int dequeue()
{
    if (size == 0)
        return 0;
    else
    {
        int data = pq[0].data;
        for (int i = 0; i < size; i++)
            pq[i] = pq[i + 1];
        size--;
        return data;
    }
}

void display()
{
    if (size == 0)
        printf("empty priority queue\n");
    else
    {
        for (int i = 0; i < size; i++)
            printf("ele = %d and p = %d\n", pq[i].data, pq[i].p);
    }
}