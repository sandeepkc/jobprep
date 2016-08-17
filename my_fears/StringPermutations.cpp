#include<iostream>
using namespace std;

void swap(char *x, char *y) {
	char temp = *x;
	*x = *y;
	*y =  temp;
}

void printPermutations(char *s, int left, int right) {
	if(left == right) 
		cout<<s<<"\n";
	else {
		for(int i = left; i <= right; ++i) {
			swap(s + i, s + left);
			printPermutations(s, left + 1, right);
			swap(s + left, s + i);
		}
	}
}

int main(void) {
	char input[] = "ABC";
	printPermutations(input, 0, 2);
	return (0);
}
