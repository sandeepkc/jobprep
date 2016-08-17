#include<iostream>
using namespace std;

class test{
      int a;
      //int a = 20;
      /* The above and below for 'b' will not be allowed as per ISO C++
       * standards. Initialization can be done through constructors and not 
       * like this.
       */
      
      public:
             int b;
             //int b = 10;
             test(int x, int y)
             {
                      a = x;
                      b = y;
             }
             test(){}
};

int main(int argc, char **argv)
{
    test x;
    /* we must have the second constructor if we wish to make a call like this.
     */
    
    test y(25,25);
    //x.a = 10;
    /* This will not be allowed because 'a' is private to the class 'test' and 
     * can't be accessed through the objects of this class.
     */
     
    x.b = 10;
    cout<<x.b<<"\n";
    cout<<y.b<<"\n";
    cin.get();
    return (0);
}    
