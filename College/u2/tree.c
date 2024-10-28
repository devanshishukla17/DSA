// BINARY TREE THEORY

/*
main one is the parent the ones that come out of it are child nodes, there are siblings who are child nodes of same parent
a node which has no children is called leaf node/external node
A node which has a child is called the non leaf node/internal node
3. Ansecstors-
~depth is bottom to top
~height is top to bottom


Binary trees are:
    atmost 2 children(0,1,2).
    
leaf node ka left and right pointer is null
struct node
{
    struct node *right;
    char c;
    struct node *left;
}

TYPES OF BINARY TREES:
    1. full/proper/strict binary tree.
        every node has either 0 or two children.
    2. complete binary tree
        all *levels* are completely fixed(except the last level)
        nodes in the last level are filled from left to right.
    3. perfect binary tree  -- will always be a complete and full binary tree.
    4. degenerate binary tree
        
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int data;
    struct node *left;
    struct node *right;
}TNODE;

typedef struct tree
{
    TNODE* root;
}TREE;




void init(TREE *t)
{
    t->root=NULL;
}

void insert(TREE *t,int x)
{
    TNODE *temp=(TNODE*)malloc(sizeof(TNODE));
    temp->data=x;
    temp->left=temp->right=NULL;

    TNODE *current,*previous;

    current=t->root;
    previous=NULL;

    if(current=NULL) //first element
    {
        t->root=temp;
    }
    else //there are more elements
    {
        while(current!=NULL)
        {
            previous=current;
            if(x>current->data) //agar x ka value is greater than current value then it will go right.
            {
                current=current->right;
            } 
            else
            {
                current=current->left;
            }
        }
        if(x>previous->data)
        {
            previous->right=temp;
        }
        else
        {
            previous->left=temp;
        }
    }
}

int count_t(TREE *t)
{
    int n=0;
    n=count(t->root);
    return 0;
}

int count(TNODE *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if((root->left==NULL) && (root->right=NULL)) //only one node
    {
        return 1;
    }
    int l=count(root->left);
    int r=count(root->right);

    return(l+r+1);
}



void main()
{
	TREE t;
	int ch,num,k,n;
	init(&t);
 
	while(1)
	{
		printf("\n1.Insert");
		printf("\n2.No. of nodes");
		printf("\n3..recursively insert..");
		printf("\n4.find smallest");
		printf("\n5.find largest");
		printf("\n6..exit");
        printf("\nEnter the choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\nEnter the element:");
					scanf("%d",&num);
					insert(&t,num);
					break;
			case 2: k=count_t(&t);
					printf("\nthe number of nodes=%d",k);
					break; 
			case 3:	printf("\nEnter the element");
					scanf("%d",&num);
					rinsert_t(&t,num);
					break;
			case 4:n=minimum(&t);
					printf("\nThe smallest element = %d\n",n);
					break;
			case 5:n=maximum(&t);
					printf("\nthe largest element = %d\n",n);
					break; 
			case 6:exit(0);
       }
    }
}

