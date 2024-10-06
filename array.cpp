#include<iostream>
using namespace std;
#include<stdio.h>
class Array
{
    private:
        int capacity;
        int *ptr;
        int lastindex;
    public:
        void create_array(int);
        void insert(int,int);
        void append(int);
        void extend(Array);
        int getitem(int);
        bool isempty();
        bool isfull();
        void del(int);
        void edit(int,int);
        int count();
        int getcapacity();
        int get_lastindex();
        void printar();
        void sort(int =1);
        int search(int);
        void clear();
        
        Array sub_array(int,int);
        void copy(Array);
        Array(Array &);
        Array()
        {
            
            ptr=NULL;
            
        }
        Array& operator=(Array &);
        ~Array();

};
Array Array::sub_array(int index1,int index2)
{
    // condn jisme code nhi chalega 
    /*
        1. index -ve ho to 
        2. index >lastindex;
        3. index 

    */
    try{
        if(index1<0||index2<0||index1>index2||index2>lastindex)
        {
            throw 1;
        }
        Array a;
        create_array(index2);
        int i=index1;
        while(i<=index2)
        {
            a.append(*(ptr+i));
            i++;
        }
        return a;

    }
    catch(int e){
        if(e==1)
        {
            cout<<"Invalid Subarray Index !!"<<endl;
        }
    }
}
void Array::copy(Array a)
{

}
void Array::sort(int k) {
    for (int i = 0; i <= lastindex; i++) {
        for (int j = i + 1; j <= lastindex; j++) {
            if (ptr[i] > ptr[j]) {
                int temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    if(k==1)
    {
       for (int i = 0; i <= lastindex; i++) {
        for (int j = i + 1; j <= lastindex; j++) {
            if (ptr[i] < ptr[j]) {
                int temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        } 
    }
    }
}
    
int Array::get_lastindex()
{
    return lastindex;
}
void Array::extend(Array a)
{   // condn jisme code nhi chalega 
    /*
        1. agar calling array full hoga to extend nhi hoga.
        2. agar extending array ka size empty space se jada hoo too..
        3. extending array empty hogi tb
        4. datatype different hoga tab.
    */
    try{
        if(isfull())
            throw 1;
        else if(a.lastindex>(this->capacity-this->lastindex))
            throw 2;
        else if(a.isempty())
            throw 3;
        else{
            int i=0;
            while(i<=a.lastindex)
            {
                this->append(a.getitem(i));
                i++;
                
            }
        }
    }
    catch(int e)
    {
        if(e==1)
        {
            cout<<"NOT Enough Sapce to Extend!!"<<endl;
        }
        else if(e==2)
        {
            cout<<"Not Enough space !! "<<endl;
        }
        else if(e==3)
        {
            cout<<"Extending array is EMPTY!!"<<endl;
        }
    }

}
void Array::printar()
{
    int i=0;
    while(i<=lastindex)
    {
        cout<<*(ptr+i)<<" ";
        i++;
    }
    cout<<endl;
}
Array::~Array()
{
    delete []ptr;
}
Array& Array::operator=(Array &arr )
{
    capacity=arr.capacity;
    lastindex =arr.lastindex;
    if(ptr!=NULL)
        delete []ptr;
    ptr =new int[capacity];
    for(int i=0;i<=lastindex;i++)
        ptr[i]=arr.ptr[i];
    return (*this);//arr3=arr2=arr1;
}
Array::Array(Array &arr)
{
    capacity=arr.capacity;
    lastindex =arr.lastindex;
    ptr =new int[capacity];
    for(int i=0;i<=lastindex;i++)
        ptr[i]=arr.ptr[i];

}
void Array::create_array(int cap)
{
    //dynamic Array creation
    capacity=cap;
    lastindex=-1;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];

    
}
void Array::insert(int index,int data)
{
    int i;
    try{
        if(index<0||index>lastindex+1)
            throw 1; 
        if(isfull())
            throw 2;
        for(i=lastindex;i>=index;i--)
        {
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        lastindex++; 

    }
    catch(int e){
        if(e==1)
            cout<<"Invalid index"<<endl;
        else if(e==2)
            cout<<"Array fully loaded!!"<<endl;
        
    }    
}
void Array::append(int data)
{
    if(!isfull())
    {
        lastindex++;
        ptr[lastindex]=data;
    }
    else{
        cout<<"Array overflow!!!"<<endl;
    }
} 

int Array::getitem(int index)
{
    try{
        if(index>lastindex||index<0)
            throw 1;
        return ptr[index];
    }
    catch(int e){
        if(e==1)
            cout<<"\nInvalid index!!"<<endl;
    }
    return -1;
}
bool Array::isempty()
{
    return lastindex==-1;
}
bool Array::isfull()
{
    return lastindex==capacity-1;
}
void Array::edit(int index,int newdata)
{
    try{
        if(index<0||index>lastindex)
            throw 1;
        ptr[index]=newdata;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\ninvalid index!!"<<endl;
    }
}
void Array::del(int index)
{
    try
    {
        int i;
        if(index<0||index>lastindex)
            throw 1;
        for(i=index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;
        
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\n invalid index!! underflow "<<endl;
    }
    
}
int Array::count()
{
    return lastindex+1;
}
int Array::getcapacity()
{
    return capacity;
}
int Array::search(int element)
{
    // implementing linear search for now
    int i=0;
    while(i<=lastindex){
        
        if(ptr[i]==element)
        {
            return i;// will return only first occurence of Element.
            
        }
        i++;

    }
    return -1;
}
void Array::clear()
{
    // condn where not work
    // 1. agar empty hoga to
    // 2. if not created then.
    // 3. 
        try{
        if(this->lastindex==-1)
            throw 1;
        
        delete []ptr;
        ptr = new int[capacity];
        lastindex=-1;
    }
    catch(int e)
    {
        if(e==1)
        {
            cout<<"Array is Empty"<<endl;
        }
        
    }
}

int main()
{
    
    Array a,b;
    a.create_array(10);
    b.create_array(10);
    
    a.append(10);
    //a.insert(1,20);

    a.append(20);
    a.append(40);
    
    //b.printar();
    b.append(50);
    b.append(25);
    a.extend(b);
    a.sort(1);
    cout<<a.count()<<endl;
    cout<<a.getcapacity()<<endl;
    cout<<a.search(35)<<endl;
    a.printar();
    Array c;
    a.sub_array(1,3);
    cout<<b.get_lastindex()<<endl;
    cout<<b.getcapacity()<<endl;
    a.clear();
    a.printar();



    return 0;
}
