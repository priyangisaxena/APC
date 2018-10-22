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
int largestrect(int hist[],int n)
{
    node *st=NULL;
    int i=0,max=0,area=0;
    while(i<n)
    {
        if((isempty(st)==1)||hist[i]>=hist[peek(st)])
        {
            push(&st,i);
            i++;
        }
        else
        {
            int t=peek(st);
            pop(&st);
            area=hist[t]*(isempty(st)?i:i-peek(st)-1);
            if(area>max)
                max=area;
        }
    }
    while(isempty(st)==0)
    {
           int t=peek(st);
            pop(&st);
            area=hist[t]*(isempty(st)?i:i-peek(st)-1);
            if(area>max)
                max=area;
    }
    return max;
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
    printf("%d\n",largestrect(hist,n));
}
