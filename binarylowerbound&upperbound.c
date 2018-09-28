#include<stdio.h>
int lowerbound(int *a,int n,int num)
{

int left=0; int right=n;
 int mid;
 while(left<right)
 {
     mid=(left+right)/2;
     if(num<=a[mid])
            right=mid;
     else
        left=mid+1;
 }
 return left;

}
int upperbound(int *a,int n,int num)
{

 int left=0;
 int right=n;
 while(left<right)
 {
    int mid=(left+right)/2;
     if(num>=a[mid])
        left=mid+1;
     else
        right=mid;
 }
 return left;
}
int main()
{
int n,i;
scanf("%d",&n);
int *a=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter a number");
int num;
scanf("%d",&num);
int lb=lowerbound(a,n,num);
int ub=upperbound(a,n,num);
printf("lower bound is %d",lb);
printf("\nupper bound is %d",ub);
}
