// in dequeue insertion and deletion from both the ends.
#include<iostream>
using namespace std;
#include<stdio.h>
struct Node{
    int item;
    Node * next;
    Node * prev;
};
class Dequeue
{
    private:
        Node * front;
        Node *rear;
    public:
        Dequeue();
        Dequeue(int);
        ~Dequeue();
        Dequeue(Dequeue&);
        Dequeue& operator=(Dequeue&);
        void print(int =1);
        void Insert_front(int=0);
        void Insert_rear(int=0);
        void Delete_front();
        void Delete_rear();
        void get_front();
        void get_rear();
        bool is_empty();



        

};
Dequeue& Dequeue::operator=(Dequeue& D)
{
    while(front!=NULL)
        Delete_front();
    Node *t=D.rear;
    while(t)
    {
        Insert_front(t->item);
        if(t->prev==NULL)
            break;
        t=t->prev;
    }
    
    
    return *this;
}
Dequeue::Dequeue(Dequeue&D)
{
    if(D.front==NULL&&D.rear==NULL)
    {
        front=NULL;
        rear=NULL;
    }
    else{
        front=NULL;
        rear=NULL;
        Node*t=D.rear;
        while(t)
        {
            Insert_front(t->item);
            if(t->prev==NULL)
                break;
            t=t->prev;
            
        }

    }
}
bool Dequeue::is_empty()
{
    return front==NULL&&rear==NULL;
}
Dequeue::~Dequeue()
{
    while(front&&rear)
    {
        Node *t=front;
        if(front==rear)
        {
            delete front;
            front=NULL;
            rear=NULL;

        }
        else{
            front=t->next;
            front->prev=NULL;
            delete t;
            t=t->next;

        }
    }
}
void Dequeue::Delete_rear()
{
    if(front==NULL&&rear==NULL)
        cout<<"Queue Doesn't Exist !!"<<endl;
    else if(front==rear)
    {
        delete front;
        front=NULL;
        rear=NULL;
    }
    else{
        Node*t=rear->prev;
        delete rear;
        rear=t;
        rear->next=NULL;
    }
}
void Dequeue::Delete_front()
{
    // two condn to hanfle 1. if NULL 2. if single Node ho to
    if(front==NULL&& rear==NULL)
        cout<<"Queue Doesn't Exist !!"<<endl;
    else if(front==rear)// single element
    {
        delete front;
        front=NULL;
        rear=NULL;
    }
    else{
        Node *t=front->next;
        t->prev=NULL;
        delete front;
        front=t;

    }
}
void Dequeue::get_front()
{
   if(rear==NULL)
        cout<<"Queue Doesn't Exist !!"<<endl;
    else{
        cout<<front->item<<endl;
    }
}
void Dequeue::get_rear()
{
    if(rear==NULL)
       cout<<"Queue Doesn't Exist !!"<<endl;
    else{
        cout<<rear->item<<endl;
    }
    
}
void Dequeue::Insert_rear(int val)
{
    if(rear==NULL)
    {
        front=new Node;
        front->item=val;
        front->next=NULL;
        front->prev=NULL;
        rear=front;
    }
    else{
        Node *n=new Node;
        n->item=val;
        n->next=NULL;
        n->prev=rear;
        rear->next=n;
        rear=n;

    }
}
void Dequeue::Insert_front(int val)
{
    if(front==NULL)
    {
        front=new Node;
        front->item=val;
        front->next=NULL;
        front->prev=NULL;
        rear=front;

    }
    else{
        
        Node*n=new Node;
        n->item=val;
        n->next=front;
        front->prev=n;
        n->prev=NULL;
        front=n;
    }
}
Dequeue::Dequeue()
{
    front=NULL;
    rear=NULL;
}
Dequeue::Dequeue(int val)
{
    front=new Node;
    rear=front;
    front->item=val;
    front->next=NULL;
    front->prev=NULL;
    // denotes only single element in list.

}
void Dequeue::print(int i)
{
    if(front==NULL&&rear==NULL)
        cout<<"Queue Doesn't Exist !!"<<endl;
    else if(i==1)
    {
        Node *t=front;
        while(t)
        {
            cout<<t->item<<" ";
            if(t->next==NULL)
                break;
            else{
                t=t->next;
            }
        }
        cout<<endl;

    }
    else{
        Node * t=rear;
        while(t)
        {
            cout<<t->item<<" ";
            if(t->prev==NULL)
                break;
            else{
                t=t->prev;
            }
        }
        
    }   
}

int main()
{
   Dequeue D;
   //cout<<D.get_front()<<" "<<D.get_rear()<<endl;
    D.Insert_front(11);
    D.Insert_rear(9);
    Dequeue p;
    p=D;
    p.print();


    //cout<<D.is_empty();
    //D.Delete_front();
    //D.Delete_rear();

   D.print();
   return 0;
}