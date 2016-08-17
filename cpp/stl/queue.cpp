#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<string> Q;
	
	Q.push("The");
	Q.push("quick");
	Q.push("brown");
	Q.push("dogs");
	Q.push("jumped");
	Q.push("over");
	Q.push("the");
	Q.push("lazy");
	Q.push("fox");
	
	cout<<"Size of the queue = "<<Q.size()<<endl;

	while(!Q.empty()) {
		cout<<Q.front()<<" ";
		Q.pop();
	}
	cout<<endl;

	return(0);
}
