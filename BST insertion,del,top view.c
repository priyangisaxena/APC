#include<stdio.h>
#include<stdlib.h>
typedef struct node{
 int data;
 int val;
 struct node *left,*right;
}node;
node *createnode(int d)
{
 node* n=(node*)malloc(sizeof(node));
 n->val=0;
 n->data=d;
 n->left=n->right=NULL;
 return n;
}
node *insert(node *root,int d,int val)
{
 if(root==NULL)
 {
  node *nn=createnode(d);
  return nn;
 }
 if(root->data<d)
 root->right=insert(root->right,d,val);
 else if(root->data>d)
 root->left=insert(root->left,d,val);

 return root;
}
int findmax(node *root)
{
    while(root->right)
    {
        root=root->right;
    }
    return root->data;
}
node *del(node *root,int d)
{
    if(root->data==d)
    {
        if(root->left==NULL)
            return root->right;
        else if(root->right==NULL)
            return root->left;
        else
        {
            int x=findmax(root->left);
            root->data=x;
            root->left=del(root->left,x);
            return root;
        }
    }
    if(root->data>d)
        root->left=del(root->left,d);
    else if(root->data<d)
        root->right=del(root->right,d);
    return root;
}
int k=0,a[50];
void inorder(node *root)
{
 if(root==NULL)
 return;
 inorder(root->left);
 printf("%d ",root->data);
 a[k++]=root->data;
 inorder(root->right);

}
typedef struct queue{
 node* *a;
 int head,tail;
}queue;
queue* initialize(int n)
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->a=(node*)malloc(sizeof(node)*n);
    q->head=q->tail=-1;
    int i;
    for(i=0;i<n;i++)
        q->a[i]=NULL;
    return q;
}
void push(queue *q,node* d)
{
    q->tail++;
    q->a[q->tail]=d;
    if(q->head==-1)
        q->head=0;
}
void pop(queue *q)
{
    q->head++;
}
int height(node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int l=height(root->left);
        int r=height(root->right);
        if(l>r)
            return l+1;
        return r+1;
    }
}
void topview(node *root,int n)
{
    queue *q=initialize(n);
    int h=height(root);
    int a[2*h],i;
    for(i=0;i<2*h;i++)
        a[i]=-1;
    push(q,root);
    while(1)
    {
        int s=q->tail-q->head+1;
        if(s==0)
            break;
        while(s>0)
        {
            node *t=q->a[q->head];
            int d=t->val;
            printf("%d*",d);
            pop(q);
            if(t->left)
            {
                push(q,t->left);
                t->left->val=d-1;
            }
            if(t->right)
            {
                push(q,t->right);
                t->right->val=d+1;
            }
            if(a[d+h]==-1)
                a[d+h]=t->data;
            --s;
        }
    }
    for(i=0;i<2*h;i++)
        if(a[i]!=-1)
        printf("%d ",a[i]);
}
int main()
{
int i,n,num;
 scanf("%d",&n);
 //int a[n],k=0;
 node *root=NULL;
 for(i=0;i<n;i++)
 {
  scanf("%d",&num);
  root=insert(root,num,0);
 }
 inorder(root);
 //root=del(root,4);
 printf("\n");
 //inorder(root);
 /*int flag=0;
 for(i=0;i<k-1;i++)
 {
     if(a[i]>a[i+1])
     {
         printf("not a valid tree");
         flag=1;
         break;
     }
     printf("%d ",a[i]);
 }
 if(flag==0)
    printf("valid tree");
*/
topview(root,n);
}
