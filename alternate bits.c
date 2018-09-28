#include<stdio.h>
int main()
{
 int a=0x10101100;
 int num=a<<1;
 int x=num&1;
 if((a&x)==0)
 printf("alternate");
 else
 printf("not alternate");
}
