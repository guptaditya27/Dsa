#include<iostream>
using namespace std;
#include<stdio.h>
struct Node{
    int item;
    Node * next;
    Node *prev;
    

};
class Circular_Linked_List
{
    private:
        Node *start;
        Node *last;


    public:
        Circular_Linked_List();
        Circular_Linked_List(Circular_Linked_List&);
        ~Circular_Linked_List();
        Circular_Linked_List(int);
        Circular_Linked_List(int,int);
        
        void Insert_first(int=0);
        void Insert_last(int =0);
        void insert_after(int index);
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
    last=NULL;
}
Circular_Linked_List::Circular_Linked_List(int val)
{
    start=new Node;
    start->item=val;
    start->next=start;
    last =start;
}
Circular_Linked_List::Circular_Linked_List(int val1,int val 2)
{
    start=new Node;
    start->item=val1;
    Node *p=new Node;
    start->next=p;
    p->item=val2;
    p->next=start;
    last=p;

}
void print(int num)
{
    try{
        if(start ==NULL)
            throw 1;
        else if(num==1)
        {
            
        }
        else{

        }
    }
    catch(int e)
    {
        if(e==1)
            cout<<"List Not Found !!"<<endl;
    }
}
int main()
{
    return 0;
}