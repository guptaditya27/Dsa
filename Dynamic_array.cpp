#include<iostream>
using namespace std;
#include<stdio.h>
class D_array{
    private:
        int lastindex;
        int *ptr;
        int capacity;
    public:
        D_array();
        D_array(int);// creates array of specified capacity.
        D_array(int,int);
        D_array(D_array&);
        ~D_array();
        void create_array(int);
        void append(int);
        void doublearray();
        void halfarray();
        void del(int);
        void clear();
        int get_capacity();
        bool is_empty();
        void Insert(int,int);
        int get_element(int);
        int count();
        void print();
        int find(int);
        D_array& operator =(D_array&);


};
// half only if lastindex == capacity/2
// double if full ho jyee to.
D_array& D_array::operator=(D_array& D)
{
    
    if(ptr!=NULL)
        delete []ptr;
    lastindex=D.lastindex;
    capacity=D.capacity;
    ptr=new int [capacity];
    int i=0;
    while(i<=lastindex)
    {
        ptr[i]=D.ptr[i];
        i++;
    }
    return *this;
}
int D_array::find(int element)
{
    int i=0;
    while(i<=lastindex)
    {
        if(ptr[i]==element)
            return i;
    }
    return -1;
}
D_array::~D_array()
{
    delete []ptr;

}
D_array::D_array(D_array&D)
{
    capacity=D.capacity;
    lastindex=D.lastindex;
    if(D.ptr==NULL)
        ptr=NULL;
    else{
        ptr=new int [capacity];
        int i=0;
        while(i<=lastindex)
        {
            ptr[i]=D.ptr[i];
            i++;
        }
    }
}
int D_array::count()
{
    return lastindex;
}
int D_array::get_element(int ind)
{
    try{
        if(ind<0||ind>lastindex)
            throw 1;
        return ptr[ind];
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Invalid index Value !!"<<endl;
    }
}
bool D_array::is_empty()
{
    return lastindex!=capacity-1;
}
int D_array::get_capacity()
{
    
    return capacity;
}
void D_array::clear()
{
    delete []ptr;
    ptr=NULL;
    capacity=0;
    lastindex=-1;

}
void D_array::del(int ind)
        {
            try{
                if(ind<0||ind>lastindex)
                    throw 1;
                int i=ind;
                while(i<=lastindex)
                {
                    ptr[i]=ptr[i+1];
                    i++;
                }
                lastindex--;


                
            }
            catch(int e)
            {
                if(e==1)
                    cout<<"invalid Index !!"<<endl;
            }
        }
void D_array::append(int val)
{
    if(lastindex==capacity-1)
        doublearray();
    ptr[lastindex+1]=val;
    lastindex++;

    
}
void D_array::halfarray()
{
    int * ptrn=new int[capacity%2==0?capacity/2:capacity/2+1];
    for(int i=0;i<=lastindex;i++)
        ptrn[i]=ptr[i];
    delete ptr;
    capacity=capacity/2;
    ptr=ptrn;

}
void D_array::doublearray()
{
    int *ptrn=new int[2*capacity];
    for(int i=0;i<=lastindex;i++)
        ptrn[i]=ptr[i];
    delete []ptr;
    ptr=ptrn;
    capacity=capacity*2;
}
void D_array::Insert(int ind,int val)
{
    try{
        if(ind<0)
            throw 1;
        else if(ind>lastindex)
            throw 2;
        else{
            if(lastindex==capacity-1)
                doublearray();
            int i=lastindex;
            while(i>=ind)
            {    
                ptr[i+1]=ptr[i];
                i--;
            }
            ptr[ind]=val;
            
        }
        

    }
    catch(int e)
    {
        if(e==1)
            cout<<"Negative Index Not Allowed !!"<<endl;
        else if(e==2)
            cout<<"Invalid Index value"<<endl;
    }
}
void D_array::create_array(int cap)
{
    capacity=cap;
    ptr=new int[capacity];
    lastindex=-1;
    cout<<"Array created successfully ........"<<endl;
}
void D_array::print()
{
    try{
        if(ptr==NULL)
            throw 1;
        int i=0;
        for(i;i<=lastindex;i++)
            cout<<ptr[i]<<" ";
        cout<<endl;

    }
    catch(int e)
    {
        if(e==1)
            cout<<"Array Not Found !!"<<endl;
    }
}
D_array::D_array()
{
    ptr=NULL;
    capacity=0;
    lastindex=-1;
}
D_array::D_array(int cap)
{
    capacity=cap;
    ptr = new int[capacity];
    lastindex=-1;   
}
D_array::D_array(int cap,int val)
{
    try{
        if(capacity<0)
            throw 1;
        
        capacity=cap;
        ptr = new int[capacity];
        ptr[0]=val;
        lastindex=0;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Invalid Capacity value !!"<<endl;
    }  
}
int main()
{
   
   D_array D;
   D.create_array(5);
   D.append(11);
   D.append(12);
   D.append(13);
   D.append(14);
   D.append(15);
   D.append(16);
   D.append(21);
   D.Insert(3,43);
   cout<<D.get_capacity()<<endl;
   //D.del(3);
   //cout<<D.is_empty()<<endl;
    D_array b=D;



   //D.doublearray();
    //cout<<D.getcap();
    //D.clear();
   D.print();
    b.print();
   return 0;
}