#include<iostream>
using namespace std;
#include<stdio.h>
struct Node{
    int item;
    Node * next;
    //Node * prev;

};
class Circular_Linked_List
{
    private:
        Node *start;

    public:
        Circular_Linked_List();
        Circular_Linked_List(Circular_Linked_List&);
        ~Circular_Linked_List();
        Circular_Linked_List(int);
        Circular_Linked_List(int,int);
        
        void Insert_first(int=0);
        void Insert_last(int =0);
        // void insert_after(int index);
        void edit(int,int=0);
        bool is_exist(int);
        bool is_empty();
        void Deletefirst();
        void Deletelast();
        void Deleteby_value(int value);
        void DeleteNode(Node *);
        int Size();
        void clear();
        Node * find(int);// find node with specific value
        void print(int =1);// will also print in rev;
        bool operator ==(Circular_Linked_List&);
};
Circular_Linked_List::Circular_Linked_List()
{
    start=NULL;
}
Circular_Linked_List::Circular_Linked_List(Circular_Linked_List&C)
{
   C.start=NULL;
   Node *p=start;
   while(1)
   {
    if(p->next==start)
        break;
    else if(C.start==NULL)
    {
        C.start=new Node;
        C.start->item=p->item;
        C.start->next=C.start;
    }
    else
    {   
        Node*k=new Node;
        k->item=p->item;
        Node *w=C.start;
        while(w->next!=start)
            w=w->next;
        w->next=k;
        k->next=C.start;
    }
    
    

    p=p->next;
   }
    
}
Circular_Linked_List::Circular_Linked_List(int val)
{
    start =new Node;
    //start->prev=NULL;
    start->item=val;
    start->next=start;

}
Circular_Linked_List::Circular_Linked_List(int val1,int val2){
    start=new Node;
    start->item=val1;
    Node*p=new Node;
    start->next=p;
    p->item=val2;
    p->next=start;
    
    
}
Circular_Linked_List::~Circular_Linked_List()
{
    clear();
    delete start;
    
}
void Circular_Linked_List::Insert_first(int val)
{
    if(start==NULL)
    {
        start=new Node;
        start->item=val;
        start->next=start;

    }
    else{
        Node *t=start;
        Node *p=new Node;
        p->item=val;
        p->next=start;
        while(t->next!=start)
            t=t->next;
        t->next=p;
        start=p;
        
        //start=p;

    }
}
void Circular_Linked_List::Insert_last(int val)
{
    if(start==NULL)
    {
        start=new Node;
        start->next=start;
        start->item=val;

    }
    else{
        Node *t=start;
        while(t->next!=start)
            t=t->next;
    
        Node *p=new Node;
        t->next=p;
        p->next=start;
        p->item=val;
    }
}

