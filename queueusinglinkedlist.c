#include<stdio.h>
typedef struct node{
 int data;
 struct node* next;
}node;
typedef struct queue{
 node *rear,*front;
}que;
node* createnode(int x)
{
 node *n=(node*)malloc(sizeof(node));
 n->data=x;
 n->next=NULL;
 return n;
}
que *createQueue()
{
    que *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}
void push(que *q,int x)
{
 node *n=createnode(x);
 if(q->rear==NULL)
 {
     q->front=q->rear=n;
 }
 else
 {
     q->rear->next=n;
     q->rear=n;
 }
}
node* pop(que *t)
{
 if(t->front==NULL)
    printf("empty"); return;

     node* n=t->front;
     t->front=t->front->next;
     if(t->front==NULL)
     {
         t->rear=NULL;
     }

 return n;
}
void display(que *t)
{
 node *cur=t->front;
 while(cur!=t->rear->next)
 {
  printf("%d ",pop(t)->data);
  cur=cur->next;
 }
}
int main()
{
 que *s=createQueue();

  push(s,2);
  push(s,4);
  push(s,8);
  push(s,10);
 // pop(s);
  display(s);
}
