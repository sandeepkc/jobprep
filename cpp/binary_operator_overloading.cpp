#include<iostream>
using namespace std;

class complex{      
      float x,y;
      
      /* These two are private by default hence can't be accessed outside this 
       * class. This is the reason printing these values directly in the main 
       * function failed. When these are accessed via the public function 
       * 'display' which is declared in this class, there are no issues. 
       */
       
      public:
             complex(){}
             complex(float a, float b)
             {
                           x = a;
                           y = b;
             }
             
             complex operator + (complex);
             /* The above function doesn't have to be a friend function because
              * the arguments to the operator '+' will be objects of the same 
              * class
              */
              
             void display(void);
};

complex complex:: operator + (complex c)
{
        complex temp;
        
        /* For the first argument, we have to use the members directly from the
         * class. The use of this operator will actually be in the following
         * way -
         * c = c1 + c2;
         * c, c1 and c2 are all objects of the class 'complex' here.
         */
         
        temp.x = this->x + c.x;
        temp.y = this->y + c.y;
        return (temp);
}

void complex:: display(void)
{
     cout<<x<<"+i"<<y<<"\n";
}

int main(int argc, char **argv)
{
    complex a(5.4, 6.5);
    complex b(4, 3.9);
    complex z;
    
    z = a + b;
    
    //cout<<"z = "<<z.x<<" + i"<<z.y<<"\n";
    
    /* Can't access the private members x and y outside the scope of the class.
     * This is the reason it gave error while trying to do the above. 'x' and
     * 'y' are private and can't be accessed by the objects of the class.
     */
     
    z.display();
    cin.get();
    return (0);
} 
