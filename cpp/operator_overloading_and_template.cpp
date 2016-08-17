#include<iostream>
using namespace std;

const int size = 3;
template <class T>

class vector{
      T *v;
      public:

      vector(T *a)
      {
         v = new T[size];
         for(int i = 0; i < size; i++)
                 v[i] = a[i];
      }
         
      T operator* (vector &b)
      {
         T sum = 0;
         for(int i = 0; i < size; i++)
                 sum = sum + this->v[i]*b.v[i];
         return (sum);
      }
};

/* The below definitions are so cool. We can overload the 'c.in' and 'c.out'
 * for our defined data types and can those in a very easy and efficient 
 * manner.
 */
 
       
int x[size] = {1,2,3};

int main(int argc, char **argv)
{
    vector <int> n(x); //Will invoke the other constructor
    int m = n*n;
    cout<<"m = "<<m<<"\n";
    cin.get();
    return (0);
}
