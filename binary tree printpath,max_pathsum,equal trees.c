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

int equal(node* a,node* b)
{
    if(a&&b){
    if(a->data!=b->data)
        return 0;
    return (equal(a->left,b->left)&&equal(a->right,b->right));
    }
    if(a==NULL&&b==NULL)
        return 1;
    else
        return 0;
}

void printpath(node* root,int *a,int len)
{
    if(root==NULL)
        return ;
    a[len]=root->data;
    len++;
    if(root->left==NULL&&root->right==NULL)
    {
        int i;
        for(i=0;i<len;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    else
    {
        printpath(root->left,a,len);
        printpath(root->right,a,len);
    }
}

int printpath_maxsum(node* root,int *a,int len,int *max)
{
    if(root==NULL)
        return ;
    a[len]=root->data;
    len++;
    if(root->left==NULL&&root->right==NULL)
    {
        int i,sum=0;
        for(i=0;i<len;i++)
        {
            sum+=a[i];
          printf("%d ",a[i]);
        }
        if(sum>*max)
            *max=sum;
        printf("\n");
    }
    else
    {
        printpath_maxsum(root->left,a,len,max);
        printpath_maxsum(root->right,a,len,max);
    }

    return *max;
}
int main()
{
 node* root=NULL;


 int n;
 scanf("%d",&n);
 queue *q=initialize(n);
 int i,num;
 for(i=0;i<n;i++)
 {
     scanf("%d",&num);
     insert(&root,num,n,q);
 }
 //inorder(root);
 preorder(root);

 node *root1 = createnode(1);
  node *root2 = createnode(1);
    root1->left = createnode(2);
    root1->right = createnode(3);
    root1->left->left  = createnode(4);
    root1->left->right = createnode(5);
    root1->left->left->right=createnode(6);

    root2->left = createnode(2);
    root2->right = createnode(3);
    root2->left->left = createnode(5);
    root2->left->right = createnode(4);

  //  printf("hello");
 printf("\n%d\n",equal(root1,root2));
 int ar[100],len=0;
 printpath(root1,ar,len);
 int m=0;
 printf("\n%d\n",printpath_maxsum(root1,ar,len,&m));

}
