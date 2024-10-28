#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary search tree
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;

NODE *insert(NODE *root,int x)
{
    if(root==NULL)
    {
        //create a new node if the root is empty
        NODE *nn=(NODE*)malloc(sizeof(NODE));
        nn->data=x;
        nn->left=nn->right=NULL;
    }
    else if(x<root->data)
    {
        root->left=insert(root->left,x);
    }
    else
    {
        root->right=insert(root->right,x);
    }
    return root;
}

NODE* delete(NODE *root,int x)
{
    if(root==NULL)
    {
        return root;  //if the tree is empty
    }
    //recursively find the node to be deleted
    if(x<root->data)
    {
        root->left=delete(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=delete(root->right,x);
    }
    else
    {
        //found the node to be deleted

        //case 1 is deleting a leafnode
        if((root->left==NULL) && (root->right==NULL))
        {
            free(root);
            root=NULL;
        }
        //case 2 is delete a node with one child
        else if(root->left==NULL) //right child exists
        {
            NODE *temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL) //right child exists
        {
            NODE *temp=root;
            root=root->left;
            free(temp);
        }

        //case
        else
        {
            NODE *temp=findmin(root->right); //inorder successor
            root->data=temp->data;
            root->right=delete(root->right,x);
        }

    }
}

int main()
{

    NODE *root = NULL;
   
    root = Insert(root, 20);
    root = Insert(root, 16);
    root = Insert(root, 28);
    root = Insert(root, 15);
    root = Insert(root, 18);
    root = Insert(root, 14);
    root = Insert(root, 17);
    root = Insert(root, 19);
    root = Insert(root, 22);
    root = Insert(root, 21);
    root = Insert(root, 30);
    root = Insert(root, 39);

    // Deleting node with value 5
    //root = Delete(root, 5);
    //root = Delete(root, 4);
     root = delete(root, 21);

    // Print nodes in inorder traversal after deletion
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}