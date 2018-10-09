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
        (s->top)++;
        s->a[s->top]=num;
    }
}
int isempty(stk *s)
{
 if(s->top==-1)
 return 1;
 return 0;
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
   // printf("\n%d deleted",d);
}
void cal(stk *t,int n)
{
 stk *s=(stk*)malloc(sizeof(stk));
 initialize(s,n);
 int max_area=0;
 int area=0;
 int i=0,tp;
 while(i<n)
 {
     if(isempty(s)||(t->a[i])>=(t->a[s->top]))
      {
           push(s,i,n);
           i++;
      }
     else
     {
         tp=s->top;
         pop(s);
         area=t->a[tp]*(isempty(s)?i:(i-(s->top)-1));
         printf("*%d*%d**",t->a[tp],area);
         if(area>=max_area)
            max_area=area;
     }
 }
 while(isempty(s)==0)
 {
         tp=s->top;
         pop(s);
         area=t->a[tp]*(isempty(s)?i:(i-(s->top)-1));
         printf("*%d*%d**",t->a[tp],area);
         if(area>=max_area)
            max_area=area;
 }
 printf("%d",max_area);
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
  cal(s,n);
}
