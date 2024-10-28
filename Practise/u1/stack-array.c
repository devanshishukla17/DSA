#include <stdio.h>
#include <stdlib.h>

int push(int *s,int *top, int size, int ele);
int pop(int *s,int *top,int size);
void display(int *s,int top,int size);

int main()
{
    int size,ele,ch,res;
    int top=-1;
    printf("enter size of array\n");
    scanf("%d",&size);
    int *s=(int *)malloc(sizeof(int)*size);

    while(1)
    {
        printf("\n 1. push an element\n");
        printf("2. pop the element\n");
        printf("3. display\n");

        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                printf("enter the element\n");
                scanf("%d",&ele);
                res= push(s,&top,size,ele);
                if(res>0)
                {
                    printf("element pushed\n");
                }
                break;
            case 2:
                res= pop(s,&top,size);
                if(res>0)
                {
                    printf("element popped is %d",res);
                }
                break;
            case 3:
                display(s,top,size);
                break;
            case 4:
                exit(0);
        }
    } 
}

int push(int *s,int *top, int size, int ele)
{
    if(*top==size-1)
    {
        printf("\nstack is overflow\n");
        return 0;
    }
    (*top)++;
    s[*top]=ele;
    return 1;

}
int pop(int *s,int *top,int size)
{
    if(*top==-1)
    {
        printf("\nstack underflow\n");
    }
    int ele=s[*top];
    (*top)--;
    return ele;

}
void display(int *s,int top,int size)
{
    if(top==-1)
    {
        printf("\n stack is empty\n");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d",s[i]);
        }
    }

}