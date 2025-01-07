#include<iostream>
using namespace std;

class item {
    private:
        int a, b;
        static int k;
    public:
        void set_a(int);
        void set_b(int);
        static void set_k(int);
        int get_a();
        int get_b();
        static int get_k();
};

int item::k;

void item::set_a(int k) { a = k; }
void item::set_b(int k) { b = k; }
void item::set_k(int w) { k = w; }
int item::get_a() { return a; }
int item::get_b() { return b; }
int item::get_k() { return k; }

int main() {
    item i1, i2;
    i1.set_k(10);
    cout << i1.get_k() << endl;  // Corrected line
    //cout<<item::get_k() cant call member fn without obj
    // static member fn can be called without
    item::set_k(5);
    cout<<item::get_k();

    return 0;
}
