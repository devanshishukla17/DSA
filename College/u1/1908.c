#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
    int data;
    struct node *link;
}NODE;

typedef struct list
{
    NODE *head;


}LIST;

int main()
{
    LIST l1,l2,l3;
    init_list(&l1);
    init_list(&l2);
    init_list(&l3);
    printf("Enter list1..\n");
    create_list(&l1);
    printf("Enter list2..\n");
    create_list(&l2);
}
void init_list(LIST *ptr_list)
{
    ptr_list->head=NULL;

}

void create_list(LIST *ptr_list)
{
    int x;
    while(1)
    {
        printf("\nEnter the elements:\n");
        scanf("%d",&x);
        if(x==0)
        {
            break;
        }
        insert_order(ptr_list,x);
    }
}