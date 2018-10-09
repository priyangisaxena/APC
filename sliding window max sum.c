#include<stdio.h>
typedef struct queue{
 int *a;
 int front,rear;
}queue;
queue* initialize(int n)
{
 queue* q=(queue*)malloc(sizeof(queue));
 q->a=(int*)malloc(sizeof(int)*n);
 q->front=q->rear=-1;
 return q;
}
void push(queue *q,int num,int n)
{
 /*if(isfull(q,n))
 printf("can't add more");
 else
 {*/
  q->a[++q->rear]=num;
  if(q->front==-1)
  q->front++;

}
void pop(queue *q)
{
 if(isempty(q))
 {
  printf("can't pop");
 }
 else
 {
  ++q->front;
  if(q->front==q->rear)
  q->front=q->rear=-1;
 }
}
int isfull(queue *q,int n)
{
 if(q->rear==n)
 return 1;
 return 0;
}
int isempty(queue *q)
{
 if(q->rear==-1)
 return 1;
 return 0;
}
void display(queue *q)
{
 int i;
 for(i=q->front;i<=q->rear;i++)
 printf("%d ",q->a[i]);
}
void cal(int *arr,int n,int k)
{
    int cur=0,max=0,i;
    queue *q=initialize(n);
 /*   for(i=0;i<n;i++)
        printf("%d ",arr[i]);*/

    for(i=0;i<k;i++)
    {
        push(q,i,k);
        cur+=arr[i];
    }
    max=cur;
    for(i=3;i<n;i++)
    {
        int p=arr[q->a[q->front]];
        printf("%d*",p);
        pop(q);
        push(q,i,k);

        cur=cur-p+arr[i];
        printf("%d*\n",cur);
        if(cur>=max)
            max=cur;
    }
    printf("max sum: %d ",max);
}
int main()
{
int i,n,num,k;
scanf("%d",&n);
int *arr=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
scanf("%d",&k);
cal(arr,n,k);
}
