//Create and Reverse Link List
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    struct node* next;
}*head;

void display(struct node *head)
{
    struct node* t;
    t=head;
    while(t!=NULL)
    {
        cout<<t->info<<" ";
        t=t ->next;
    }
    cout<<"\n";
}
void rev()
{
    struct node *p1,*p2,*p3;

    p1=head;
    p2=p1->next;
    p3= p2->next;
    p1->next=NULL;
    p2->next=p1;

    while(p3!=NULL)
    {
        p1= p2;
        p2=p3;
        p3= p3->next;
        p2->next =p1;
    }
    head = p2;
}
int main()
{

   //create link list
   struct node *start;

   head=NULL;
   int n,inf;
   cout<<"enter no of nodes";
   cin>>n;
   cout<<"enter info of nodes";
   for (int i=0;i<n;i++)
   {
       cin>>inf;
       struct node *temp;
       temp = new(node);
       temp->info= inf;
       temp->next=NULL;

       if(head == NULL)
       {
           head = temp;
       }
       else
       {
           start=head;
         while(start->next!=NULL)
         {
             start= start->next;
         }
         start->next = temp;
       }
   }

   display(head);
   rev();
    display(head);

return(0);
}
