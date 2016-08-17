#include<iostream>
#include<map>
using namespace std;

int main(void) {
	map<int, bool> mp;
	if(mp[2] == true) cout<<"babbu"<<endl;
	else cout<<"sandeep"<<endl;

	for(int i = 0; i < 10; ++i) {
		if(i%2 == 0) mp[i] = true;
	}

	for(int i = 0; i < 10; ++i) {
		if(mp[i]) cout<<i<<" ";
	}
	return (0);
}
