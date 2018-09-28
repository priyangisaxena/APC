#include<stdio.h>
#include<stdlib.h>
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
    /*if(q->head==q->tail)
        q->head=q->tail=-1;*/
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

void levelorder(node* root,int n)
{
    if(root==NULL)
        return ;
    queue *q=initialize(n);
    push(q,root);
    int size=0;
    while(1)
    {
        size=(q->tail)-(q->head)+1;
       // printf("*********%d ****",size);
        if(size == 0) {
            //printf("df ");
            break;
        }
        while(size>0)
        {
            int i;
            printf("%d ",(q->a[q->head])->data);
            //for(i=q->head;i<=q->tail;i++)
              //  printf("%d ",(q->a[i])->data);
            node *t=q->a[q->head];
            pop(q);
            if(t->left)
                push(q,t->left);
            if(t->right)
                push(q,t->right);
            size--;
        }
        printf("\n");
    }
}
void leftview(node *root,int n)
{
    queue *q=initialize(n);
    push(q,root);
    int size=0;
    while(1)
    {
     size=(q->tail)-(q->head)+1;
       // printf("*********%d ****",size);
        if(size == 0) {
            //printf("df ");
            break;
        }
       printf("%d\n",(q->a[q->head])->data);

        while(size>0)
        {
            int i;
         //   printf("%d ",(q->a[q->head])->data);
            //for(i=q->head;i<=q->tail;i++)
              //  printf("%d ",(q->a[i])->data);
            node *t=q->a[q->head];
            pop(q);
            if(t->left)
                push(q,t->left);
            if(t->right)
                push(q,t->right);
            size--;
        }
        printf("\n");
    }
}
int height(node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int ld=height(root->left);
        int rd=height(root->right);
        if(ld>rd)
            return ld+1;
        else
            return rd+1;
    }
    return 0;
}
typedef struct queue1{
int *a;
int head,tail;
}queue1;
queue1* initializeq(int n)
{
    queue1 *q=(queue1*)malloc(sizeof(queue1));
    q->a=(int*)malloc(sizeof(int)*n);
    q->head=q->tail=-1;
    return q;
}
void pushq(queue1 *q,int d)
{
    q->tail++;
    q->a[q->tail]=d;
    if(q->head==-1)
        q->head=0;
}
void popq(queue1 *q)
{
    ++q->head;
}
void topview(node *root,int n)
{
 queue *q=initialize(n);
 queue1 *hd=initializeq(n);
 int d=0;
 int h=height(root);
 //printf("%d",h);
 int a[2*h];
 int i;
 for(i=0;i<2*h;i++)
    a[i]=-1;
 push(q,root);
 pushq(hd,0);
 while(1)
 {
     int size=q->tail-q->head+1;
     //printf("%d ",size);
     if(size==0)
        break;
     while(size>0)
     {
         node *t=q->a[q->head];
         int d=hd->a[hd->head];
         pop(q);
         popq(hd);
         if(t->left)
         {
             push(q,t->left);
             pushq(hd,d-1);
         }
         if(t->right)
         {
             push(q,t->right);
             pushq(hd,d+1);
         }
         if(a[d+h]==-1)
            a[d+h]=t->data;
        --size;
     }
 }
 for(i=0;i<2*h;i++)
 {
     if(a[i]!=-1)
        printf("%d ",a[i]);
 }
}
void bottomview(node *root,int n)
{
  queue *q=initialize(n);
 queue1 *hd=initializeq(n);
 int d=0;
 int h=height(root);
 //printf("%d",h);
 int a[2*h];
 int i;
 for(i=0;i<2*h;i++)
    a[i]=-1;
 push(q,root);
 pushq(hd,0);
 while(1)
 {
     int size=q->tail-q->head+1;
     //printf("%d ",size);
     if(size==0)
        break;
     while(size>0)
     {
         node *t=q->a[q->head];
         int d=hd->a[hd->head];
         pop(q);
         popq(hd);
         if(t->left)
         {
             push(q,t->left);
             pushq(hd,d-1);
         }
         if(t->right)
         {
             push(q,t->right);
             pushq(hd,d+1);
         }
            a[d+h]=t->data;
        --size;
     }
 }
 for(i=0;i<2*h;i++)
 {
     if(a[i]!=-1)
        printf("%d ",a[i]);
 }
}
void rightview(node *root,int n)
{

    queue *q=initialize(n);
    push(q,root);
    //printf("%d ",root->data);
    int size=0;
    node* t;
    while(1)
    {
     size=(q->tail)-(q->head)+1;
        if(size == 0) {
            break;
        }
        while(size>0)
        {
            int i;
            t=q->a[q->head];
            pop(q);
            if(t->left)
                push(q,t->left);
            if(t->right)
                push(q,t->right);
            size--;
        }
        printf("%d ",t->data);
        printf("\n");
    }
}
int max(int x,int y)
{
    return (x>y)?x:y;
}
int diameter(node *root)
{
    if(root==NULL)
        return 0;

    int lh=height(root->left);
    int rh=height(root->right);

    int dl=diameter(root->left);
    int dr=diameter(root->right);

    return max((lh+rh+1),max(dl,dr));
}
int main()
{
 node* root=NULL;


 int n;
 //scanf("%d",&n);
 queue *q=initialize(n);
 int i,num;
/* for(i=0;i<n;i++)
 {
     scanf("%d",&num);
     insert(&root,num,n,q);
 }
 */
  root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->left = createnode(6);
    root->right->right=createnode(7);
    root->left->left->left=createnode(8);
    root->left->left->right=createnode(9);
    root->left->right->left=createnode(10);
    root->left->right->left->left=createnode(12);
    root->right->right->right=createnode(11);
 //levelorder(root,n);
 //leftview(root,n);
 topview(root,11);
 printf("\n");
 bottomview(root,11);
 printf("\n");
 rightview(root,11);
 printf("\n%d \n",diameter(root));
}
