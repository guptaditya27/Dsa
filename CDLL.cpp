#include<iostream>
using namespace std;
struct Node{
    int item;
    Node * prev;
    Node * next;

};
class CDLL
{
    private:
        Node * start;
    public:
        CDLL();
        CDLL(int);
        CDLL(CDLL &);
        ~CDLL();
        void Insertfirst(int val);
        void Insertlast(int val);
        void Deletefirst();
        void Deletelast();
        Node * search(int);
        void print();//
        void insert_at(Node *,int);
        void insert_after(Node *,int);
        CDLL& reverse(CDLL&);
        void Deletenode(Node *);
        void edit(int,int);
        void edit(Node *,int);
        void clear();
        bool is_exist(Node *);
        bool is_exist(int);
        void sort(int);
        CDLL& operator=(CDLL &);

        


};
CDLL& CDLL::reverse(CDLL & c) {
    clear(); // Ensure current list is empty

    if (c.start == NULL) return *this; // Check if the input list is empty

    Node* t = c.start->prev; // Last node of the input list

    do {
        Insertlast(t->item);
        t = t->prev;
    } while (t != c.start->prev);

    return *this;
}

void CDLL::sort(int order = 1) {
    if (start ==NULL)
        return;

    bool swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do
    {
        swapped = false;
        ptr1 = start;

        while (ptr1->next != lptr && ptr1->next != start)
        {
            if ((order == 1 && ptr1->item > ptr1->next->item) ||
                (order == 0 && ptr1->item < ptr1->next->item))
            {
                swap(ptr1->item, ptr1->next->item);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
        } while (swapped);
}
CDLL::~CDLL()
{
    Node*t=start;
    while(start)
    {
        Deletefirst();
    }
}
CDLL& CDLL::operator=(CDLL &c)
{
    while(start!=NULL)
        Deletefirst();
    
    
    Node *t=c.start->prev;//last node.
    while(t)
    {
        Insertfirst(t->item);
        if(t==c.start)
            break;
        else{
            t=t->prev;
        }
    }
        

    
    
    return *this;
}
CDLL::CDLL(CDLL &c)
{
    //cout<<"im inside"<<endl;
    Node *t=c.start->prev;// last element.
    start =NULL;
    if(c.start==NULL)
        start=NULL;
    while(t)
    {
        Insertfirst(t->item);
        if(t==c.start)
            break;
        else{
            
            t=t->prev;

        }
    }
}
void CDLL::clear()
{
    Node *t=start;
    while(start)
    {
        Deletefirst();
    }

}
void CDLL::edit(Node *n,int val)
{
    if(is_exist(n))
    {
        n->item=val;
    }
    else{
        cout<<"Node Not Found !!"<<endl;
    }
}
void CDLL::edit(int val1,int val2)
{
    Node *t=search(val1);
    if(t==NULL)
        cout<<"Value Not Found !! "<<endl;
    else{
        t->item=val2;
    }
}
void CDLL::Deletenode(Node *n)
{
    if(start==NULL)
    {
        cout<<"List is Empty !!"<<endl;
    }
    else if(n==start&&n->next==start&&n->prev==start)
    {
        start=n->next;
        start->prev=n->prev;
        n->prev->next=start;
        delete n;
        start=NULL;
    }
    else if(n==start)// deleting 1st node 
    {
        start=n->next;
        start->prev=n->prev;
        n->prev->next=start;
        delete n;
    }
    
    else if(is_exist(n))
    {
        Node *t=n->prev;
        t->next=n->next;
        n->next->prev=t;
        delete n;

    }
    else{
        cout<<"Node Not Found !! "<<endl;
    }
}
void CDLL::insert_after(Node *n,int val)
{
    Node *t=new Node;
    t->item=val;
    if(is_exist(n))
    {
        t->next=n->next;
        t->prev=n;
        n->next->prev=t;
        n->next=t;


    }
}
bool CDLL::is_exist(Node * n)
{
    if(n==NULL)
        cout<<"Node Doesn't Exist "<<endl;
    else if(start==NULL)
        cout<<"List Does't Exist"<<endl;
    else{
        Node *t=start;
        while(t)
        {
            if(t->next==n)
                return 1;
            else if(t->next==start)
                break;
            else{
                t=t->next;
            }
        }
        return 0;
    }

}
bool CDLL::is_exist(int val)
{
    if(start==NULL)
        cout<<"List Doesn't Exist"<<endl;
    else{
        Node *t=start;
        while(t)
        {
            if(t->item==val)
                return t;
            else if(t->next==start)
                break;
            else{
                t=t->next;
            }
        } 
        return 0;
    }

}
void CDLL::insert_at(Node * n,int val)
{
    if(start==NULL)
        cout<<"List Doesn't Exist"<<endl;
    else if(!is_exist(n))
        cout<<"Node Not Found !! "<<endl;
    else if(n==start)
    {
        Insertfirst(val);

    }
    else{
        Node *t=n->prev;
        Node * p=new Node;
        p->item =val;
        p->prev=t;
        p->next=n;
        t->next=p;
        n->prev=p;
        


    }
}
Node * CDLL::search(int val)
{
    Node *t=start;
    while(t)
    {
        if(t->item==val)
            return t;
        else{
            t=t->next;
        }
    }
    return NULL;
}
void CDLL::print()
{
    
    if(start==NULL)
        cout<<"List Is Empty !!"<<endl;
    else{    
        Node *t=start;
        while(t)
        {
            cout<<t->item<<" ";
            if(t->next==start)
                break;
            else{
                t=t->next;
            }
        }
        cout<<endl;
    }
}
void CDLL::Deletefirst()
{
    try{
        if(start==NULL)
            throw 1;
        else if(start->next==start&&start->prev==start)// only one node exist.
        {
            delete start;
            start=NULL;
        }
        else{
            Node *t=start->next;// 2nd node
            t->prev=start->prev;// 2nd node starts pointing last node
            start->prev->next=t;// last node starts poiinting 2nd node
            delete start;
            start =t;// start started pointing 2nd node
            // 2nd node becomes first node.



        }
    }
    catch(int e)
    {
        if(e==1)
            cout<<"LIst Not Found !!"<<endl;
    }
}
void CDLL::Deletelast()
{
    try{
        if(start==NULL)
            throw 1;
        else if(start->next==start&&start->prev==start)
        {
            delete start;
            start=NULL;
        }
        else{
            Node *t=start->prev->prev;//2nd last node 
            t->next=start;// 2nd last node start pointing to start
            delete start->prev;
            start->prev=t;// 1st node prev starts to point 2nd last node ie. last node. 


        }
    }
    catch(int e)
    {
        if(e==1)
            cout<<"LIst Not Found !!"<<endl;
    }
}
void CDLL::Insertlast(int val)
{
    Node *t=new Node;
    t->item = val;
    if(start==NULL)
    {
        start=t;
        t->next=start;
        t->prev=start;
    }
    else{
        t->next=start;//last node link with 1st node.
        t->prev=start->prev;//last node connect with second last node
        start->prev->next=t;//adding add of current last node to the next of prev last node;
        start->prev=t; //updating start node prev link to new lastnode

    }
    
}
CDLL::CDLL():start(NULL)
{}
CDLL::CDLL(int val)
{
    start=new Node;
    start->item=val;
    start->next=start;
    start->prev=start;

}
void CDLL::Insertfirst(int val)
{
    Node *t=new Node;
    t->item=val;

    if(start==NULL)
    {
      start=t;
      t->next=start;
      t->prev=start;  
    }
    else{
        t->next=start;
        t->prev=start->prev;
        start->prev->next=t;
        start->prev=t;
        start=t;

    }
}

int main()
{
   CDLL c(5);
   Node * d;
   c.Insertfirst(4);
   c.Insertfirst(2);
   c.Insertfirst(3);
   
   c.Insertfirst(1);
   c.Insertlast(6);
   CDLL p;
   p.reverse(c);
   p.sort(0);
   p.print();

//    d=c.search(5);
//    c.print();
//    c.Deletefirst();
//    c.print();
//    c.Deletelast();
//    c.insert_after(d,15);
//    Node*p=c.search(2);
//    CDLL q(10);
//    Node *w=q.search(10);
//    q.edit(w,200);
//    //q.Deletenode(w);
//    q.print();
//    q.clear();
//    q.print();
//    c.clear();
//    c.print();
//    //cout<<c.is_exist(0);
   return 0;
}