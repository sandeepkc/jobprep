#include<iostream>
using namespace std;

bool is_palindrome_dont_ignore_special(string s) {
	if(s.size() <= 1) return true;
	for(int i = 0; i < s.size()/2; ++i) {
		if(s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}

int main(void) {
	cout<<is_palindrome_dont_ignore_special("sandeep")<<" no"<<endl;
	cout<<is_palindrome_dont_ignore_special("%^^%")<<" yes"<<endl;
	cout<<is_palindrome_dont_ignore_special("a@#.#@a")<<" yes"<<endl;
	cout<<is_palindrome_dont_ignore_special("a@#asaa.#@a")<<" no"<<endl;
	return 0;
}
