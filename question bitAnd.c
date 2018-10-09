#include<stdio.h>
int bitAnd(int x,int y)
{
 return (~((~x)|(~y)));
}
int main()
{
 int x,y;
 scanf("%d%d",&x,&y);
 int ch=bitAnd(x,y);
 printf("%d",ch);
}
