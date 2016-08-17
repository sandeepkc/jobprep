#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main() {
	list<string> L;
	
	L.push_back("The");
	L.push_back("quick");
	L.push_back("brown");
	L.push_back("dogs");
	L.push_back("jumped");
	L.push_back("over");
	L.push_back("the");
	L.push_back("lazy");
	L.push_back("fox");
	
	cout<<"Size of the list = "<<L.size()<<endl;

	list<string>::iterator it;
	for(it = L.begin(); it != L.end(); ++it)
		cout<<*it<<" ";
	cout<<endl;

	L.sort();

	while(!L.empty()) {
		cout<<L.front()<<" ";
		L.pop_front();
	}
	cout<<endl;

	return(0);
}
