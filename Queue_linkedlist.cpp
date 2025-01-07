#include<iostream>
using namespace std;
struct Node{
    int item;
    Node *next;
};
class Queue
{
    private:
        Node * front;
        Node * rear;
    public:
        Queue();
        Queue(int);
        Queue(Queue&);
        Queue& operator=(Queue &);
        void Enqueue(int);
        void Dequeue();
        ~Queue();
        void print();
        Node * Front();
        Node * Rear();
        int get_front();
        int get_rear();
        int size();
        void clear();
        void reverse();

};
void Queue::reverse()
{
    // pta nhi kaise hoga.
    
    
}
Queue& Queue::operator =(Queue & Q)
{
    if(Q.front==NULL&&Q.rear==NULL)
    {
        front=NULL,rear=NULL;
    }
    else{
        
        if(front!=NULL&&rear!=NULL)
        {
           Node *t=front;
           while(t)
           {
            if(front==rear)
            {
                delete front;
                front=NULL;
                rear=NULL;
                break;
            }
            else{
                front=front->next;
                delete t;
            }
           } 
        }
        Node *w=Q.front;
        while(w)
        {
            Enqueue(w->item);
            if(w==rear)
                break;
            else{
                w=w->next;
            }
        }
    }
    return *this;
}
Queue::Queue(Queue &Q)
{
    if(Q.front==NULL&&Q.rear==NULL)
    {
        front=NULL;
        rear=NULL;
    }
    else{
        Node *t=Q.front;
        front=NULL;
        rear=NULL;
        while(t)
        {
            Enqueue(t->item);
            if(t==rear)
                break;
            else{
                t=t->next;
            }
        }
    }
}
void Queue::clear()
{
    
    if(front==NULL&&rear==NULL)
        cout<<endl;
    
    while(front!=NULL&&rear!=NULL)
    {
        Node *t=front;
        if(front==rear)// only single element left
        {
            delete t;
            front=NULL;
            rear=NULL;
            break;
        }
        else{
            front=front->next;
            delete t;
        }
    }
    cout<<endl;
    
}
int Queue::size()
{
    Node *t=front;
    int count=0;
    while(t)
    {
        count++;
        if(t->next==NULL||t==rear)
            break;
        else{
            t=t->next;
        }
    }
    return count;
}
Node * Queue::Front()
{
    return front;
}
Node * Queue::Rear()
{
    return rear;
}
int Queue::get_rear()
{
    if(rear==NULL)
        cout<<"\n";
    else{
        return rear->item;
    }
}
int Queue::get_front()
{
    if(front==NULL)
    {
        cout<<"/n";
    }
    return front->item;
}
Queue::~Queue()
{
    while(front!=rear)
    {
        Node *t=front;
        front=t->next;
        delete t;
    }// prob next is dangling at ending of loop if only 1 node remains.
    // but as of i am deleting front front so last mein to null hai already
    // so No dangling pointer will be left ..
    delete front;
    rear=NULL;

}
void Queue::Dequeue()
{
    
    if(front==NULL&&rear==NULL)
        cout<<"Queue Not Found !! "<<endl;
    else if(front==rear)// only single node.
    {
        cout<<front->item<<endl;
        delete front;
        front=NULL;
        rear=NULL;
    }
    else{
        cout<<front->item<<endl;
        Node *t=front;
        front=front->next;
        delete t;
    }
}
void Queue::Enqueue(int val)
{
    // adds element at last;
    Node *t= new Node;
    t->item=val;
    if(front==NULL&&rear==NULL)
    {
        front=t;
        rear=t;
        t->next=NULL;
    }
    else{
        
        rear->next=t;
        t->next=NULL;
        rear=t;

    }
}
void Queue::print()
{
    if(front==NULL&& rear==NULL)
        cout<<"Empty Queue !!"<<endl;
    else{
        Node *t=front;
        while(t)
        {
            cout<<t->item<<" ";
            if(t==rear)
                break;
            t=t->next;
        }
        cout<<endl;
    }

}
Queue::Queue()
{
    front=NULL;
    rear=NULL;
}
Queue::Queue(int val)
{
    front=new Node;
    front->item=val;
    front->next=NULL;
    rear=front;

}
int main()
{
   Queue a(10);
   a.Enqueue(15);
   a.Enqueue(20);
   //a.Dequeue();
   //a.print();
   //cout<<a.size()<<endl;
   //cout<<a.get_front()<<endl;
   //cout<<a.get_rear()<<endl;
   //a.clear();
   //a.print();
    Queue p;
    //p.print();
    p=a;
    //p.reverse();
    p.print();
//    Node *t=p.Front();
//    cout<<t->item;
   return 0;
}