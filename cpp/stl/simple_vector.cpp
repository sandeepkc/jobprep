#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	vector <int> V;
	
	for(int i = 0; i < 100; ++i) {
		V.push_back(i);
	}
	
	cout<<"Printing using integer iteration on the vector.\n";
	for(int i = 0; i < 100; ++i) {
		cout<<V[i]<<" ";
	}

	cout<<"\nNow printing using vector iterator.\n"; 
	for(vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
		cout<<*it<<" ";
	}
	

	return(0);
}
