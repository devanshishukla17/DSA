#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;

typedef struct dlist
{
    NODE *last;
}CLIST;

void init(CLIST *ptr)
{
    ptr->last=NULL;
}

NODE *create(int ele)
{
    NODE *temp=malloc(sizeof(NODE));
    if(temp!=NULL)
    {
        temp->link=temp;
        temp->data=ele;
    }
    return temp;
}

void insertatfront(CLIST *ptr,int ele)
{
    NODE *p=ptr->last;
    NODE *temp=create(ele);

    if(p==NULL)
    {
        ptr->last=temp;
    }
    else
    {
        temp->link=p->link;
        p->link=temp;
    }
}

void insertatrear(CLIST *ptr,int ele)
{
    NODE *p=ptr->last;
    NODE *temp=create(ele);
    if(p==NULL)
    {
        ptr->last=temp;
    }
    else
    {
        temp->link=p->link;
        p->link=temp;
        ptr->last=temp;
    }
}

void display(CLIST *ptr)
{
    NODE *end,*cur,*prev;
    if(ptr->last==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        end =ptr->last; //copy last nodes address
		cur=end->link;
        while(cur!=end)
        {
            printf("%d-->",cur->data);
            cur=cur->link;
        }
        printf("%d",cur->data);  //prints last data
    }
}

void delete(CLIST *ptr,int ele)
{
    NODE *end,*prev,*cur;
    end=ptr->last;
    prev=end;
    cur=end->link;
    while((cur->data!=ele) && (cur!=end))
    {
        prev=cur;
        cur=cur->link;
    }    
    if(cur->data==ele)
    {
        if(cur->link=cur)//only one node
        {
            ptr->last=NULL;
        }
        else
        {
            prev->link=cur->link;
            if(cur==end)
            {
                ptr->last=prev;
            }
        }
        free(cur);          
    }
    else
    {
        printf("data not found.\n");
    }
}

int main()
{
    int ch,ele,pos;
    CLIST cl;
    init(&cl);

    while(1)
    {
        printf("\n1. Insert at front\n");
        printf("2. insert at last\n");
        printf("3. display\n");
        printf("4. delete a node\n");
        printf("5. exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the element\n");
            scanf("%d",&ele);
            insertatfront(&cl,ele);
            break;
        
        case 2:
            printf("Enter the element\n");
            scanf("%d",&ele);
            insertatrear(&cl,ele);
            break;

        case 3:
            display(&cl);
            break;

        case 4:
            printf("Enter the element");
            scanf("%d",&ele);
            delete(&cl,ele);
            break;

        case 5:
            exit(0);
        }
    }
}
