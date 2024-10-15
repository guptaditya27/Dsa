#include<iostream>
using namespace std;
#include<stdio.h>
struct Node
{
    int item;
    Node* prev;
    Node* next;
};
class DLL
{
    private:
        Node*start;
    public:
        DLL():start(NULL)
        {}
        void insertstart(int);
        void insertlast(int);
        Node * search(int);
        void insertafter(Node *,int=0);
        void deletefirst();
        void deletelast();
        void deletenode(Node *);
        DLL(DLL&);
        ~DLL();
        DLL & operator=(DLL&);


};
DLL & DLL::operator=(DLL &D)
{
    while(start)
        deletefirst();
    if(D.start!=NULL)
    {
        Node *t=D.start;
        while(t->next!=NULL)
            t=t->next;
        while(t)
        {
            insertstart(t->item);
            t=t->prev;
        }
    }
    else{
        start=NULL;
    }
    return *this;
}
DLL::DLL(DLL&D)
{
    if(start!=NULL){
        Node*t=D.start;
        while(t->next!=NULL)
            t=t->next;
        while(t)
        {
            insertstart(t->item);
            t=t->prev;
        }
    }
    else{
        start=NULL;
    }
}
DLL::~DLL()
{
    while(start)
        deletefirst();
}
void Dll::deletenode(Node*n)
{
    if(n==NULL)
    {
        cout<<"List NOt Found"<<endl;
    }
    else if(n==start)
        deletefirst();
    else if(n->next==NULL)
        deletelast();
    else{
        n->next->prev=n->prev;
        n->prev->next=n->next;
        delete n;
    }
}
void DLL::deletelast()
{
    Node *t=start;
    if(start==NULL)
        cout<<"Empty List"<<endl;
    else if(start->next==NULL)
    {
        delete t;
        start=NULL;
    }
    else{
        while(t->next!=NULL)
            t=t->next;
        t->prev->next=NULL;
        delete t;
    }

}
void DLL::deletefirst()
{
    Node *t=start;
    if(start!=NULL)
    {
        start->next->prev=NULL;
        start=start->next;
        delete t;

    }
    else{
        cout<<"List Empty !!"<<endl;
    }
}
void DLL::inserafter(Node*n,int val)
{
    Node *t=new Node;
    t->item=val;
    t->next=n->next;
    t->prev=n;
    n->next->prev=t;
    n->next=t;
}
Node * DLL::search(int val)
{
    Node *t=start;
    while(t)
    {
        if(t->item==val)
            return t;
        t=t->next;
    
    }
    return NULL;
}
void DLL::insertlast(int val)
{
    Node*n=new Node;
    n->item=val;
    n->next=NULL;
    if(start==NULL)
    {
        n->prev=NULL;
        start=n;
    }
    else{
        Node *t=start;
        while(t->next!=NULL)
            t=t->next;
        n->prev=t;
        t->next=n;
         
    }
    
}
void DLL::insertstart(int val)
{
    Node *n=new Node;
    n->item=val;
    n->prev=NULL;
    n->next=start;
    if(start!=NULL)
        start->prev=n;
    start=n;

}

int main()
{
   return 0;
}
