#include<iostream>
using namespace std;

class person
{
      char *name;
      int age;
      /* Above members will be private by default */
      
      public:
             void getdata(void);
             void printdata(void);
};

void person:: getdata(void)
{
     cout<<"Input your name and age.\n";
     cin>>name>>age;
}
     
void person:: printdata(void)
{
     cout<<"Name : "<<name<<"\n";
     cout<<"Age : "<<age<<"\n";
}

int main(int argc, char **argv)
{
    person p;
    p.getdata();
    p.printdata();
    cin.get();
    return (0);
}
