#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct node 
{
    int data;
    struct tnode *left;
    struct tnode *right;
}NODE;

typedef struct tree
{
    int top;
    NODE *stack[MAX];
}TREE;

NODE *createNode(int data)
{
    NODE *nn = (NODE *)malloc(sizeof(NODE));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

void push(NODE *nn,TREE *t)
{
    if(t->top>MAX-1)
    {
        printf("The stack is overflow\n");
    }
    else
    {
        t->stack[++(t->top)] = t;
    }
}

NODE *pop(TREE *t)
{
    if(t->top==-1)
    {
        printf("stack is underflow\n");
        return NULL;
    }
    else
    {
        return t->stack[(t->top)--];
    }
}

NODE *insertNode(NODE *nn, int data)
{
    if (isEmpty(nn))
    {
        nn= createNode(data);
    }
    else if (data <=nn->data)
    {
        nn->left = insertNode(nn->left, data);
    }
    else
    {
        nn->right = insertNode(nn->right, data);
    }
    return nn;
}

void preorder(NODE *nn)
{
    if(nn==NULL)
    {
        printf("The tree is empty\n");
        return NULL;
    }
    else
    {
        TREE *t = (TREE *)malloc(sizeof(TREE));
        t->top = -1;
        push(nn,t);

    while (t->top!=-1)
    {
        NODE *temp = pop(t);
        printf("%d",temp->data);

        if (temp->right!= NULL)
        {
            push(temp->right,t);
        }
        if (temp->left != NULL)
        {
            push(temp->left,t);
        }
    }
    }
}



