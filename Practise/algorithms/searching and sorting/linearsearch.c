//LINEAR SEARCH
#include <stdio.h>
int searchinsorted(int [],int,int);
int searchinunsorted(int [],int,int);
int main()
{
    int unsortedarr[ ]= {11,2,9,13,57,25,17,1,90,3};
    int sortedarr[ ]= {1,2,3,9,11,17,25,57,90};
    int num,pos;
    printf("enter number to be searched");
    scanf("%d",&num);
    pos=searchinunsorted(unsortedarr,10,num);
    if(pos==-1)
    {
        printf("number is not present\n");
    }
    else
    printf("number is at position %d in the array\n",pos);

    printf("enter number to be searched");
    scanf("%d",&num);
    pos=searchinsorted(sortedarr,10,num);
    if(pos==-1)
    {
        printf("number is not present");
    }
    else
    printf("number is at position %d in the array",pos);
}
int searchinunsorted(int arr[],int size,int num)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]==num)
            return i;
    }
    return -1;
}
int searchinsorted(int arr[],int size,int num)
{
    int i;
    if(num>arr[size-1])
        return -1;
    for(i=0;i<size;i++)
    {
        if(arr[i]==num)
            return i;
        if(arr[i]>num)
            return -1;
    }
    return -1;
}
