#include<iostream>
using namespace std;
#include<stdio.h>
struct Node
{
    int item;
    Node * next;

};
class CLL
{
    private:
        Node * last;
    
    public:
        CLL();
        CLL(int);
        ~CLL();
        CLL(CLL &);
        void insertfirst(int=0);
        void insertlast(int =0);
        Node * search(int);
        void insert_after(Node *,int =0);
        void insert_at(Node *,int =0);
        void insert(int[],int);
        void edit(Node *,int);
        void edit(int,int);
        void print();
        void Deletefirst();
        void Deletelast();
        void Delete_node(Node *);
        bool is_exist(int);
        bool is_exist(Node *);
        void clear();
        CLL & operator=(CLL &);
        


};
CLL & CLL::operator =(CLL &C)
{
    while(last!=NULL)
        Deletefirst();
    Node *t=C.last->next;
    while(t)
    {
        Node *n=new Node;
        n->item=t->item;
        if(last==NULL)
        {
            last=n;
            n->next=n;
        }
        else if(last!=NULL)
        {
            n->next=last->next;
            last->next=n;
            last=n;
        }
        if(t->next==C.last->next)
            break;
        else{
            t=t->next;
        }
    }
}
CLL::CLL(CLL & C)
{
    last=NULL;
    if(C.last==NULL)
        last=NULL;
    else{
        Node *t=C.last->next;
        while(t)
        {
            Node *n=new Node;
            n->item=t->item;
            if(last==NULL)
            {
                last=n;
                n->next=n;
            }
            else if(last!=NULL)
            {
                n->next=last->next;
                last->next=n;
                last=n;
            }
            if(t->next==C.last->next)
                break;
            else{
                t=t->next;
            }
        }
        
    }

}
CLL::~CLL()
{
    while(last)
    {
        Deletelast();
    }
}
void CLL::Delete_node(Node *n)
{
    if(is_exist(n))
    {
        if(n==last)
            Deletelast();
        else if(n->next==last->next)
            Deletefirst();
        else{
            Node *t=last->next;// 1st node;
            while(t->next!=n)
                t=t->next;
            
            t->next=n->next;
            delete n;
            
        }
        
        
        


    }
}
void CLL::insert(int a[],int size)
{
    
    int i;
    for(i=0;i<size;i++)
    {
        insertlast(a[i]);
        
        
        /*Node*p=new Node;
        p->item=a[i];
        p->next=last->next;
        last->next=p;
        last=p;*/
        
    }
}
void CLL::edit(Node *n,int val)
{
    if(is_exist(n))
    {
        Node*t=n;
        t->item=val;
    }
    else if(!is_exist(n))
    {
        cout<<"Node Not Found !!"<<endl;
    }
}
void CLL::edit(int val1,int val2)
{
    Node *t=search(val1);
    if(t!=NULL)
    {
        t->item=val2;
    }
}
void CLL::insert_at(Node *n,int val)
{
    if(is_exist(n))
    {
        if(n==last->next)
            insertfirst(val);
        else if(n==last)
            insertlast(val);
        else{
            Node *p=new Node;
            p->item=val;
            p->next=n;
            Node * t=last->next;
            while(t->next!=n)
                t=t->next;
            t->next=p;
        }
        
    }
    else{
        cout<<"NOt Valid Node !!"<<endl;
    }
}
void CLL::insert_after(Node*n,int val)
{
    // condn to be taken care ...
    /*
        1. if last NULL hoga tb.
        2. agr n points the last element of list.
        3. if n points the first element of list.
    */  
    try{
        if(last==NULL)
            throw 1;
        Node * k=new Node;
        k->item=val;
        Node *t=last->next;//1st element.
        if(n->next==last->next)//n pointing last elemnt
            insertlast(val);
        else if(n==last->next)// 1st block of list
        {
            k->next=t->next;
            t->next=k;
            
        }
        else{
            // travrsing of list should be done for all other cases.
            while(t)
            {
                if(t==n)
                    break;
                t=t->next;
            }
            // at desired node.
            k->next=t->next;
            t->next=k;

        }

        
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }
    
}
Node * CLL::search(int val)
{
    try{
        if(last==NULL)
            throw 1;
        Node * t=last->next;// 1st Node.
        while(t)
        {
            if(t->item==val)
                return t;
            else if(t->next==last->next)
                break;
            else{
                t=t->next;
            }
            
        }
        cout<<"Value Not Found !! "<<endl;
        return NULL;

    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }

}
void CLL::insertlast(int val)
{
    try{
        if(last==NULL)
            throw 1;
        //Node *t=last->next;// ist element
        Node *n= new Node;
        n->item =val;
        n->next=last->next;
        last->next=n;
        last=n;


        
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }
}
void CLL::print()
{
    
    try{
        if(last==NULL)
            throw 1;
        Node *t=last->next;
        while(1)
        {
            cout<<t->item<<" ";
            if(t->next==last->next)
                break;
            
            else{
                t=t->next;
            }
        }
        cout<<endl;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !! "<<endl;
    }
}
void CLL::insertfirst(int val)
{
    
    Node * n=new Node;
    n->item=val;
    
    if(last==NULL)
    {
     last =n;
     n->next =n;
    }
    else{
        Node * t=last->next;// denotes 1st node ;
        last->next=n;
        n->next=t;
    }
    
}
bool CLL::is_exist(int val)
{
    if(last==NULL)
        cout<<"List NOt Found !!"<<endl;
    else{
        Node *t=last;
        while(t)
        {
            if(t->item==val)
                return 1;
            else if(t->next==last->next)
                break;
            else{
                t=t->next;
            }
        }
        return 0;
    }
}
CLL::CLL()
{
    last =NULL;
}
CLL::CLL(int val)
{
    last=new Node;
    last->item=val;
    last->next=last;

}
bool CLL::is_exist(Node *n)
{
    if(last==NULL)
        cout<<"List Not Found !!"<<endl;
    else{
        Node *t=last->next;// 1st node of list.
        while(t!=n)
            {
                if(t->next==last->next)
                    return 0;
                else{
                    t=t->next;
                }
            }
            return 1;

    }
}
void CLL::Deletefirst()
{
    if(last==NULL)
        cout<<"List Not Found !!"<<endl;
    else{
        Node *t= last->next;
        if(t->next==last)
        {
            delete t;
            last=NULL;
        }
        else{
            last->next=t->next;
            delete t;
        }

    }
}
void CLL::Deletelast()
{
    if(last==NULL)
        cout<<"List Not Found !!"<<endl;
    else{
        Node *t=last->next;
        if(t->next==last)
        {
            delete last;
            last =NULL;
        }
        else{
            while(t->next!=last)
                t=t->next;
            t->next=last->next;
            delete last;
            last=t;
        }
    }

}
int main()
{
   CLL c1(5);
   int a[]={10,20,30,40,50};
    c1.insertfirst(12);
   c1.insertfirst();
   c1.insertlast(20);
   c1.insert(a,5);
   //c1.print();
//    CLL c2;
//    c2=c1;
//    c2.print();
    //Node * k=c1.search(0);
    //c1.insert_at(k,45);
    //c1.Delete_node(k);
    //c1.edit(k,50);
    // cout<<c1.is_exist(k)<<endl;
//    c1.insert_after(k,15);
//    c1.insert_after(k,11);
//    Node *w=c1.search(10);
//    c1.insert_after(w,22);
   //cout<<k->item<<endl;
   //cout<<c1.is_exist(5)<<endl;
   //c1.Deletelast();
   //c1.print();
   //c1.edit(20,15);
   //c1.print();
   return 0;
}