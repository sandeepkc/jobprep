#include<iostream>
using namespace std;

const int size = 3;

class vector{
      int v[size];
      public:
             vector();
             vector(int *);
             friend vector operator* (int, vector);
             
             /* The above function needs to be a 'friend' function because 
              * while when this operator is applied e.g. 2*a, where a is an 
              * object of class vector, both the arguments are not object of
              * same class.
              * Friend function have two properties -
              * 1. It can access the private members
              * 2. The aruguments to a friend function can be from different 
              *    classes
              */
              
             friend istream & operator >>(istream &, vector &);
             friend ostream & operator <<(ostream &, vector &);
             /* Same is the case with above two function. To overload the 'c.in'
              * and 'c.out', we must declare these as friend fuctions.
              */
};

vector:: vector()
{
         for(int i = 0; i < size; i++)
                 v[i]=0;
}

vector:: vector(int *a)
{
         for(int i = 0; i < size; i++)
                 v[i] = a[i];
}
         
vector operator* (int a, vector b)
{
       vector temp;
       for(int i = 0; i < size; i++)
               temp.v[i] = a*b.v[i];
       return temp;
}

/* The below definitions are so cool. We can overload the 'c.in' and 'c.out'
 * for our defined data types and can those in a very easy and efficient 
 * manner.
 */
 
istream & operator >> (istream &din, vector &b)
{
        for(int i = 0; i < size; i++)
                din>>b.v[i];
        return (din);
}

ostream & operator << (ostream &dout, vector &b)
{
        dout<<"("<<b.v[0];
        for(int i = 1; i < size; i++)
                dout<<","<<b.v[i];
        dout<<")";
        return (dout);
}
        
int x[size] = {1,2,3};

int main(int argc, char **argv)
{
    vector m; //Will invoke the first constructor
    vector n(x); //Will invoke the other constructor
    cout<<"Enter vector elements.\n";
    cin>>m;
    cout<<"\n";
    cout<<"m = "<<m<<"\n";
    cout<<"n = "<<n<<"\n";
    vector p,q;
    p = 2*m;
    q = 2*n;
    cout<<"p = "<<p<<"\n";
    cout<<"q = "<<q<<"\n";
    cin.get();
    cin.get();
    return (0);
}
