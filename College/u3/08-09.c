#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int bst[MAX];

void init()
{
    int i;
    for(i=0;i<MAX;i++)
    {
        bst[i]=-999;
    }
}
void insert(int x)
{
    int i=0;
    while((bst[i]!=-999) && (i<MAX))
    {
        if(x<bst[i])
        {
            i=i*2+1;  //left subtree
        }
        else
        {
            i=i*2+2;  //right subtree
        }
        bst[i]=x;
    }
}

void inorder(int i)
{
    if(bst[i]!=-999)
    {
        inorder(i*2+1);
        printf("\n Element is %d",bst[i]);
        inorder(i*2+2);
    }
}

void display()
{
    int i=0;
    printf("The elements in the array are\n");
    for(i;i<MAX;i++)
    {
        if(bst[i]!=-999)
        {
            printf("%d",bst[i]);
        }
    }
}

void menu()
{
    int choice,ele;
    while(1)
    {
        printf("Input your choice\n");
        printf("1. for insert into bst\n");
        printf("2. for inorder traversal of bst\n");
        printf("3. for displaying all elemenst in array\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Input the value to be inserted");
                scanf("%d",ele);
                insert(ele);
                break;
            case 2:
                inorder(0);
                break;
            case 3:
                display();
                break;
            default:
                exit(1);
            
        }
    }
}
int main()
{
    init();
    menu();
    return 0;
}


