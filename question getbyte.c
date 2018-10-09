#include<stdio.h>
int getByte(int x,int n)
{
 int a=x>>(n*8);
 int m=(1<<9)+(-1);
 return (a&m);
}
int main()
{
 int x=12578329;
 int n=0;
 int y=getByte(x,n);
 printf("%d",y);
}
