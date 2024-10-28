#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;

typedef struct list
{
    NODE* head;
}LIST;

void init(LIST *ptr)
{
    ptr->head=NULL;
}

NODE *create(int ele)
{
    NODE *temp=malloc(sizeof(NODE));
    if(temp!=NULL)
    {
        temp->data=ele;
        temp->link=NULL;
    }
    return temp;
}

void insertatfront(LIST *ptr,int ele)
{
    NODE *temp=create(ele);
    temp->link=ptr->head;
    ptr->head=temp;
}

void insertatrear(LIST *ptr,int ele)
{
    NODE *cur,*temp=create(ele);
    if(ptr->head==NULL)  // list is empty
    {
        ptr->head=temp;  // toh direct hi ho jayega
    }
    else
    {
        cur=ptr->head;
        while(cur->link!=NULL)  //jab tak end na reach ho
        {
            cur=cur->link;    //current ko badhate jao,when it reaches null vo loop ke bahar aayega
        }
        cur->link=temp;  // tab current ka link give to temp.
    }

}
void insertatpos(LIST *ptr,int ele,int pos)
{
    NODE *cur=ptr->head,*prev=NULL,*temp=create(ele);
	int x=1;

	while ((cur != NULL) && (x < pos))  // go to the desired position
	{
		x++;    //x ko aage badhate jao
		printf("%d\n",x);
		prev = cur;
		cur =cur->link;
	}
    if(cur==NULL) // current is NULL
	{
		if (x==pos) // insert at the end
			prev->link = temp;
		else
			printf("\nInvalid position..");
	}
    else
    {
        if (prev == NULL) // inserting in postion 1
		{
			ptr->head = temp;
			temp->link =cur;
		}
		else // prev is not NULL, inserting node in the middle
		{
			temp->link =cur;
			prev->link = temp;
		}
    }        
}

void display(LIST *ptr)
{
    NODE *cur=ptr->head;
    if(ptr->head==NULL)   //list empty ho gayi
    {
        printf("list is empty\n");
    }
    else
    {
        while(cur!=NULL)   //jab tak current ka link null na ho
        {
            printf("%d\n",cur->data);   //current ka data print karo
            cur=cur->link;            // and keep passing the link to the next one
        }
    }
}
int deleteatfront(LIST *ptr)
{
    NODE *cur=ptr->head;
    if(ptr->head==NULL)   //agar list is empty return garbage value
    {
        return 999;
    }
    else
    {
        ptr->head=cur->link;    //varna head ko point to current ka link
        int x=cur->data;        //x stores data of the current
        free(cur);              //current ko azaad kar do
        return x;               //value ko return kar do
    }
}
int deleteatrear(LIST *ptr)
{
    NODE *prev=NULL,*cur=ptr->head;
    int x;
    if(ptr->head==NULL)     //agar list is empty return garbage value
    {
        return 999;
    }
    if(cur->link==NULL)     //agar ek hi element hai
    {
        ptr->head=NULL;     //put the head as null 
        x=cur->data;        //and x ko current ka data de do
        free(cur);          //free current
    }
    else
    {
        while(cur->link!=NULL)      //jab tak end na reach ho
        {
            prev=cur;               //prev ko current do and keep continuing current
            cur=cur->link;
        }                           //reaches the end toh give prev ka link as null and free current
        prev->link=NULL;            
        x=cur->data;
        free(cur);
    }
    return x;
}

int main()
{
    int ch,ele,pos;
    int x;
    LIST ll;
    init(&ll);
    while(1)
    {
        printf("1.insert at front\n");
        printf("2. insert at rear\n");
        printf("3.insert at position\n");
        printf("4. display\n");
        printf("5. delete at front\n");
        printf("6. delete at rear\n");

        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter element");
                scanf("%d",&ele);
                insertatfront(&ll,ele);
                break;
            case 2:
                printf("enter element");
                scanf("%d",&ele);
                insertatrear(&ll,ele);
                break;
            case 3:
                printf("enter the position and element\n");
                scanf("%d %d",&ele,&pos);
                insertatpos(&ll,ele,pos);
                break;
            case 4:
                display(&ll);
                break;
            case 5:
                x=deleteatfront(&ll);
                if(x=999)
                {
                    printf("list is empty");
                }
                else
                {
                    printf("deleted element is:%d",ele);
                }
                break;
            case 6:
                x=deleteatrear(&ll);
                if(x=999)
                {
                    printf("list is empty");
                }
                else
                {
                    printf("deleted element is:%d",ele);
                }
                break;
        }		
    }
}

