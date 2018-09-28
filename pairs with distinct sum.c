#include<stdio.h>
int main()
{
 int a[]={1,2,3,6,6,6,9,9};
 int i=0,j=7,k=18,count=0,p1=-1,p2=-1;
 while(i<j)
 {
  if(a[i]+a[j]==k&&a[i]!=p1&&a[j]!=p2)
  {
   count++;
   p1=a[i];
   p2=a[j];
   i++;
   j--;
  }
  else if(a[i]+a[j]>k)
  --j;
  else
  i++;
 }
 printf("%d",count);
}
