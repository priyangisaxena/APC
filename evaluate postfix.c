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
}

void evaluate(char str[50])
{
 stk *s=(stk*)malloc(sizeof(stk));
 int n=strlen(str);
 initialize(s,n);
 int i=0,r=0;
 for(i=0;i<n;i++)
 {
   if(isdigit(str[i]))
   {
    push(s,str[i]-'0',n);
   }
   else
   {
     int x=s->a[s->top];
     pop(s);
     int b=s->a[s->top];
     pop(s);
     if(str[i]=='+')
     r=x+b;
     else if(str[i]=='-')
     r=b-x;
     else if(str[i]=='/')
     r=b/x;
     else
     r=x*b;
     push(s,r,n);
   }
 }
 printf("%d",s->a[s->top]);
}
 int main()
 {
 char str[50];
 scanf("%s",str);
evaluate(str);
}
