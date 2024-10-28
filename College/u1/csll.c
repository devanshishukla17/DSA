// program to implement circular singly linked list
//CSLL implementation
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE;
typedef struct list
{
    NODE *last; // pointer to the last node
}CLIST;

void init_list(CLIST *);
void insert_front(CLIST *, int);
void insert_end(CLIST*,int);
void delete_node(CLIST*, int);
void display(CLIST*);

int main()
{
	int ch,data,pos;
	CLIST l;
	init_list(&l);

    while(1)
	{
		display(&l);
		printf("\n1..insert_head");
		printf("\n2..insert_tail");
		printf("\n3..Display");
		printf("\n4.Delete a node");
		printf("\n5..Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the data...");
			             scanf("%d",&data);
						 insert_front(&l,data);
						 break;
			case 2:printf("\nEnter the data...");
			             scanf("%d",&data);
						 insert_end(&l,data);
						 break;			 
			case 3:display(&l);
			             break;
			 
			case 4:printf("\nEnter the data...");
			             scanf("%d",&data);
						 delete_node(&l,data);	
                         break;	
					   
			case 5:exit(0);
		}
	}
}
void init_list(CLIST *ptr_list)
{
    ptr_list->last = NULL;
}