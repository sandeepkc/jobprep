#include<iostream>
#include<cstring>
using namespace std;

class Father
{
      char name[20];
      public:

      Father(char * fname)
      {
              strcpy(name,fname);
      }
 
      /* Virtual functions allow us to do run time binding of functions.
       * If we don't declare the below function as 'virtual', and  put the
       * the following statements
       * 
       * Father * fp;
       * fp= & sl;
       * fp->show();
       * 
       * It will still call the 'show' function from the base class because 
       * it can't determine the function to be called based on the object class.
       * So, to overcome this, we use virtual function which allows us to do 
       * run time binding and thus allows us to call appropriate function 
       * based on the class to which the object belongs to.
       */
       
      virtual void show()
      {
              cout<<"Father name:"<<name<<endl;
      }
};
 
class Son:public Father
{
      char name[20];
      public :
      Son(char * sname, char * fname):Father(fname)
      /* For a constructor in the derived class, the constructor for the base
       * class should aslo be called like this.
       */
      
      {
               strcpy(name,sname);
      }
 
      void show()
      {
           cout<<"Son name:"<<name<<endl;
      }
};

int main( )
{

     Father * fp;
     Father fl("David");
     fp=& fl;
     fp->show(); //call the father show function
     Son sl ("John","David");
     fp= & sl;
     fp->show(); //call the son show function
     cin.get();
     cin.get();
     cin.get();
     return (0);
}
