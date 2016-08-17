#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char **argv)
{
    ofstream output_file;
    output_file.open("config.txt");
    
    for(int i = 1; i < 10; i++)
        output_file<<"controller t1 0/2/1/0/"<<i<<" cem-group unframed"<<endl;
    for(int i = 1; i < 10; i++)
        output_file<<"controller e1 0/2/1/1/"<<i<<" cem-group unframed"<<endl;
    for(int i = 1; i < 10; i++)
        {
        output_file<<"interface cem 0/2/1/0/"<<i<<" cem dummy mode user"<<endl;
        output_file<<"interface cem 0/2/1/0/"<<i<<" cem dummy pattern 0xcc"<<endl;
        output_file<<"interface cem 0/2/1/0/"<<i<<" cem idle pattern 0xcd"<<endl;
        output_file<<"interface cem 0/2/1/0/"<<i<<" cem payload 320"<<endl;
        output_file<<"interface cem 0/2/1/0/"<<i<<" cem dejitter 3"<<endl;

        output_file<<"interface cem 0/2/1/1/"<<i<<" cem dummy mode user"<<endl;
        output_file<<"interface cem 0/2/1/1/"<<i<<" cem dummy pattern 0xcc"<<endl;
        output_file<<"interface cem 0/2/1/1/"<<i<<" cem idle pattern 0xcd"<<endl;
        output_file<<"interface cem 0/2/1/1/"<<i<<" cem payload 320"<<endl;
        output_file<<"interface cem 0/2/1/1/"<<i<<" cem dejitter 3"<<endl;
        }        
    
    return (0);
}
    
