//program to implement circular doubly linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* next,*prev;
};

typedef struct node NODE;
struct dlist
{
	NODE *head;
};

typedef struct dlist DLIST;

void insert_head(DLIST*,int);
void insert_tail(DLIST*,int);
void delete_node(DLIST*,int);
void display(DLIST*);
void init_list(DLIST*);

int main()
{
 
  int ch,x,pos;
  
  DLIST dl;
  
  init_list(&dl);

  while(1)
  { 
    display(&dl);
    printf("\n1..Insert Head\n");
    printf("2..Insert Tail\n");
    printf("3..Delete a Node..\n");
    printf("4..Display\n");
    printf("5..Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:printf("Enter the number...");
            scanf("%d",&x);
            insert_head(&dl,x);
            break;
     case 2:printf("Enter the number...");
            scanf("%d",&x);
            insert_tail(&dl,x);
            break;
    case 3: printf("Enter the value of the node to be deleted...");
            scanf("%d",&x);
            delete_node(&dl,x);
            break;
   
     case 4:display(&dl);
            break;
     case 5:exit(0);
   }
 }
}

void init_list(DLIST* ptr_list)
{
	ptr_list->head=NULL;
}

void insert_head(DLIST* ptr,int x)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data=x;
    temp->prev=temp->next=temp;

    NODE *p=ptr->head;
    if(p==NULL)
    {
        ptr->head=temp;
    }
    else
    {
        
    }
}

void display(DLIST *ptr)
{
    NODE *p=ptr->head;
    if(p==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
       
    }
}
 