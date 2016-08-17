#include<iostream>
using namespace std;

class Ratio{
      public:
             /* As we can see in the below example, constructors can be 
              * overloaded i.e. we can have constructors to initialize 
              * objects from the same class but with different arguments
              */
              
             Ratio(int a, int b)
             {
                       num = a;
                       den = b;
             }
             
             Ratio(int a)
             {
                       num = a;
                       den = 1;
             }
             
             Ratio()
             {
                    num = 0;
                    den = 1;
             }
             
             void print(void)
             {
                   cout<<num<<"/"<<den<<"\n";
             }
      private:
              int num;
              int den;
};

int main(int argc, char **argv)
{
    Ratio x, y(5), z(3,4);
    /* This will call all the three constructors */
    
    x.print();
    y.print();
    z.print();
    cin.get();
    return (0);
}
