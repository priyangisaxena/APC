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
   // printf("%d deleted",d);
}
int comp(char ch)
{
    if(ch=='(')
        return 0;
    else if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
}
void infixtopostfix(char str[50])
{
    stk *s=(stk*)malloc(sizeof(stk));
    int n=strlen(str);
    initialize(s,n);
    int i;
    char res[50]="";
    int k=0;
  //  printf("%s",str);
    for(i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            push(s,i,n);

        }
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
                while(comp(str[s->a[s->top]])>=comp(str[i]))
                {
                    int t=s->a[s->top];
                    pop(s);
                    res[k++]=str[t];
                }
                push(s,i,n);

        }
        else if(str[i]==')')
        {

            while(str[s->a[s->top]]!='(')
            {
                int t=s->a[s->top];
                pop(s);
                res[k++]=str[t];
            }
            if(s->a[s->top]!=0)
                pop(s);


        }
        else
            res[k++]=str[i];
    }
  //  printf("%d \n",s->top);
    while(s->top!=0)
    {
      int t=s->a[s->top];
        pop(s);
        res[k++]=str[t];

    }
    printf("%s",res);
}
 int main()
 {
 char str[50];
 scanf("%s",str);
infixtopostfix(str);
}
