#include<bits/stdc++.h>
using namespace std;


int fib(int n) {
	if(n == 0 || n == 1 || n == 2)
		return 1;
	else return  fib(n - 1) +  fib(n - 2);
}

int main(void) {
	cout<<fib(40)<<endl;
	return (0);
}
	
