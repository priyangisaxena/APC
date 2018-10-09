#include<stdio.h>
int conditional(int x,int y,int z)
{
return ((x&y)|((~x)&z));
}
int main()
{
int x,y,z;
scanf("%d%d%d",&x,&y,&z);
int a=conditional(x,y,z);
printf("%d",a);
}
