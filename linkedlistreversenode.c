

#include<stdio.h>
#include<assert.h>
typedef struct node{
  int data;
  struct node* next;
}node;
node* createnode()
{
  node *n=(node*)malloc(sizeof(node));
  return n;
}
void add(node **h,int d)
{
  node *n=createnode();
  n->data=d;
  n->next=NULL;
  if(*h==NULL)
    *h=n;
  else
  {
    node *cur=*h;
    while(cur->next)
    {
       cur=cur->next;
    }
    cur->next=n;
  }
}
void display(node *h)
{
    while(h)
    {
        printf("%d ",h->data);
        h=h->next;
    }
}
void mid(node *h)
{
    node *fast=h;
    node *slow=h;
    while(fast->next&&fast->next->next)
    {
        fast=(fast->next)->next;
        slow=slow->next;
    }
    printf("\n%d",slow->data);
}
node *reverse(node *h)
{
    node* cur=h;
    node* prev=NULL;
    node* t;
    while(cur)
    {
        t=cur->next;
        cur->next=prev;
        prev=cur;
        cur=t;
    }
    return prev;
}

int main(){
  node *head=NULL;
  int n,data;
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
  {  scanf("%d",&data);
     add(&head,data);
  }
  //display(head);
 // mid(head);
  //findloop(head);
  node *list=reverse(head);
  display(list);
  //display(list);
}

