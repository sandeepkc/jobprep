#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main(int argc, char **argv)
{
    vector <pair<int, char> > V;
    int i;
    char ch;
    
    ifstream input_file;
    input_file.open("input.txt");
    
    ofstream output_file;
    output_file.open("output.txt");
    
    while(input_file>>i>>ch)
    V.push_back(make_pair(i,ch));
    
    sort(V.begin(), V.end());
    
    /* 
     * Basically this kind of sorting will sort on the basis of first member
     * of the pair.
     */
    
    for(i = 0; i < V.size(); i++)
    output_file<<V[i].first<<" "<<V[i].second<<endl;
    
    cin.get();
    return (0);
    
}
                            
    
