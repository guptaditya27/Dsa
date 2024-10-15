#include<iostream>
using namespace std;
#include<stdio.h>
struct node
{
    int item;
    node *next;
};
class Linkedlist
{
    private:
        node* start;

    public:
        Linkedlist();
        ~Linkedlist();
        void insertat_start(int );
        void insertat_last(int);
        void insert_after(node*,int);
        node* search(int);
        void Deletefirst();
        void Deletelast();
        void Delete_particular(node *);
        //~Linkedlist();
        Linkedlist(Linkedlist &);
        Linkedlist& operator=(Linkedlist &);
        void print();
        
    

};
void Linkedlist::print()
{
    node *t;
    while(t->next)
    {
        cout<<t->item<<" ";
        t=t->next;
    }


}
Linkedlist& Linkedlist::operator=(Linkedlist& list)
{
    node*t;
    t=list.start;
    while(start)
        Deletefirst();

    while(t)
    {
        insertat_last(t->item);
        t=t->next;
    }
    return *this;
}
Linkedlist::Linkedlist(Linkedlist&L)
{
    node*t;
    t=L.start;
    start=NULL;

    while(t)
    {
        insertat_last(t->item);
        t=t->next;
    }

}
Linkedlist::~Linkedlist()
{
    while(start)
        Deletefirst();
}
Linkedlist::Linkedlist()
{
    start=NULL;
}
void Linkedlist::insertat_start(int data)
{
    node* n=new node;
    n->item=data;
    n->next=start;
    start=n;

   /* if(start==NULL)
    {
        there is no need to use it bcoz if list empty hogi
        jto start me NuLL hoga and wph NuLL new node ke next mein
        null dal dega means ek hi node bnega jiske next mein Null
        hoga so That will we our first and last Node.
    }
    else{


    }*/
}
void Linkedlist::insertat_last(int data)
{
    node *t;
    node*n;
    n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else{
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }
}
void Linkedlist::insert_after(node*t,int data)
{
    node*n;
    if(t)
    {
        n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
}
node* Linkedlist::search(int data)
{
    node*t;
    t=start;
    while(t)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return t; 
}
void Linkedlist::Deletefirst()
{
    node * r;
    if(start!=NULL)
    {
        r=start;
        start=r->next;
        delete r;
    }
}

void Linkedlist::Deletelast()
{
    node *t;
    try{
        if(start==NULL)
            throw 1;
        if(start->next==NULL)
        {
            delete start;
            start =NULL;
        }
        else{
            t=start;
            while(t->next->next==NULL)
                t=t->next;
            delete t->next;
            t->next=NULL;
        }
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Empty Linked LIst!!"<<endl;
    }
}
void Linkedlist::Delete_particular(node*t)
{
    node*r;
    try{
        if(start==NULL)
            throw 1;
        if(t==start)
            Deletefirst();
        else{
            r=start;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            delete t;
        }
    }
        
        catch(int e)
        {
            if(e==1)
                cout<<"Empty List!!"<<endl;

        }
    
}
int main()
{
   Linkedlist l;
   l.insertat_start(10);
   l.insertat_start(30);
   //l.insert_after(,20);
   l.print();
   return 0;
}