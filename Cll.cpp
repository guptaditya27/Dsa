#include<iostream>
using namespace std;
#include<stdio.h>
struct Node
{
    int item;
    Node * next;

};
class CLL
{
    private:
        Node * last;
    public:
        CLL();
        void insertfirst(int=0);
        void print();
};
void CLL::insertfirst(int val)
{
    
    Node * n=new Node;
    n->item=val;
    
    if(last==NULL)
    {
     last->next=n;
     

    }
    
}

CLL::CLL()
{
    last =NULL;
}
int main()
{
   CLL c1;
   c1.insertfirst(10);
   c1.insertfirst(20);
   c1.print();
   return 0;
}