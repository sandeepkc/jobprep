#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<string> S;
	
	S.push("The");
	S.push("quick");
	S.push("brown");
	S.push("dogs");
	S.push("jumped");
	S.push("over");
	S.push("the");
	S.push("lazy");
	S.push("fox");
	
	cout<<"Size of the stack = "<<S.size()<<endl;

	while(!S.empty()) {
		cout<<S.top()<<" ";
		S.pop();
	}

	return(0);
}
