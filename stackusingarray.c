#include<stdio.h>
typedef struct stack{
 int *a;
 int top;
 }stk;
 void initialize(stk *t,int n)
 {
  t->a=(int*)malloc(sizeof(int)*n);
  t->top=-1;
 }
void push(stk *s,int num,int n)
{
    if(isfull(s,n))
    {
        printf("can't insert any more element");
    }
    else
    {
        s->top++;
        s->a[s->top]=num;
    }
}
int isfull(stk* s,int n)
{
    if(s->top==n)
        return 1;
    return 0;
}
void pop(stk *s)
{
    int d=s->a[s->top];
    (s->top)--;
    printf("%d deleted",d);
}
 int main()
 {
 int n;
  stk *s=(stk*)malloc(sizeof(stk));
  scanf("%d",&n);
  initialize(s,n);
  int num,i;
  for(i=0;i<n;i++)
  {
   scanf("%d",&num);
   push(s,num,n);
  }
  for(i=s->top;i!=-1;i--)
  {
      printf("%d ",s->a[i]);
  }
  pop(s);
  for(i=s->top;i!=-1;i--)
  {
      printf("%d ",s->a[i]);
  }
  }
