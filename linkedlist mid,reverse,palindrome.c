

#include<stdio.h>
#include<assert.h>
int a[100],k=0;
typedef struct node{
  int data;
  struct node* next;
}node;
node* createnode(int d)
{
  node *n=(node*)malloc(sizeof(node));
  n->data=d;
  n->next=NULL;
  return n;
}
node* add(node *m,int d)
{
  if(m==NULL)
  {
      m=createnode(d);
      return m;
  }
    m->next=add(m->next,d);
    return m;
  /*{
    /*node *cur=*h;
    while(cur->next)
    {
       cur=cur->next;
    }
    cur->next=n;
    */



}
void display(node *h)
{
    while(h)
    {
        printf("%d ",h->data);
        h=h->next;
    }
}
node *mid(node *h)
{
    node *fast=h;
    node *slow=h;
    while(fast->next&&fast->next->next)
    {
        fast=(fast->next)->next;
        slow=slow->next;
    }
    printf("\n%d",slow->data);
    return slow;
}
node *reverse(node *h)
{
    if(h==NULL)
        return h;
    else
    {
        reverse(h->next);
        a[k++]=h->data;
    }
}
int palindrome(node **n,node *h)
{
    if(h==NULL)
        return 1;
    else
    {
        int y=palindrome(n,h->next);
        if(y==1)
        {
            if((*n)->data==h->data)
            {
                *n=(*n)->next;
                return 1;
            }
        }
            else
                return 0;
    }
}
int main(){
  node *head=NULL;
  int n,data;
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
  {  scanf("%d",&data);
     node* n=createnode(data);
     head=add(head,data);
  }
  display(head);
 //node *m=mid(head);
  //findloop(head);
 /* node *list=reverse(m);
  display(list);
  int ch=palindrome(&head,head);
  if(ch==1)
    printf("palindrome");
  else
    printf("not palindrome");
  //display(list);
  */
}

