#include<iostream>
using namespace std;

bool is_alpha(string s, int i) {
	if(s[i] >= 'a' && s[i] <= 'z') return true;
	if(s[i] >= 'A' && s[i] <= 'Z') return true;
	return false;
}

bool is_palindrome_ignore_special(string s) {
	if(s.size() <= 1) return true;
	int front = 0, back = s.size() - 1;
	do {
		while(!is_alpha(s, front)) front++; 
		while(!is_alpha(s, back)) back--;
		if(front >= back) return true;
		if(s[front] != s[back]) return false;
		front++;
		back--;
	} while (front < back);
	return true;
}

int main(void) {
	cout<<is_palindrome_ignore_special("a@#bc.#$cba")<<" yes"<<endl;
	cout<<is_palindrome_ignore_special("a@#c.#$cba")<<" no"<<endl;
	cout<<is_palindrome_ignore_special("a@#c.#$ca")<<" yes"<<endl;
	cout<<is_palindrome_ignore_special("a^$%^>,][")<<" yes"<<endl;
	cout<<is_palindrome_ignore_special("a@#a%$#@.<")<<" yes "<<endl;
	return 0;
}
