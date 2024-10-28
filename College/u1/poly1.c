
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int px;
    int py;
    int flag;
    struct node *link;
};

typedef struct node node_t;
struct list
{
    struct node *head;
};

typedef struct list list_t;

void init_list(list_t *);
void create_polynomial(list_t *);
void display(list_t *);
void add(list_t *, list_t *, list_t *);
void insert(list_t *ptr_list, int co, int x, int y);
void append(list_t *, list_t *, list_t *);
int main()
{
    struct list l1, l2, l3;
    init_list(&l1);
    init_list(&l2);
    init_list(&l3);
    printf("Enter the first polynomial terms:\n");
    create_polynomial(&l1);
    printf("Enter the second polynomial terms:\n");
    create_polynomial(&l2);
    printf("First polynomial:\n");
    display(&l1);
    printf("Second polynomial:\n");
    display(&l2);
    add(&l1, &l2, &l3);
    append(&l1, &l2, &l3);
    printf("\nThird polynomial:\n");
    display(&l3);
}
void create_polynomial(list_t *ptr_list)
{
    while (1)
    {
        int co;
        int x;
        int y;
        printf("Enter the coeff:");
        scanf("%d", &co);
        if (co == 0)
        {
            break;
        }
        printf("Enter powx powy:");
        scanf("%d %d", &x, &y);
        insert(ptr_list, co, x, y);
    }
}
void insert(list_t *ptr_list, int co, int x, int y)
{
    node_t *temp;
    temp = (node_t *)malloc(sizeof(node_t));
    temp->coeff = co;
    temp->px = x;
    temp->py = y;
    temp->flag = 1;
    temp->link = 0;
    if (ptr_list->head == NULL)
    {
        ptr_list->head = temp;
    }
    else
    {
        node_t *p = ptr_list->head;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}
void display(list_t *ptr_list)
{
    node_t *pres;
    // is list empty ?
    if (ptr_list->head == NULL)
        printf("\nEmpty list.\n");
    else
    {
        // copy the address of the first node
        pres = ptr_list->head;
        while (pres != NULL)
        {
            printf("%d %d %d->", pres->coeff, pres->px, pres->py);
            pres = pres->link;
        }
    }
    printf("\n");
}
void add(list_t *l1, list_t *l2, list_t *l3)
{
    node_t *i, *j;
    i = l1->head;
    printf("Entering add..\n");

    // Use the flag as 1 for unprocessed, 0 for processed
    while (i != NULL)
    {
        if (i->flag == 1)
        {
            int coeff_sum = i->coeff;
            j = l2->head;
            while (j != NULL)
            {
                if (j->flag == 1 && i->px == j->px && i->py == j->py)
                {
                    coeff_sum += j->coeff;
                    j->flag = 0; // Mark j as processed
                }
                j = j->link;
            }
            insert(l3, coeff_sum, i->px, i->py);
            i->flag = 0; // Mark i as processed
        }
        i = i->link;
    }
    printf("Exit add\n");
}

void append(list_t *l1, list_t *l2, list_t *l3)
{
    node_t *i;
    printf("Entering append\n");

    // Append remaining items in l1
    i = l1->head;
    while (i != NULL)
    {
        if (i->flag == 1)
        {
            insert(l3, i->coeff, i->px, i->py);
        }
        i = i->link;
    }

    // Append remaining items in l2
    i = l2->head;
    while (i != NULL)
    {
        if (i->flag == 1)
        {
            insert(l3, i->coeff, i->px, i->py);
        }
        i = i->link;
    }
    printf("Exit append\n");
}

void init_list(list_t *ptr_list)
{
    ptr_list->head = NULL;
}




