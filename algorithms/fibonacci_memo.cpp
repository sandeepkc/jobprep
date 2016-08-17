#include<bits/stdc++.h>
using namespace std;

long long int memo[100];

int fib(int n) {
	if(n == 0 || n == 1 || n == 2)
		return 1;
	if(memo[n] != -1) return memo[n];
	
	else memo[n] = fib(n - 1) +  fib(n - 2);
	return memo[n];
}

int main(void) {
	for(int i = 0; i < 100; ++i)
		memo[i] = -1;
	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 1;
	cout<<fib(40)<<endl;
	return (0);
}
	
