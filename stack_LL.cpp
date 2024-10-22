#include<iostream>
using namespace std;

struct Node
{
    int item;
    Node * next;
};
class stack
{
    private:
        Node * top;
    protected:
        void f1(Node *t)
    {
        if(t->next==NULL)
            cout<<t->item<<" ";
        else{
            cout<<t->item<<" ";
            f1(t->next);
            
            
        }
    }
    public:
        stack();
        ~stack();
        stack(int);
        stack(stack&);
        stack& operator =(stack &);
        void reverse();
        void Push(int);
        void peek();
        void pop();
        void print();

};
void stack::print()
{
    Node *t=top;
    if(top!=NULL)
    {
        while(t)
        {
            cout<<t->item<<" ";
            if(t->next==NULL)
            {
                
                break;
            }
            else{
                t=t->next;
            }
        }
        cout<<endl;
    }
}
stack& stack::operator =(stack& S)
{
    if(top!=NULL)
    {
        Node *t=top;
        while(t)
        {
            
            if(t->next==NULL)
            {
                delete t;
                top=NULL;
                break;
            }
            else{
                top=t->next;
                delete t;
                t=t->next;
                
            }
        }
    }
    else
    {
        if(S.top==NULL)
        top=NULL;
        else
        {
            //top=NULL;
            Node *t=S.top;
            while(t)
            {
                Node *w=new Node;
                w->item=t->item;
                if(top==NULL)
                {
                    top=w;
                    top->next=NULL;
                }
                else
                {
                w->next=top;
                top=w;
                }
                if(t->next==NULL)
                    break;
                else{
                    t=t->next;
                }
            }
        }
    }

}
void stack::reverse()
{
    // recurssion use kr;
    Node *t=top;
    
    f1(t);
    cout<<endl;
    

}
stack::stack(stack&S)
{
    if(S.top==NULL)
        top=NULL;
    else{
        //top=NULL;
        Node *t=S.top;
        while(t)
        {
            Node *w=new Node;
            w->item=t->item;
            if(top==NULL)
            {
                top=w;
                top->next=NULL;
            }
            else
            {
               w->next=top;
               top=w;
            }
            if(t->next==NULL)
                break;
            else{
                t=t->next;
            }
        }
        

    }
}
stack::~stack()
{
    while(top)
    {
        if(top->next==NULL)
        {
            delete top;
            break;
        }
        else{
            Node *t=top;
            top=t->next;
            delete t;
        }
    }
    //peek();
}
void stack::pop()
{
    
    if(top==NULL)
    {
        cout<<"Empty Stack !!"<<endl;
        return;
    }

    else if(top->next!=NULL)
    {
        cout<<top->item<<endl;
        Node *t=top;
        
        top=top->next;
        delete t;

    }
    else if(top->next==NULL)
    {
        delete top;
        top=NULL;
    }
    else{
        cout<<"Stack Not Found !!"<<endl;
    }
}
void stack::peek()
{
    
    if(top==NULL)
        cout<<"Empty Stack !!"<<endl;
    else{
        cout<<top->item<<endl;
    }

    
            
    
}
void stack::Push(int val)
{
    Node *t=new Node;// always insert as a 1st Node only.
    t->item=val;
    if(top==NULL)
        t->next=NULL;// if push hone wala node is being the 1st node of entire empty list.
    else{
        t->next=top;
    }
    top=t;
    
        
}
stack::stack()
{
    top=NULL;
}
stack::stack(int val)
{
    top=new Node;
    top->item=val;
    top->next=NULL;

}
int main()
{
   stack s(10);
   s.Push(20);
   s.Push(30);
   stack p;
   p=s;
   //p.print();
   //p.peek();
   //p.pop();
   //p.peek();
//    s.peek();
//    s.pop();
//    s.peek();
//     s.pop();
//    s.peek();
//     s.pop();
//     s.pop();
//    s.peek();

   return 0;
}