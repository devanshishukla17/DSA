#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;    
}NODE;

typedef struct tree
{
    NODE root;
}TREE;


NODE *createnode()
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));

}

int count(NODE *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}

void inorder(NODE *root) //left,root,right
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void preorder(NODE *root) //root,left,right
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);        
        preorder(root->right);
    }
}

void postorder(NODE *root) //left,right,root
{
    if(root!=NULL)
    {
        postorder(root->left);        
        postorder(root->right);
        printf("%d",root->data);
    }
}

int height(NODE *root)
{
    if(root==NULL)
    {
        return -1;        
    }
    int l=height(root->left);
    int r=height(root->right);
    return (l>r?l:r)+1; //if l>r gives that answer and adds 1 to it
}

int leafnode(NODE *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if((root->left)==NULL && (root->right)==NULL)
    {
        return 1;
    }
    return leafnode(root->left)+leafnode(root->right);
}

int main()
{

}

