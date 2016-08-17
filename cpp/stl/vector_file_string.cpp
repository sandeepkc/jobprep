#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main(int argc, char **argv)
{
    vector<string> V;
    
    ifstream input_file;
    input_file.open(argv[1]);
    
    string word;
    
    while(input_file>>word)
    {
                           sort(word.begin(), word.end());
                           V.push_back(word);
    }
    
    sort(V.begin(), V.end());
    
    int i;
    
    for(i = 0; i < V.size(); i++)
          cout<<V[i]<<endl;
    
    cin.get();
    cin.get();
    return (0);
}
