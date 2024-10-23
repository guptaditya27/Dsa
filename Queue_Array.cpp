#include<iostream>
using namespace std;
#include<stdio.h>
class Queue{
   private:
      int capacity;
      int front;
      int  rear;// front , rear are index values 
      int * ptr;
   public:
      Queue();
      Queue(int,int);
      ~Queue();
      Queue(Queue &);
      Queue& operator =(Queue &);
      void Insert(int);
      void create_Queue(int);
      void Rear();
      void Front();
      void print();
      bool is_full();
      bool is_empty();
      void pop();
      int count();

      

      


};
Queue& Queue::operator=(Queue& Q)
{
   if(ptr!=NULL||Q.ptr==NULL)
   {
      delete []ptr;
      ptr=NULL;
      capacity=0;
      front=0;
      rear=-1;
   }
   else{
      capacity=Q.capacity;
      ptr=new int [capacity];
      front=0;
      rear=-1;
      int i=Q.front;
      while(rear<(Q.rear-Q.front))
      {
         rear++;
         ptr[rear]=Q.ptr[i];
         i++;
      }
   }
   return *this;
}
Queue::Queue(Queue &Q)// copy constructor.
{
   capacity=Q.capacity;
   front=0;
   int i=Q.front;
   rear=-1;

   if(Q.ptr==NULL)
      ptr=NULL;
   else{
      ptr=new int[capacity];
      while(rear<(Q.rear-Q.front))
      {
         rear++;
         ptr[rear]=Q.ptr[i];
         i++;
      }
   }
      
   
   
   
}
int Queue::count()
{
   if(ptr==NULL)
      cout<<"Queue Doesn't Exist !!"<<endl;
   return (rear-front)+1;
}
void Queue::pop()
{
   if(ptr==NULL)
   {
      cout<<"Queue Doesn't Exist !!"<<endl;
      return;
   }
   else if(rear==front)
   {
      delete []ptr;
      ptr=NULL;
      front=0;
      rear=-1;
      capacity=0;
   }
   else{
      cout<<ptr[front]<<endl;
      front++;

   }
}
Queue::~Queue()
{
   if(ptr!=NULL)  
      delete []ptr;
   ptr=NULL;

}
bool Queue::is_empty()
{
   if(ptr==NULL)
      cout<<"Queue Doesn't Exist !! "<<endl;
   else{
      return rear<capacity-1;
   }
}
bool Queue::is_full()
{
   if(ptr==NULL)
      cout<<"Queue Doesn't Exist !!"<<endl;
   else{
      return rear>=capacity-1;
   }
}
void Queue::Rear()
{
   if(ptr==NULL)
      cout<<"Queue Doesn't Exist !!"<<endl;
   else{
      cout<<"Rear:- "<<*(ptr+rear)<<endl;
   }
}
void Queue::Front()
{
   if(ptr==NULL)
      cout<<"Queue Doesn't Exist !!"<<endl;
   else{
      cout<<"Front:- "<<*(ptr+front)<<endl;
   }
}
void Queue::print()
{
   if(ptr==NULL)
      cout<<"Queue Doesn't Exist !!"<<endl;
   else{
      int i=front;
      while(i<=rear)
      {
         cout<<ptr[i]<<" ";
         i++;
      }
      cout<<endl;
   }
}
void Queue::Insert(int data)
{
   if(ptr==NULL)
      cout<<"Queue Doesn't Exist !!"<<endl;
   else if(rear>=capacity-1)
      cout<<"Queue overflow !!"<<endl;
   else{
      rear++;
      ptr[rear]=data;

   }
}
void Queue::create_Queue(int capacity)
{
   if(ptr==NULL)
   {
      this->capacity=capacity;
      ptr=new int[capacity];
      front=0;
      rear=-1;
   }
   else{// if create_queue called multiple times then memory leak hogi of ptr;
      // so ilaaj yeh hai ki agr multiple time call ho to purane dma variable ki memory releasr krke nyaa bna dege .
      delete []ptr;// release memory of o;d dma array/ queue.
      this->capacity=capacity;
      front=0;
      rear=-1;
      ptr=new int[capacity];

      
   }
   

}
Queue::Queue(int capacity,int val)
{
  this->capacity=capacity;
  ptr =new int[capacity];
  front=0;
  rear=0;
  ptr[rear]=val;
}
Queue::Queue()
{
   capacity=0;
   ptr=NULL;
   front=0;
   rear=-1;

}
int main()
{
   Queue Q(7,11);
   //Q.create_Queue(2);// creates new queue.
   Q.Insert(10);
   Q.Insert(5);
   Q.Insert(1);
   Q.Insert(8);
   Q.Insert(13);
   Q.Insert(21);
   //cout<<Q.count();
   Q.pop();

   //Q.pop();
   Queue w;
   w=Q;
   w.print();
   //cout<<Q.count();

   Q.Front();
   Q.Rear();
   //cout<<Q.is_full();
   //Q.Insert(40);
   //Q.Insert(30);
   Q.print();
   return 0;
}