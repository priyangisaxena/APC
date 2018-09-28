#include<stdio.h>
int find(int *a,int n)
{
    //printf("hello");
 int l=0;
 int r=n-1;
 int mid;
 while((r-l)>1)
 {
  mid=(l+r)/2;
  if(a[l]-l!=a[mid]-mid)
  r=mid;
  if(a[r]-r!=a[mid]-mid)
  l=mid;

 }
 return a[mid]+1;
}
int main()
{
    int n,i;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
int x=find(a,n);
printf("%d",x);
}
