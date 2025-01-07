


/*# include<stdio.h>
int duplicate_elements(int size,int a[])
{   
    int duplicate=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(a[i]==a[j])
            {
                duplicate++;
                break;

            }
        }
    }
    return duplicate;
}

int main() {
    int size=6;
    int a[6]={10,10,10,30,30,40};
    printf("%d",duplicate_elements(size,a));
    return 0;
}*/


//unique elements of array!

/*# include<stdio.h>
void sort(int size,int a[])
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(a[i]>a[j])
            {
                int w=a[i];
                a[i]=a[j];
                a[j]=w;
            }
        }
    }
}
void unique_elements(int size,int a[])
{
    sort(size,a);
    int i=0;
    while(i<size)    
        while(a[i]==a[i+1])
            i++;
        printf("%d ",a[i+1]);
        i++;
    
}
int main() {
    int size=10;
    int a[10]={10,20,10,40,40,50,60,70,80};
    unique_elements(size,a);
    return 0;
}*/




# include<stdio.h>
# include<string.h>
struct Book
{
    int bookid;
    char title[20];
    char author[30];
    float price;

};
void display_book(struct Book);
struct Book input_book();


int main() {
    struct Book b1,b2;
    b1.bookid=101;
    //fflush(stdin);
    strcpy(b1.title,"Rich Dad Poor Dad");
    strcpy(b1.author,"Robert Keiyosaki");
    b1.price=505;
    //printf("%s",b1.author);
    b2=input_book();
    display_book(b1);
    printf("\n");
    display_book(b2);


    return 0;
}
void display_book(struct Book b)
{
    printf("%d %s %s %.2f",b.bookid,b.title,b.author,b.price);
}
struct Book input_book()
{
    struct Book b;
    printf("Enter Bookid:- ");
    scanf("%d",&b.bookid);
    fflush(stdin);
    fgets(b.title,20,stdin);
    b.title[strlen(b.title)-1]=0;
    fflush(stdin);
    fgets(b.author,30,stdin);
    b.author[strlen(b.author)-1]=0;
    fflush(stdin);

    scanf("%f",&b.price);
    return b;


}