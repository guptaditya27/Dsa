#include<iostream>
using namespace std;
class stack
{
    private:
        int top;
        int* ptr;
        int capacity;
        
    public:
        stack();
        ~stack();
        stack(stack &);
        void create_stack(int=1);
        stack(int,int);
        void print();
        void push(int);
        int peek();
        void pop();
        bool is_full();
        bool is_empty();
        void clear();
        stack & operator =(stack &);
        void reverse();
        int size();// return no of elements.




};
int stack::size()
{
    
    return top+1;
}
void stack::reverse()
{
    int i=0,j=top;
    while(i=top&&j>=0)
    {
        int w=ptr[i];
        ptr[i]=ptr[j];
        ptr[j]=w;
        i+=2,j-=2;
    }

}
stack & stack::operator =(stack&S)
{
    if(ptr!=NULL)
        clear();
    else if(S.ptr ==NULL)
    {
        ptr=NULL;
        capacity=S.capacity;
        top=S.top;
    }
    else{
        top=S.top;
        capacity=S.capacity;
        ptr=new int[capacity];
        int i=0;
        while(i<=S.top)
        {
            ptr[i]=S.ptr[i];
            i++;
        }
    }
    return *this;

}
void stack::clear()
{
    if(ptr!=NULL)
    {
        delete []ptr;
        ptr=NULL;
        capacity=0;
        top=-1;
    }

}
stack::stack(stack &S)
{
    
    if(S.ptr==NULL)
    {
        ptr=NULL;
        capacity=0;
        top=-1;
    }
    else{
        top=S.top;
        capacity=S.capacity;
        ptr=new int[capacity];
        int i=0;
        while(i<=S.top)
        {
            ptr[i]=S.ptr[i];
            i++;
        }
    }
}
bool stack::is_full()
{
    return top==capacity-1;
}
bool stack::is_empty()
{
    if(top<capacity-1)
        return 1;
    return 0;
}
stack::~stack()
{
    if(ptr!=NULL)
    {
        delete []ptr;
        delete ptr;
    }
    else{
        delete ptr;
    }
}
void stack::pop()
{
    if(ptr==NULL)
        cout<<"Stack Not Found !!"<<endl;
    else{
        cout<<ptr[top]<<endl;
        //delete ptr+top;
        top--;

    }
}
int stack::peek()
{
    if(ptr==NULL)
        cout<<"stack Not Found !!"<<endl;
    else{
        return ptr[top];
    }
}
void stack::push(int val)
{
    if(ptr==NULL)
        cout<<"Stack Not Found !!"<<endl;
    else{
        if(top==capacity-1)
            cout<<"stack overflow"<<endl;
        else{
            top++;
            ptr[top]=val;
        }
    }

}
void stack::print()
{
    int i=0;
    while(i<=top)
    {    
        cout<<ptr[i]<<" ";
        i++;
    }
    cout<<endl;
}
stack::stack(int cap,int val)
{
    capacity=cap;
    top=0;
    ptr=new int [capacity];
    ptr[top]=val;


}
void stack::create_stack(int cap)
{
    // if create array called multiple time?
    /*
        memory leak ho jyegi kyuki pointer nhi bachega previously created stack ko point
        krne ke liye.
    */
    if(ptr==NULL)
    {
        capacity=cap;
        top=-1;
        ptr=new int [capacity];
        
    }
    else if(ptr!=NULL)
        cout<<"Stack is created already !!"<<endl;
}
stack::stack()
{
    capacity=0;
    top=-1;
    ptr=NULL;

}
int main()
{
   stack s(10,15);
   s.push(12);
   s.push(20);
   s.push(13);
   s.push(22);
   cout<<s.peek()<<endl;
   s.pop();
   s.print();
   cout<<s.is_empty()<<endl;
   cout<<s.is_full()<<endl;
   stack p;
   p=s;
   p.reverse();
   //p.clear();
   p.print();
   
   return 0;
}