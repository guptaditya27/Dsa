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
        void Insertfirst(int val);
        void Insertlast(int val);
        void Deletefirst();
        void Deletelast();
        Node * search(int);
        void print();
        


};
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
   c.Insertfirst(3);
   c.Insertfirst(2);
   c.Insertfirst(1);
   c.Insertlast(6);
   d=c.search(5);
   c.print();
   c.Deletefirst();
   c.print();
   c.Deletelast();
   c.print();
   return 0;
}