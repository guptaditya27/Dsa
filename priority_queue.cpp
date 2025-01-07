#include<iostream>
using namespace std;
#include<stdio.h>
struct Node{
   int item;
   Node* next;
   int Pno;

};
class priority_queue{
   private:
      Node* start;
   public:
      priority_queue();
      void insert(int,int);// nodes having highest priority comes first .
      void print();
      void del();
      int get_item();
      int get_highest_priority();


};
int priority_queue::get_highest_priority()
{
   if(start)
   {
      return start->Pno;
   }
   throw -1;
}
int priority_queue::get_item()
{
   if(start)
      return start->item;
   throw -1;
}
void priority_queue::del()
{
   if(start)
   {
      Node*t=start;
      start=start->next;
      delete t;

   }
}
void priority_queue::print()
{
   Node *t=start;
   while(t)
   {
      cout<<t->item<<" ";
      if(t->next==NULL)
         break;
      t=t->next;
   }
   cout<<endl;
}
priority_queue::priority_queue()
{
   start=NULL;
}
void priority_queue::insert(int data,int p)
{
   Node*n=new Node;
   n->item=data;
   n->Pno=p;
   Node *t=start;
   if(start==NULL||start->Pno<n->Pno)
   {
      n->next=start;
      start=n;
      
   }
   else{
      while(t->next->Pno>=n->Pno)
      {
         if(t->next==NULL)
            break;
         t=t->next;
      }
      n->next=t->next;
      t->next=n;
   }
}
int main()
{
   priority_queue p;
   p.insert(10,1);
   p.insert(29,9);
   p.insert(45,7);
   p.insert(25,11);
   p.insert(13,5);
   p.print();
   return 0;
}