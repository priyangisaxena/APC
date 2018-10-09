#include<stdio.h>
int logicalshift(int x,int y)
{
 int z=x>>y;
 int m=(1<<(32-y))+(-1);
 return (z&m);
}
int main()
{
int x,y;
scanf("%d%d",&x,&y);
int num=logicalshift(x,y);
printf("%d",num);
}
