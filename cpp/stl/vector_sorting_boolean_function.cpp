#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

bool sort_bool_function(const pair<int, char> &i, const pair<int, char> &j)
{
     /*
      * This compatrator function returns true if 'i' goes before 'j' in the
      * ordering, false otherwise.
      */
      
     if(i.first > j.first) return false;
     if(i.first < j.first) return true;
     return j.second < i.second;
}

int main(int argc, char **argv)
{
    vector <pair<int, char> > V;
    
    int i,j;
    char ch;
    
    ifstream input_file;
    ofstream output_file;
    input_file.open(argv[1]);
    output_file.open(argv[2]);
    
    while(input_file>>i>>ch)
    V.push_back(make_pair(i,ch));
    
    sort(V.begin(), V.end(), sort_bool_function); 
    
    for (j = 0; j < V.size(); j++)
        output_file<<V[j].first<<" "<<V[j].second<<endl;
    
    cin.get();
    return (0);
}                       
