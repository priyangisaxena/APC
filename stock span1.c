#include<stdio.h>
typedef struct stack{
 int data;
 struct stack *next;
}node;
node *createnode(int d)
{
    node *n=(node*)malloc(sizeof(node));
    n->data=d;
    n->next=NULL;
    return n;
}
void push(node **root,int d)
{
    if(*root==NULL)
    {
        *root=createnode(d);
    }
    else
    {
        node *n=createnode(d);
        n->next=*root;
        *root=n;
    }
}
int pop(node **root)
{
    if(*root==NULL)
    {
        return -1;
    }
    else
    {
        int d=(*root)->data;
        *root=(*root)->next;
        return d;
    }
}
void display(node *root)
{
    while(root!=NULL)
    {
        printf("%d ",root->data);
        root=root->next;
    }
    printf("\n");
}
int peek(node *root)
{
    return (root->data);
}
int isempty(node *root)
{
    if(root==NULL)
        return 1;
    return 0;
}

void stock(int hist[],int n)
{
    node *st=NULL;
    int a[n];
    a[0]=1;
    push(&st,0);
    int i;
    for(i=1;i<n;i++)
    {
        while(!isempty(st)&&hist[peek(st)]<=hist[i])
            pop(&st);
        a[i]=isempty(st)?(i+1):(i-peek(st));
        push(&st,i);
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main()
{
    int n,i,num;
    scanf("%d",&n);
    int hist[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&hist[i]);
    }
   stock(hist,n);
}
