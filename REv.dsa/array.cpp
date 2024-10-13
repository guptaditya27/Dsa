#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<cmath>
class Array
{
    private:
        int lastindex;
        int capacity;
        int *ptr;
    public:
        Array();
        Array(Array &);
        void create_array(int);
        void append(int);
        void print();
        int get_capacity();
        int get_lastindex();
        bool is_full();
        bool is_empty();
        void insert(int ,int);
        void extend(Array&);
        void extend(int [],int);
        
        //void del(int=lastindex);
        int pop();
        void del();
        void sort(int=1);
        void reverse();
        ~Array()
        {
            delete []ptr;
        }
        

};

bool Array::is_full()
{
    return (lastindex+1==capacity);
}
bool Array::is_empty()
{
    return (lastindex+1 !=capacity);
}
int Array::get_capacity()
{
    return capacity;
}
int Array::get_lastindex()
{
    return lastindex;
}
void Array::print()
{
    int i=0;
    while(i<=lastindex)
    {
        cout<<ptr[i]<<" ";
        i++;
    }
    cout<<endl;
}
void Array::append(int data)
{
    try{
        if(ptr==NULL)
            throw 1;
        else if(lastindex+1==capacity)
            throw 2;
        ptr[lastindex+1]=data;
        lastindex++;
        //cout<<data<<" Appended Succesfully at "<<lastindex<<endl;

        
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Create array first !!"<<endl;
        else if(e==2)
            cout<<"Array is Full !! "<<data<<" Not Appended !!"<<endl;
    }
}
Array::Array()
    {
        
        lastindex=-1;
        capacity=0;
        ptr=NULL;


    }
Array::Array(Array &a)
{
    lastindex=a.lastindex;
    capacity=a.capacity;
    ptr=new int[capacity];
    int i=0;
    while(i<=lastindex)
    {
        ptr[i]=a.ptr[i];
        i++;
    }
}
void Array::insert(int index,int data)
{
    // condn jiska dhyan rkhna hai
    /*
        1. khii array full to nhi.
        2. khii uss index pe value to nhi hai.
        3. agr value hai to kya krege.
        4. array created to hai n.
        5. specified index is valid or not.
    */
   try{
    if(index>=capacity||index<0)
        throw 1;
    else if(is_full())
        throw 2;
    else if(ptr==NULL)
        throw 3;
    else if(index<=lastindex)
    {
        int i=lastindex;
        int a=ptr[lastindex];
        while(i>=index)
        {
            ptr[i+1]=ptr[i];
            i--;
        }
        ptr[index]=data;
        lastindex++;
    }
    else if(index>lastindex&&index<capacity)
    {
        ptr[index]=data;
        lastindex++;
    }
    
   }
   catch(int e)
   {
    if(e==1)
        cout<<"Not a Valid Index No !!!"<<endl;
    else if(e==2)
        cout<<"Array is Full !!!"<<endl;
    else if(e==3)
        cout<<"Array Not Found !!"<<endl;
   }
}
void Array::extend(Array &a)
{
    // condn jinka dhyan rkhna hai.
    /*
        1. array created hai ya nhi.
        2. array full hai ya nhi.
        3. agar full nhi hai to kitni jagah hai 
        4. jitni jagah ho utne elements extend ho jyee.
        5. 
    */
   try{
    if(is_full())
        throw 1;
    else if(ptr==NULL)
        throw 2;
    else if(a.lastindex>(capacity-lastindex)-1)
    {
        int i=(capacity-lastindex)-1;
        while(i>0)
        {
            int w=0;
            lastindex++;
            ptr[lastindex]=a.ptr[w];
            w++;
            i--;
        }
        if(i==0)
            cout<<"....Array space Full.... Terminating Operation .........."<<endl;
    }
    else{
        //int i=0;
        cout<<"inside else"<<endl;
        
        for(int i=0;i<=a.lastindex;i++)
        {
            lastindex++;
            ptr[lastindex]=a.ptr[i];
            
        }
    }
   }
   catch(int e)
   {
    if(e==1)
    {
        cout<<"Array overflow !!"<<endl;
    }
    else if(e==2)
    {
        cout<<"Array Not Created!!!"<<endl;   
    }
    else if(e==3)
    {
        cout<<"Array space full !!"<<endl;
    }
   }
}

void Array::del()
{
    delete []ptr;
    ptr =NULL;
    lastindex=-1;
    capacity=0;
    cout<<" Array Deleted successfully"<<endl;

}
int Array::pop()
{
    int i=ptr[lastindex];
    lastindex--;
    return i;

}
void Array::reverse()
{

}
void Array::sort(int i)
{
    try{
        if(ptr==NULL)
            throw 1;
        if(i==1)
        {
            
        }
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Array is NOt created....."<<endl;
        else if(e==2)

    }
}

void Array::create_array(int size)
{
    try{
        if(ptr!=NULL)
            throw 1;
        else if(size<=0)
            throw 2;
        capacity=size;
        lastindex=-1;
        ptr =new int[size];
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Array Already exist Delete first !!! "<<endl;
        else if(e==2)
            cout<<"Size can't be Less than equal's Zero !!!"<<endl;
    }
}
int main()
{
   Array a;
   a.create_array(5);
   a.append(10);
   //a.append(20);
   //a.append(30);

   a.append(40);
   Array b;
   b.create_array(5);
   b.append(11);
   b.append(21);
   b.append(23);
   a.extend(b);
   a.print();
   a.del();
   a.print();
   //cout<<a.get_lastindex()<<"  "<<a.is_full();

   return 0;
}