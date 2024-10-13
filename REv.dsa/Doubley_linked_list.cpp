#include<iostream>
using namespace std;
#include<stdio.h>
#include<cmath>
struct Node
{
    int item;
    Node* prev;
    Node* next;

};
class Doubley_Linked_list
{
    private:
        Node * start;

    public:
        Doubley_Linked_list();//
        Doubley_Linked_list(int);//
        Doubley_Linked_list(int,int);//
        void Insert_first(int);//
        void Insert_last(int);//
        bool is_empty();//
        Node * find(int);//
        void clear();//
        bool is_exist(int);//
        void indexof(int);//
        int size();//
        void print();//
        void print(int);// can be done using default arg also (But mera mann nhi tha!!!).
        void deletefirst();//
        void deletelast();//
        void delete_at_position(int=0);//
        void delete_Node(Node *);//
        ~Doubley_Linked_list();//
        Doubley_Linked_list(Doubley_Linked_list &);//

};
Doubley_Linked_list::~Doubley_Linked_list()
{
    clear();
    
}
Doubley_Linked_list::Doubley_Linked_list(Doubley_Linked_list&L)
{
    start=NULL;
    Node *t=L.start;
    while(t)
    {
        Insert_last(t->item);
        t=t->next;
    }  
    
}
void Doubley_Linked_list::clear()
{
    try{
        if(start==NULL)
            throw 1;
        Node *t=start;
        while((t->next)->next!=NULL)
            t=t->next;
        while(t->prev!=NULL)
        {
            delete t->next;
            t->next=NULL;

            t=t->prev;
        }
        delete t;
        start=NULL;
        
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }
}
void Doubley_Linked_list::delete_at_position(int pos)
{
    try{
        if(pos>size())
            throw 1;
        else if(start==NULL)
            throw 2;
        else if(pos<=0)
            throw 3;
        else if(pos ==1)
            deletefirst();
        else if(pos==size())
            deletelast();
        else{
            Node *t=start;
            int index=1;
            while(t->next!=NULL)
            {
                if(index==pos)
                    break;
                index++;
                t=t->next;
            }
            (t->prev)->next=t->next;
            (t->next)->prev=t->prev;
            delete t;
        }
        


    }
    catch(int e)
    {
        if(e==1)
            cout<<"Position Out Of Range !!"<<endl;
        else if(e==2)
            cout<<"List Not Found !!"<<endl;
        else if(e==3)
            cout<<"Negative or Zero Index Not Allowed !! "<<endl;
    }

}
void Doubley_Linked_list::deletelast()
{
    try{
        if(start==NULL)
            throw 1;
        Node*t=start;
        while(t->next->next!=NULL)
            t=t->next;
        delete t->next;
        t->next=NULL;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }

    
}
void Doubley_Linked_list::deletefirst()
{
    //Node *t=start;// start will be always having add of 1st node only so also be
    try{
        if(start ==NULL)
            throw 1;
        Node *p=start;
        while(p->prev!=start)
            p=p->next;
        start=p;
        delete p->prev;
        p->prev=NULL;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }


}
void Doubley_Linked_list::Insert_last(int value)
{
    Node *p=new Node;
    if(start==NULL)
    {
        start=p;
        p->next=NULL;
        p->prev=NULL;
        p->item=value;
    }
    else{
        Node *t=start;
    
        while(t->next!=NULL)
            t=t->next;
        t->next=p;
        p->prev=t;
        p->next=NULL;
        p->item=value;
    }
    
    
    
}
int Doubley_Linked_list::size()
{
    Node *t=start;
    if(start == NULL)
        return 0;
    int count=1;
    while(t->next!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
}
void Doubley_Linked_list::indexof(int value)
{
    try{
        if(start==NULL)
            throw 1;
        else if(!is_exist(value))
            throw 2;
        
        
        
        int index=1;
        Node *t=start;
        while(t)
        {
            if(t->item==value)
                cout<<index<<endl;
            index++;
            t=t->next;

        }


    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
        else if(e==2)
            cout<<"Element Not Found !!"<<endl;
    }

    
    

}
Node* Doubley_Linked_list::find(int value)
{
    try{
        if(start ==NULL)
            throw 1;
        Node *t=start;
        while(t)
        {
            if(t->item==value)
                return t;
            t=t->next;
        }
        throw 2;

    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
        if(e==2)
            cout<<"Element Not Found !!"<<endl;
    }
}
void Doubley_Linked_list::print(int a)
{
    Node*t=start;
    try{
        if(start==NULL)
            throw 1;
        
        while(t->next!=NULL)
        {
            t=t->next;
        }
        
        
        
        while(t)
        {
            cout<<t->item<<" ";
            t=t->prev;
        }
        cout<<endl;
        }
        catch(int e)
        {
            if(e==1)
                cout<<"List Doesn't Exist !!"<<endl;
        }
}
bool Doubley_Linked_list::is_exist(int value)
{
    
    
    
    Node* t=start;
    while(t)
    {
        if(t->item==value)
        {
            return 1;
            
        }
        t=t->next;
    }
    
    return 0;
    
    
}
bool Doubley_Linked_list::is_empty()
{
    if(start==NULL)
        return 1;
    return 0;

}
void Doubley_Linked_list::print()
{
    try{
        if(start==NULL)
            throw 1;
        Node *t=start;
        while(t)
        {
            cout<<t->item<<" ";
            t=t->next;
        }
        cout<<endl;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }
    

}
Doubley_Linked_list::Doubley_Linked_list(int data)
{
    
    
    start=new Node;
    
    start->item=data;
    start->next=NULL;
    start->prev=NULL;
    
}
Doubley_Linked_list::Doubley_Linked_list(int data1,int data2)
{
    
    Node *t=new Node;

    start=new Node;
    start->prev=NULL;
    start->next=t;
    t->prev=start;
    t->next=NULL;
    start->item=data1;
    t->item=data2;
    
}
void Doubley_Linked_list::Insert_first(int data)
{
    
    Node *t=new Node;
    t->item=data;
    if(start==NULL)
    {
        start=t;
        t->prev=NULL;
        t->next=NULL;
    }
    else{
        t->next=start;
        t->prev=NULL;
        start->prev=t;
        start=t;
    }
    
    

    
    
    
}
Doubley_Linked_list::Doubley_Linked_list():start(NULL){}


int main()
{
    Doubley_Linked_list d(4);
   d.Insert_first(15);
   d.Insert_first(11);
   d.Insert_first(12);
   d.Insert_first(21);
   cout<<d.size()<<endl;
   d.print();
   d.Insert_last(56);
   d.print();
   /*d.deletefirst();
   d.print();
   //d.delete_at_position(5);
   //d.delete_at_position(4);

   //d.deletelast();
   d.print();
   d.clear();
   d.Insert_first(10);
   d.Insert_last(15);
   d.print();
   //Node *p=d.find(54);
   //d.indexof(53);
   cout<<d.is_exist(21)<<endl;
   Doubley_Linked_list d1=d;
    d1.print();
    //d.print();
    //cout<<d1.is_exist(10);
   //d2.print();*/
   
   return 0;
}