void Circular_Linked_List::edit(int value,int chng)
{
    Node *t=start;
    try{
        if(start==NULL)
            throw 1;
        while(1)
        {
            if(t->item==value)
            {
                t->item=chng;
                break;
            }
            else if(t->next==start){
                cout<<"Value Not Found !!"<<endl;
                break;
            }
            else{
                t=t->next;
            }
        }
    }
        
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }
    
}
bool Circular_Linked_List::is_exist(int value)
{
    try{
        if(start==NULL)
            throw 1;
        Node *t=start;
        while(1)
        {
            if(t->item==value)
                return 1;
            else if(t->next==start)
            {
                break;
            }
            else{
                t=t->next;
            }
        }
        return 0;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }
}
bool Circular_Linked_List::is_empty()
{
    if(start==NULL)
        return 1;
    return 0;
}
void Circular_Linked_List::Deletefirst() {
    if (start == NULL) return; // If list is empty

    Node* t = start;

    if (start->next == start) { // If there's only one node
        delete start;
        start = NULL;
        return;
    }

    // Move start to the next node
    start = start->next;

    // Find the last node to update its next pointer
    Node* p = start;
    while (p->next != t) {
        p = p->next;
    }
    p->next = start; // Update the last node to point to the new start

    delete t; // Delete the old start node
}
void Circular_Linked_List::Deletelast()
{
    //if only one Node;
    // if start=NULL;
    try{
        if(start==NULL)
            throw 1;
        else if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else{
            Node *t=start;
            while(t->next->next!=start)
                t=t->next;
            delete t->next;
            t->next=start;
            
        }
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }
}
void Circular_Linked_List::Deleteby_value(int value)
{
    try{
        if(start==NULL)
            throw 1;
        
        Node *t=start;
        while(1)
        {
            
            if(t->next->item==value)
            {
                
                break;
            }
            else if(t->next==start)
            {
                cout<<"Value Not Found !!"<<endl;
                break;
            }
            t=t->next;

            
        }


    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
        else if(e==2)
            cout<<"Value Not Found !!"<<endl;
    }

    
}
void Circular_Linked_List::DeleteNode(Node *N)
{
    Node*t=start;
    //Node *k=start;
    while(t->next->next!=N)
        t=t->next;
    
    t->next=N->next;
    delete N;
    
    
}
void Circular_Linked_List::clear()
{
    Node *t=start;
    int count=Size();
    while(count>0)
    {
        Deletefirst();
        count--;
    
        
    }
    start=NULL;

}
int Circular_Linked_List::Size()
{
    try{
        if(start==NULL)
            throw 1;
        int count=1;
        Node *t=start;
        while(t->next!=start)
        {
            
            count++;
            t=t->next;

        }
        return count;


    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }
}
Node* Circular_Linked_List::find(int val)
{
    try{
        Node *t=start;
        if(start ==NULL)
            throw 1;
        while(1)
        {
          if(t->item==val)
            return t;
          else if(t->next==start)
          {
            cout<<"Value Not Found !! "<<endl;
            break;
          }
         
          else{
            t=t->next;
          }  
        }
        
        
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }

}
void Circular_Linked_List::print(int choice)
{
    Node*t=start;
    if(choice==1)
    {
        try{
            if(start==NULL)
                throw 1;
            else if(t->next==start)
                cout<<t->item<<" "<<endl;
            else{
                while(t->next!=start){
                    cout<<t->item<<" ";
                    t=t->next;
                }
                cout<<t->item<<endl;
            }
        }
        catch(int e)
        {
            if(e==1)
                cout<<"List Not Found !!"<<endl;
        }
    }
    else{
        try{
            if(start ==NULL)
                throw 1;
            // trying recursion to reverse print lets see!!
            
        }
        catch(int e)
        {
            if(e==1)
                cout<<"List Not Found !!"<<endl;
        }
    }
}
bool Circular_Linked_List::operator==(Circular_Linked_List& C)
{
    // checks equality two.
    Node *t=start;
    Node *p=C.start;
    
    while(t->item==p->item)
    {
        t=t->next;
        p=p->next;
        if(t->next==start&&t->item==p->item)
        {
            
            return 1;
        }
        else if(p->next==start&&t->item==p->item)
            return 1;
        else if(t->next==start||p->next==start&&t->item!=p->item)
            return 0;
    }
    return 0;


}
int main()
{
   Circular_Linked_List c1(11,12),c2;
   c1.Insert_first(13);
   c1.Insert_first(22);
   c1.Insert_last(23);
   c1.edit(22);
   c1.print();
   c1.Deletefirst();
   c1.Deletelast();
   c1.print();
   c2.Insert_first(13);
   c2.Insert_last(11);
   c2.Insert_last(9);
   c2.clear();
   //Circular_Linked_List c3=c1;
   //c3.print();
   //c2.Insert_first(15);
   //c2.print();
   //printf("%d",c1==c2);

   //Node *p;
   //p=c1.find(23);
   //cout<<p->item;

   //cout<<c1.Size()<<endl;
   //cout<<c1.is_exist(5);
   return 0;
}