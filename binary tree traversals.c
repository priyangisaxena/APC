#include<stdio.h>
typedef struct binarytree{
 int data;
 struct binarytree *left,*right;
}node;

node* createnode(int d)
{
  node *n=(node*)malloc(sizeof(node));
  n->data=d;
  n->left=NULL;
  n->right=NULL;
  return n;
}

typedef struct queue{
 node* *a;
 int head,tail;
}queue;

queue* initialize(int n)
{
    queue *t=(queue*)malloc(sizeof(queue));
    t->a=(node*)malloc(sizeof(node)*n);
    t->head=-1;
    t->tail=-1;
    int i;
    for(i=0;i<n;i++)
        t->a[i]=NULL;
    return t;
}
void push(queue* q,node* d)
{
    q->tail++;
    q->a[q->tail]=d;
    if(q->head==-1)
        q->head=0;
}
void pop(queue* q)
{
    q->head++;

}
int hasBothChild(node* t)
{
    return (t&&t->left&&t->right);
}
typedef struct stack{
node* *a;
int top;

}st;

st* initialize_s(int n)
{
    st* s=(st*)malloc(sizeof(st));
    s->a=(node*)malloc(sizeof(node)*n);
    s->top=-1;
    int i;
    for(i=0;i<n;i++)
        s->a[i]=NULL;
    return s;
}
void push_s(st* s,node* d)
{
    s->top++;
    s->a[s->top]=d;
}
void pop_s(st *s)
{
    s->top--;
}
int isempty(st *s)
{
    if(s->top==-1)
        return 1;
    return 0;
}
void insert(node **root,int num,int n,queue* q)
{
    node* temp=createnode(num);
    if(*root==NULL)
      {
         *root=temp;
         push(q,temp);
      }
    else
    {
        node* t=q->a[q->head];
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

void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void levelorder(node *root,int n)
{
    node *t=root;
    queue *q=initialize(n);
    push(q,root);
    while(q->head!=-1)
    {
        while(q->head!=-1)
        printf("%d ",(q->a[q->head])->data);
        t=q->a[q->]
        if(t->left)
            push(q,t->left);
        if(t->right)
            push(q,t->right);
        t=q->a[q->head];
         pop(q);
    }
}

void inorder_nonrecur(node* root,int n)
{
    node* cur=root;
    st* s=initialize_s(n);
    int done=0;
    while(done==0)
    {
       // printf("%d ",cur->data);
        if(cur!=NULL)
        {
            push_s(s,cur);
           // printf("%d ",cur->data);
            cur=cur->left;
        }
        else
        {
            if(isempty(s)==0)
            {
                cur=s->a[s->top];
                pop_s(s);
                printf("%d ",cur->data);
                cur=cur->right;
            }
            else
                done=1;
        }
    }

}

void preorder_nonrecur(node *root,int n)
{

    st *s=initialize_s(n);
    push_s(s,root);
    while(isempty(s)==0)
    {
          node *cur=s->a[s->top];
     printf("%d ",cur->data);
     pop_s(s);
     if(cur->right)
            push_s(s,cur->right);
     if(cur->left)
        push_s(s,cur->left);
    }
}
void postorder_nonrecur2(node* root,int n)
{
    st* s1=initialize_s(n);
    st* s2=initialize_s(n);
    push_s(s1,root);
    while(isempty(s1)==0)
    {
        node* t=s1->a[s1->top];
        pop_s(s1);
        push_s(s2,t);
        if(t->left)
            push_s(s1,t->left);
        if(t->right)
            push_s(s1,t->right);
    }
    while(isempty(s2)==0)
    {
        printf("%d ",(s2->a[s2->top])->data);
        pop_s(s2);
    }
}
void postorder_nonrecur1(node *root,int n)
{
    st* s=initialize_s(n);
    do
    {
        while(root)
        {
            if(root->right)
                push_s(s,root->right);
            push_s(s,root);
            root=root->left;
        }
        root=s->a[s->top];
        pop_s(s);
        if(root->right&&s->a[s->top]==root->right)
        {
            pop_s(s);
            push_s(s,root);
            root=root->right;
        }
        else
        {
            printf("%d ",root->data);
            root=NULL;
        }
    }while(isempty(s)==0);
}
int height(node* root)
{
    if(root==NULL)
        return 0;
    else
    {
        int ld=height(root->left);
        int rd=height(root->right);
        if(ld>rd)
            return ld+1;
        return rd+1;
    }
}
int main()
{
int n,i,num;
 node *root=NULL;

 scanf("%d",&n);
  queue *q=initialize(n);

 for(i=0;i<n;i++)
 {
  scanf("%d",&num);
  insert(&root,num,n,q);
 }
 inorder(root);
 printf("\n");
 preorder(root);
  printf("\n");
postorder(root);
 printf("\n");
 levelorder(root,n);
 printf("\n");
 inorder_nonrecur(root,n);
 printf("\n");
 preorder_nonrecur(root,n);
 printf("\n");
 postorder_nonrecur2(root,n);
 printf("\n");
 postorder_nonrecur1(root,n);
  printf("\n");
 printf("%d\n",height(root));
}
