/*

-------------------------HEAP---------------------------
1.array representation of a heap
2. heap properties
3. heap types
4. creation/insertion of a heap
5. deletion of a heap
6. heapify
7. priority queues using heaps

1. heap memory and data structure are two different things.
heap data structure-complete binary tree
types-
min heap
    for every node x-->x's decendents will be larger than x
max heap
    for every node x-->x's decendents will be smaller than x
    
HEAP CONSTRUCTION--

TOP DOWN APPROACH
    RULES--Insert the element to the first space available
            rearrange(swapping) the elements so that the heap properties are followed

BOTTOM UP APPROACH(HEAPIFY)

inserted one element--depends on the number of swaps,depends on the tree height
space complexity-O(logn)
time complexity for inserting one O(1) to O(logn)==>O(nlogn)

heap's deletion is always the root-->
    replace the root with the last element
    rearrange(swap) only then required

*/

//MAX HEAP IMPLEMENTATION USING TOP DOWN APPROACH
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //INT_MAX in index 0
#define MAX 10

typedef struct heap
{
    int heap[MAX];
    int heapsize;
}HEAP;

void init(HEAP *h)
{
    h->heapsize=0; //heap is also a binary tree
    h->heap[0]=INT_MAX; //not used in the heap operation,index starts at 1
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insert(HEAP *h,int data)
{
    h->heap[++(h->heapsize)]=data;
    int currentsize=h->heapsize;
    int parent=currentsize/2;

    //bubble up: move the inserted element up to maintain the max heap property
    while(h->heap[parent] < h->heap[currentsize] && currentsize>1) 
    {
        swap(&h->heap[parent],&h->heap[currentsize]);
        currentsize=parent;
        parent=currentsize;
    }
}

int deletemax(HEAP *h)
{
    int max=h->heap[1]; //root element is deleted
    h->heap[1] = h->heap[(h->heapsize)--]; //moving the last element to the root
    int current=1;
    int child=2*current;

    //ensure the heap property is maintained
    while(child<= h->heapsize)
    {
        //select the larger child
        if(h->heap[child+1] > h->heap[child])
        {
            child++;
        }
        
        //if the current element is smaller than the larger child,then swap them
        if(h->heap[current] < h->heap[child])
        {
            swap(&h->heap[current],&h->heap[child]);
            current=child;
            child=2*current;
        }
        else
        {
            break;
        }
    }
    return max;
}

void display(HEAP *h)
{
    printf("Heap: ");
    for(int i=1;i<=h->heapsize;i++)
    {
        printf("%d",h->heap[i]);
    }
    printf("\n");
}
int main()
{
    HEAP *h=(HEAP*)malloc(sizeof(HEAP));
    init(h);
    int data,ch;
    do
    {
        printf("Enter the data to insert into the heap:");
        scanf("%d",&data);
        insert(h,data);
        printf("Heap after insertion: ");
        display(h);
        printf("press 1 to continue or 0 to stop");
        scanf("%d",&ch);
    } while (ch==1);

    printf("%d",deletemax(h));
    printf("\nAfter deleting:");
    display(h);
}


