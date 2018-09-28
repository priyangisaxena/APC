#include<stdio.h>
typedef struct binarytree{
 int data;
 struct binarytree *left,*right;
}node;
node* createnode(int d)
{
 node* n=(node*)malloc(sizeof(node));
 n->data=d;
 n->left=n->right=NULL;
 return n;
}
typedef struct queue{
 node* *a;
 int head,tail;
}queue;
queue* initialize(int n)
{
    queue *q=(queue*)malloc(sizeof(queue));
    q->a=(node**)malloc(sizeof(node*)*n);
    q->head=q->tail=-1;
        int i;
    for (i = 0; i < n; ++i)
        q->a[i] = NULL;
    return q;
}
void push(queue *q,node* num)
{
 q->a[++q->tail]=num;
 if(q->head==-1)
        ++(q->head);

}
void pop(queue *q)
{
    ++q->head;
    if(q->head==q->tail)
        q->head=q->tail=-1;
}
int hasBothChild(node* t)
{
    return (t&&t->left&&t->right);
}
void insert(node **root,int num,int n,queue *q)
{

    node* temp=createnode(num);
    if(!*root)
    {
        *root=temp;
         push(q,temp);
    }
    else
    {          //printf("hello*");
       node* t=q->a[q->head];
       //  printf("%d ",t->data);
       if(!t->left)
      {
          t->left=temp;
           push(q,temp);
      }
       else if(!t->right)
       {
           t->right=temp;
            push(q,temp);
       }
       if(hasBothChild(t))
        pop(q);

    }

}
void preorder(node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
node* construct_tree_inorder_preorder(int *in,int *pre,int s,int e,int *index)
{
 if(s>e)
        return NULL;
 node* nn=(node*)malloc(sizeof(node));
 nn->data=pre[*index];
 int i;
 for(i=s;i<=e;i++)
    if(pre[*index]==in[i])
    break;
(*index)++;
nn->left=construct_tree_inorder_preorder(in,pre,s,i-1,index);
nn->right=construct_tree_inorder_preorder(in,pre,i+1,e,index);
return nn;
}

node* construct_tree_inorder_postorder(int *in,int *post,int s,int e,int *index)
{
 if(s>e)
        return NULL;
 node* nn=(node*)malloc(sizeof(node));
 nn->data=post[*index];
  (*index)--;
 int i;
 for(i=s;i<=e;i++)
    if(nn->data==in[i])
    break;

nn->right=construct_tree_inorder_postorder(in,post,i+1,e,index);
nn->left=construct_tree_inorder_postorder(in,post,s,i-1,index);
return nn;
}

void mirror(node *root)
{
    if(root==NULL)
        return;
    else{
    mirror(root->left);
    mirror(root->right);
    node* t=root->left;
    root->left=root->right;
    root->right=t;
    }
}


int main()
{

 int n;
 scanf("%d",&n);

 int in[n],pre[n],post[n];
 int i,num;
 int index=n-1;
 for(i=0;i<n;i++)
 {
     scanf("%d",&in[i]);
 }
 for(i=0;i<n;i++)
    scanf("%d",&pre[i]);
node *root=construct_tree_inorder_postorder(in,pre,0,n-1,&index);

 inorder(root);

}
