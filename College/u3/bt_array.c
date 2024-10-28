/*

Trees- non linear structure
~binary tree-0,1,2
~binary search tree-0,1,2-special type of BT-minimum elements in left subtree and max elements in the right subtree
IMPLEMENTATION OF BT
1. insertion (level order inserting)
2. searching
3. count the number of nodes in the tree
4. find the height of the tree
5. find the minimum nodes
6. find the maximum nodes

--BST--


--------------

Binary tree implementation-ARRAY
1. start from the root 
2. fill the array level by level left to right.
3. if index starts at 0--node at ith index-- parent=floor((i-1)/2)
    left child=(2*i)+1
    right child=(2*i)+2

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
char tree[MAX];

void root(char data)
{
    if(tree[0]!='\0') //adding a root node is not in zeroeth index
    {
        printf("Tree already has a root\n");
    }
    else
    {
        tree[0]=data;
    }
}
void set_left(char data, int parent)
{
    if(tree[parent]=='\0')
    {
        printf("\n cannot set the child");
    }
    else
    {
        tree[(parent*2)+1]=data;
    }
}

void set_right(data,parent)
{
    if(tree[parent]=='\0')
    {
        printf("\n cannot set the child");
    }
    else
    {
        tree[(parent*2)+2]=data;
    }
}

void print()
{
    for(int i=0;i<MAX;i++)
    {
        if(tree[i]!='\0')
        {
            printf("%c",tree[i]);
        }
        else
        {
            printf("_");
        }
    }
}


int main()
{
    root('A');
    set_left('B',0);//(data,index_parent)
    set_right('C',0);
    set_left('D',1);
    set_right('E',1);
    set_right('F',2);
    set_left('G',3);
    print();

}

