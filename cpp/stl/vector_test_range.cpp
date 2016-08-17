#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char **argv)
{
    vector <int> test(3, 100);
    
    test.push_back(101);
    test.push_back(102);
    /* 
     * This will push the above two elements at the end of the existing 
     * vector.
     */
         
    vector <int>::const_iterator ci;
    
    for(ci = test.begin(); ci != test.end(); ci++)
           cout<<*ci<<endl;
           
    /* This will print all the five values */
    
    cin.get();
    return (0);
}
