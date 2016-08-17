#include<iostream>
using namespace std;

class Constructor_destructor{
      public:
             Constructor_destructor()
             {
                                     cout<<"Obeject is created.\n";
                                     }
             ~Constructor_destructor()
             {
                                      cout<<"Object is dead.\n";
                                      }
};

int main(int argc, char **argv)
{
    {
             Constructor_destructor x;
             /* The above will invoke the constructor */
             
             cout<<"Now x is alive.\n";
             /* The destructor will kick in aautomatically when the scope 
              * of this block is over. If the block is removed, the destructor 
              * will not come into picture. Destructors are needed necessarily. 
              */
              
    }
    
    cout<<"Now between the blocks.\n";
    
    {
             Constructor_destructor y;
             cout<<"Now y is alive.\n";
    }
    
    cin.get();
    return (0);
}
