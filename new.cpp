#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
struct Book
{
    private:
        int bookid;
        char title[20];
        char author[30];
        float price;
    public:
        struct Book input_book()
        {
            
            //struct Book b;
            cout<<"Enter bookid,title,author,price:- ";
            cin>>bookid;
            if(bookid<0)
                bookid=-bookid;
            cin.ignore();
            cin.getline(title,20);
            cin.getline(author,30);
            
            
            
            /*fflush(stdin);
            fgets(title,20,stdin);
            title[strlen(title)-1]=0;
            fflush(stdin);
            fgets(author,30,stdin);
            author[strlen(author)-1]=0;*/
            cin>>price;
            

        }
        void display_book()
        {
            cout<<bookid<<" "<<title<<" "<<author<<" "<<price<<endl;
        }
};
int main()
{
    Book b1;
   
   b1.input_book();
   b1.display_book();

   return 0;
}