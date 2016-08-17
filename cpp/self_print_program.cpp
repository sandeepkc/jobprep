#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char **argv)
{
    ifstream input_file;
    input_file.open("self_print_program.cpp");
    
    string line;
    
    while(input_file.is_open())
        {
        while(input_file.good())
            {
            getline(input_file, line);
            cout<<line<<endl;
        }
    
        input_file.close();
    }
    
    cin.get();
    return (0);
    
}
