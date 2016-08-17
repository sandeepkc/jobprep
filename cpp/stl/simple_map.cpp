#include<iostream>
#include<map>
using namespace std;

int main(void) {
	map <char, int> mp;
	
	int count = 0;
	for(char ch= 'a'; ch <= 'z'; ++ch) {
		mp[ch] = ++count;
	}

	for(char ch = 'a'; ch <='z'; ++ch) {
		cout<<ch<<" "<<mp[ch]<<endl;
	}

	return(0);
}
	 
		
