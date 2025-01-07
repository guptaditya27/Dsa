#include<iostream>
using namespace std;
class Area
{
    private:
        int l,b;
    public:
        Area()
        {
            l=1,b=1;
        }
        void set(int a,int c)
        {
            l=a,b=c;
        }
        int get_area()
        {
            return l*b;
        }
};
int main()
{
   Area a;
   cout<<a.get_area();
   return 0;
}