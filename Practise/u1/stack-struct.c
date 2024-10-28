#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *s;
    int top;
    int size;
}STACK;

int push(STACK *st, int x);
int pop(STACK *st);
void display(STACK st);


int main()
{
    int top,size;
    int ch;
    int k,x;
    STACK st;
    printf("enter size of stack");
    scanf("%d",&st.size);
    st.s= malloc(sizeof(int)*st.size);    //size enter karo and allocate memory for it
    st.top=-1;   //initialise top to -1

    while(1)
    {
        printf("\n 1. push an element\n");
        printf("2. pop the element\n");
        printf("3. display\n");

        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nenter data\n");
                scanf("%d",&x);
                k=push(&st,x);
                {
                    printf("\nelement pushed\n");
                }
                break;
            case 2:
                k=pop(&st);
                if(k>0)
                {
                    printf("elemnt popped is %d",k);
                }
                break;
            case 3:
                display(st);
                break;
            case 4:
                exit(0);
        }
    }
}

int push(STACK *st, int x)
{
    if(st->top==st->size-1)
    {
        printf("\n stack overflow\n");
        return 0;
    }
    st->top++;       // increment top
    st->s[st->top]=x;
    return 1;
}

int pop(STACK *st)
{
    int x;
    if(st->top==-1)
    {
        printf("\nstack underflow\n");
    }
    x=st->s[st->top];
    st->top--;
    return x;
}

void display(STACK st)
{
    if(st.top==-1)
    {
        printf("\nstack is empty\n");
    }
    else
    {
        for(int i=st.top;i>=0;i--)
        {
            printf("%d",st.s[i]);
        }
    }

}


