#include<iostream>
using namespace std;

template <class T>

class test{
      public:
             void swap(T &x, T &y)
             {
                  T t;
                  t = x;
                  x = y;
                  y = t;
             }
             test(){}
}; 

int main(int argc, char **argv)
{
    test <int> t1;
    test <char> t2;
    int a = 4, b = 5;
    char x = 'c', y = 'd';
    t1.swap(a, b);
    t2.swap(x, y);
    cout<<" a = "<<a<<" b = "<<b<<"\n";
    cout<<" x = "<<x<<" y = "<<y<<"\n";
    cin.get();
    return (0);
}
