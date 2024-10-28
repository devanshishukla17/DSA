/*

TBT-variant of a bt where the null pointers(pointers of leaf nodes) are replaced with threads.
~these threads allow a tree to be traversed efficiently in an INORDER WAY(left,root,right) without
requiring a stack or recursion.
MAIN PURPOSE-->traversal is faster
            -->less memory intrusive

In a TBT,instead of setting the left and right pointers to NULL,they are used to point to:
    ~left pointer-->inorder predecessor
    ~right pointer-->inorder successor

Types--SINGLE threaded binary tree(only one pointer is replaced by threads(left and right))
            ~left threaded binary tree
                -->left pointer points to inorder predecessor 
            ~right threaded binary tree

     --

*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int lthr; //indicates if left is a thread
    int rthr; //indicates if right is a thread
}NODE;

NODE *createnode(int x)
{
    NODE *nn=(NODE*)malloc(sizeof(NODE));
    nn->data=x;
    nn->rthr=nn->lthr=1;
    nn->right=nn->left=NULL;
    return nn;
}

NODE* inordersuccessor(NODE *t)
{
    if(t->rthr==1)
    {
        return t->right;
    }
    t=t->right;
    while(t->lthr==0)
    {
        t=t->left;
    }
    return t;
}

void inorder(NODE *root)
{
    if(root==NULL)
    {
        printf("empty tree");
        return;
    }
    //traverse the tree using threads
    NODE *t=root;
    //traverse to the left most node
    while(t->lthr!=0)
    {
        t=t->left;
    }
    while(t!=NULL)
    {
        printf("%d",t->data);
        t=inordersuccessor(t);
    }
}

NODE* insertnode(NODE *root,int x)
{
    NODE *t=root;
    NODE *parent=NULL;
    NODE *nn=createnode(x);
    if(root==NULL) //tree is empty
    {
        root=nn;
        return root;
    }
    //while loop for traversal
   
    while(t!=NULL)
    {
        parent=t;
        if(x<t->data)
        {
            if(t->lthr==0)
            {
                t=t->left;
            }
            else
            {
                break;
            }
        }
        else if(x>t->data)
        {
            if(t->rthr==0)
            {
                t=t->right;
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("duplicate key\n");
            return root;
        }
    }
    //inserting node in position
    if(x < parent->data)
    {
        nn->left=parent->left; //inorder predecessor
        nn->right=parent; //inorder sucessor
        parent->left=nn;
        parent->lthr=0;
    }
    else
    {
        nn->left=parent; //inorder predecessor
        nn->right=parent->right; //inorder sucessor
        parent->right=nn;
        parent->rthr=0;
    }
    return nn;
}

int main()
{
    int data,ch;
    NODE *tbst=NULL;
    do
    {
        printf("Enter the data:");
        scanf("%d",&data);
        tbst=insertnode(tbst,data);    
        printf("press 1 to continue");
        scanf("%d",&ch);    
    }while(ch==1);

    printf("inorder traversal:\n");
    inorder(tbst); 
    printf("\n");
    return 0;  
}