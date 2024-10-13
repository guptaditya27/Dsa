#include<iostream>
using namespace std;
#include<stdio.h>
#include<cmath>
struct Node
{
    //int * start;
    int item;
    Node * next;
};
class Linked_list{
    private:
        Node *start;
    public:
        Linked_list();
        void Insert_start(int=0);
        void Insert_last(int=0);
        void Insert_at(Node *,int);
        void print();
        void delete_first();
        void delete_last();
        void edit(int,int);
        void search(int);
        bool is_exist(int);
        void delete_value(int);
        int count();
        Linked_list(Linked_list &);

};
bool Linked_list::is_exist(int value)
{
    Node *t=start;
    //int w=count();
    while(t)
    {
        if(t->item==value)
            return 1;
        t=t->next;

    }
    return 0;

    
}
void Linked_list::search(int value)
{
    
    int node_no=0;
    try{
        if(start==NULL)
            throw 1;
        Node *t=start;
        
        while(t)
        {
            node_no++;
            if(t->item==value)
            {
                cout<<value<<" Indexed at Node :- "<<node_no<<endl;
                break;
            }
            t=t->next;
        
            
        }
        if(t==NULL)
            cout<<"Value Not Found !!"<<endl;
        
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Doesn't Exist !!"<<endl;
        
    }
}
void Linked_list::edit(int prev,int New)
{
    try{
        if(start ==NULL)
            throw 1;
        else if(!is_exist(prev))
            throw 2;
    
    
        Node *t=start;
        while(t)
        {
            if(t->item==prev)
            {    
                t->item=New;
                break;
            }
            
            t=t->next;
        }

    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Doesn't Exist !!"<<endl;
        else if(e==2)
            cout<<"Value Not Found !! "<<endl;
    }
    
}
void Linked_list::delete_value(int value)
{
    try{
        if(start==NULL)
            throw 1;
        else if(!is_exist(value))
        {
            throw 2;
        }
        
        
        Node *p=start;
        Node *t=start;
        while(t->item!=value)
        {
            t=t->next;
            
        }
        while(p->next->item!=value)
            p=p->next;
        p->next=t->next;
        delete t;
        
    }
    catch(int e)
    {
        if(e==2)
            cout<< "Value Not Found !!"<<endl;
        else if(e==1)
            cout<<"List Doesn't Exist !!"<<endl;
    }
    
}
Linked_list::Linked_list(Linked_list &L)
{
    /*
        1. node type pointer having address of already existing list .
        2. new list kew start me NULL
        3. 
    */
    try{
        if(L.start==NULL)
            throw 1;
        
        else{
            Node *prev=L.start;
            start =new Node;
            //start->item=L.start->item;
            //start->next=NULL;
            while(prev)
            {
                Node *t=new Node;
                if(start->next==NULL)
                    start=t;
                Node *p=start;
                
                while(p->next!=NULL)
                    p=p->next;
                t->item=prev->item;
                p->next=t;
                t->next=NULL;
                
                
                
                
                
                prev=prev->next;
            }

        }
        
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Empty Reference List !!! "<<endl;
    }
    

}
int Linked_list::count()
{
    Node*t;
    int count=1;
    t=start;
    while(t->next!=NULL)
    {
        t=t->next;
        count++;
    }
    return count;
}
void Linked_list::delete_first()
{
    try{
        if(start==NULL)
            throw 1;
        
        Node *n=start;
        start=start->next;
        delete n;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List doesn't Exist !!"<<endl;
    }
}
void Linked_list::delete_last()
{
    Node *t;
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
            while(t->next->next!=NULL)
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
void Linked_list::Insert_at(Node *t,int data)
{
    //1. prepare a node 1st.
    //2. agar node entered is last node
    //3. agar node entered is 1st node.
    //4. agar start == Null hai. created nhi hai list
    //5.
     
    
}
void Linked_list::print()
{
   Node *t;
   t=start;
   while(t)
   {
    
    cout<<t->item<<" ";
    t=t->next;
   }
    cout<<endl;
    
}
Linked_list::Linked_list()
{
    start=NULL;
}
void Linked_list::Insert_start(int data)
{
    Node *n =new Node;
    n->item=data;
    if(start==NULL)
    {
        start=n;
        n->next=NULL;
    }
    else{
        n->next=start;
        start=n;
    }

}
void Linked_list::Insert_last(int data)
{
    Node *n =new Node;
    n->item=data;
    if(start==NULL)
    {
        start=n;
        n->next=NULL;
    }
    else{
        Node *t;
        Node *n=new Node;
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
        n->item=data;
        n->next=NULL;
    }
}
int main()
{
   Linked_list l;
   l.Insert_last(41);// going to 1st node.
   l.Insert_start(10);// becoming 1st node.
   l.Insert_start(40);
   l.Insert_start(15);
   l.Insert_start(25);
   l.Insert_start(10);
   l.Insert_start(50);
   l.Insert_start(55);// 1st node ,last = 41
   l.Insert_last(15);// last= 15;
   //cout<<l.count()<<endl;
   //Linked_list p;

   //l.delete_value(44);
   l.delete_first();// deletes 55;
   l.delete_last();// will delete 15;
   l.edit(15,35);
   l.search(10);
   l.print();
   //Linked_list k=l;
   //k.print();
   //cout<<k.count()<<endl;


   

   return 0;
}