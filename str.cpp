/*include<iostream>
#include<string.h>
using namespace std;
struct Book
{
    int bookid;
    char title[20];
    char author[30];
    float price;
    struct Book input_book()
    {
        
        struct Book b;
        cout<<"Enter bookid,title,author,price";
        cin>>b.bookid;
        fflush(stdin);
        fgets(b.title,20,stdin);
        b.title[strlen(b.title)-1]=0;
        fflush(stdin);
        fgets(b.author,30,stdin);
        b.author[strlen(b.author)-1]=0;
        cin>>b.price;
        return b;

    }
    void display_book(struct Book b)
    {
        cout<<b.bookid<<" "<<b.title<<" "<<b.author<<" "<<b.price<<endl;
    }
};
int main()
{
   struct Book b1;
   b1=b1.input_book();
   b1.display_book(b1);

   return 0;
}*/



#include<iostream>
#include<string.h>
using namespace std;
struct Book
{
    int bookid;
    char title[20];
    char author[30];
    float price;
    struct Book input_book()
    {
        
        struct Book b;
        cout<<"Enter bookid,title,author,price";
        cin>>b.bookid;
        /*/fflush(stdin);
        fgets(b.title,20,stdin);
        b.title[strlen(b.title)-1]=0;
        fflush(stdin);
        fgets(b.author,30,stdin);
        b.author[strlen(b.author)-1]=0;*/
        cin.ignore();
        cin.getline(b.title,20);
        cin>>b.price;
        return b;

    }
    void display_book(struct Book b)
    {
        cout<<b.bookid<<" "<<b.title<<" "<<b.author<<" "<<b.price<<endl;
    }
};
int main()
{
   struct Book b1;
   b1=b1.input_book();
   b1.display_book(b1);

   return 0;
}