#include <stdio.h>


int main (void)
{
    int a =0;
    int *ptr;
    ptr=&a;
    a=a+3;

    printf("%d \n", *ptr);


    int x =1, y=2;
    ptr =&x;
    y=*ptr;
    *ptr=0;

    printf("%d \n", *ptr);
    printf("%d \n", x);
    printf("%d \n", y);


    x=1;
    y=2;    

    int *ptr_x,*ptr_y;

    ptr_x=&x;
    ptr_y=&y;

    ++*ptr_x;
    ptr_x=ptr_y;

    printf("%d \n", *ptr_x);
    printf("%d \n", *ptr_y);
    printf("%d \n", x);
    printf("%d \n", y);    

    return 0;
}

