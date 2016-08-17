#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char **argv)
{
    vector <string> S;
    /* 
     * This is how vectors are declared in a simple way. The full declaration
     * syntax is following 
     * vector <type> name(number_of_elements, value);
     * In the above case, all the vector elements will be initialized to
     * the value of 'value'.
     */
    
    S.push_back("Vector is an awesome thing.");
    S.push_back("Vector is so fucking awesome.");
    //vector<string> SS(S.rbegin(), S.rend());
    S.push_back("Vector is way too cool.");
    /*
     * In the above scenario, these elements will be pushed in the vector in
     * an orderly function. 
     */
    
    vector<string> SS(S.rbegin(), S.rend());
    /*
     * begin(), end() and other similar function are based on current values.
     * For example, if we use the similar commented declaration, it will
     * only copy the two strings pushed to the vector 'S'.
     */ 
    
    int i;
    
    for(i = 0; i < S.size() ; i++)
          cout<<S[i]<<endl;
    cout<<endl;
    
    for(i = 0; i < SS.size() ; i++)
          cout<<SS[i]<<endl;
    cout<<endl;
    
    vector <string>::const_iterator ci;
    /* 
     * The above declares an iterator 'ci' which will help to iterate from 
     * S.begin() to S.end(). We can't treat 'ci' as usual integer iterator.
     * Basically, it holds the address of element. 
     * As seen in the below commented piece of code, 'ci' can't be used in 
     * that fashion. It has to be iterated using 'begin()' and 'end()'.
     */
     
    //for(ci = 0; ci < S.size() ; ci++)
    //       cout<<*ci<<endl;
    
    for(ci = S.begin(); ci != S.end(); ci++)
           cout<<*ci<<endl;
           
    cout<<endl;
    
    vector <string>::reverse_iterator ri;
    
    for(ri = S.rbegin(); ri != S.rend(); ri++)
           cout<<*ri<<endl;
    
    
    cout<<endl<<"New output:"<<endl<<"S.size = "<<S.size()<<endl;
    
    /*
     * For the reasons explained above, below statements are not valid.
     */
      
    //cout<<"S.begin() = "<<S.end()<<endl;
    //cout<<"S.rbegin() = "<<S.rbegin()<<endl;
    
    cout<<"S.end() - S.begin() = "<<S.end() - S.begin()<<endl;
    
    cin.get();
    return (0);
}
