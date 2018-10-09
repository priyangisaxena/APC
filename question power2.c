#include<stdio.h>
int ispower2(int x)
{
 int bit=(x&1);
 return !bit;
}
int main()
{
 int x;
 scanf("%d",&x);
 int ch=ispower2(x);
 if(ch==1)
 printf("yes");
 else
 printf("no");
}
