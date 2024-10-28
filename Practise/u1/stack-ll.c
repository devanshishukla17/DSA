#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;

typedef struct stack
{
    NODE *top;
}STACK;

void display(STACK *st);
void init(STACK *st);
void push(STACK *st,int ele);
int pop(STACK *st);

int main()
{
    STACK *s;
    int ele,ch,res;
    init(&s);
    while(1)
    {
        printf("\n 1. push an element\n");
        printf("2. pop the element\n");
        printf("3. display\n");

        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nenter element");
                scanf("%d",&ele);
                push(&s,ele);
                break;
            case 2:
                res=pop(&s);
                if(res>0)
                {
                    printf("element popped is %d",res);
                }
                break;
            case 3:
                display(&s);
                break;
            case 4:
                exit(0);
        }
    }
}

void init(STACK *st)
{
    st->top=NULL;
}

void push(STACK *st,int ele)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data=ele;
    temp->link=NULL;

    temp->link=st->top;
    st->top=temp;
}

int pop(STACK *st)
{
    int data;
    NODE *p;
    p=st->top;
    if(p==NULL)
        printf("stack is empty");
    data=p->data;
    st->top=p->link;
    free(p);
    return data;
}

void display(STACK *st)
{
    NODE* p=st->top;
    if(p==NULL)
        printf("stack is empty");
    else
    {
        while(p!=NULL)
        {
            printf("%d-->",p->data);
            p=p->link;
        }
    }

}