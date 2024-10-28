//pointers
// #include <stdio.h>
// int main()
// {

    //-------------PONTERS-----------------------------------


    // int x=10;
    // int *y;
    // printf("%d\n",x);
    // printf("%d\n",&x);
    // y=&x;
    // printf("%d\n",*y);//10
    // printf("%d\n",*(&x));//10
    // printf("%d\n",&y,y);

    // int x=66;
    // int *y;
    // int **z;//double pointer concept
    // y=&x;
    // z=&y;
    // printf("%d\n",x);//66
    // printf("%d\n",**z);//66
    // printf("%d\n",*z);//address of y
    // printf("%d\n",*y);//66
    

    // int a=89;
    // double *ptr=&a;//AVOID

    // const int a=10;//error because read only and it cannot change
    // a=999;
    // printf("%d\n",a);

    // const int a;//error because read only and it cannot change
    // a=10; //error,assignment has to be during initialization
    // printf("%d\n",a);

    //the two statements are same
    // const int a=10;
    // int const a=10;


    // const int a=10;
    // const int b=30;
    // const int *ptr =&a;
    // printf("%d\n",a);//10
    // printf("%d\n",*ptr);//10
    // ptr=&b;
    // printf("%d\n",b);//30
//}

//--------------ARRAY AND STRUCTURES-----------------------------

//memory is continuous,elements will be of same type.fixed size,indexing,pointers,by default arrays are constant pointers

// #include <stdio.h>
// int main()
// {
// //datatype arrayname[size]={1,2,3,4,5}
// int a[6]={1,2,3,4,5};
// int *p=a;//int *p=&a[0];
// int i;
// for(i=0;i<5;i++)
// {

    //direct addition is fine in a but pointer is okay with both a and p

    //printf("%d\n",a[i]);
    //printf("%d\n",p[i]);
    // printf("%d\n",p+i);
    // printf("%d\n",*(p+i));

    //using *p++; (post inc)++ has high precedence than +
    //printf("%d\n",*p++);//1,2,3,4,5
    //printf("%d\n",*a++);//ERROR as a is a constant pointer

    //*++p (pre inc and * both have the same precedence R->L)

    //printf("%d\n",*++p); // there is a undefined behavior since its array index out of bound and you cant use pre inc in arrays and pointers

//}
//}


// #include <stdio.h>
// void check(int a[],int size)//void check(int *arr,int size)
// {
//     //printf("%d\n",sizeof(a)); //avoid sizeof operator in the main function since its a compile time operator
// }
// int main()
// {
//     int a[]={10,20,30};
//     int *ptr=a;
//     //you have to pass array size inside a function
//     int size=sizeof(a)/sizeof(a[0]);
//     check(a,size);
//     //printf("%d %d %d\n",a,a+1,a+2);
//     printf("%d %d\n",a,&a+1);//it will skip 12 bytes and give
    
// }

#include <stdio.h>
void disp(int *a,int n)
{
    int i;
    for(i=0;i<n+1;i++)
        printf("%d ",*(a+i)); //a[i]
}
int main()
{
    int a[5]={1,2,3,4,5};
    int size=sizeof(a)/sizeof(a[0]);
    disp(&a[0],size); // disp)a,size
}
