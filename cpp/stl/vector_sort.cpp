#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//This will do the comparison with respect to the last char
bool my_comp(string a, string b) {
	return (a[a.size()-1] < b[b.size()-1]);
}
int main() {
	vector<string> V;

	V.push_back("The");
	V.push_back("quick");
	V.push_back("brown");
	V.push_back("dogs");
	V.push_back("jumped");
	V.push_back("over");
	V.push_back("the");
	V.push_back("lazy");
	V.push_back("fox");

	//sort(V.begin(), V.end());
	sort(V.begin(), V.end(), my_comp);
	
	for(int i = 0; i < V.size(); ++i)
		cout<<V[i]<<" ";
	cout<<endl;

	return (0);
}
	
