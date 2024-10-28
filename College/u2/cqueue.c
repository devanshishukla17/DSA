#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front = -1, last = -1;
int cq[MAX];

// function to insert an element into the function
void cqinsert(int x)
{
    if (last == MAX - 1) // check for last element and update suitably
        last = 0;
    else
        last++;
    if (front == last) // check if cq is full
        printf("CQ FULL\n");
    else
    {
        cq[last] = x; // adding the element into the queue
    }
    if (front == -1) // update the front index incase 1st element in the queue
        front = 0;
}

int cqdelete(void)
{
    int x = -999;
    if (front == -1) // check if cqueue is empty
    {
        printf("queue is underflow\n");
    }
    else
    {
        x = cq[front];     // remove the element from the cqueue
        if (front == last) // check if this is the only element
        {
            front = -1; // reset the frontand last to indicate empty
            last = -1;
        }
        else

            front++;
    }
    return x;
}

void cqdisplay(void)
{
    int index1, index2;
    index1 = front;
    index2 = last;
    if (index1 == -1)
        printf("empty list\n");
    else
    {
        for (int i = index1; i <= index2; i++)
        {
            printf("%d-->\n", cq[i]);
        }
    } // end of else
}

void cqmenu(void)
{
    int choice, x;
    while (1)
    {
        printf("Input your choice--1. for cqinsert\n");
        printf("Input your choice--2. for cqdelete\n");
        printf("Input your choice--3. for cqdisplay\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("insert the value to be inserted into the queue\n");
            scanf("%d", &x);
            cqinsert(x);
            break;
        case 2:
            x=cqdelete();
            printf("element deleted is%d\n",x);
            break;
        case 3:
            printf("the elements in the dequeue are:\n");
            cqdisplay();
            break;
        default:
            printf("exiting the program");
            break;
        }
    }
}

int main()
{
    printf("welcome to circular queue");
    cqmenu();
    return 0;
}