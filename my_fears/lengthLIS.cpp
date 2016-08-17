#include<iostream>
using namespace std;

int lengthLIS(int a[], int size) {
	int lis[size];
	
	//lis[i] has the length of the longest subsequence 
	//till index i that includes a[i]
	for(int i = 0; i < size; ++i) {
		lis[i] = 1;
	}

	for(int i = 1; i < size; i++) {
		for(int j = 0; j < i; j++) {
			if(a[i] > a[j] && lis[i] < lis[j] + 1) {
				lis[i] = lis[j] + 1;
			}
		}
	}

	int max = 0;
	for(int i = 0; i < size; ++i) {
		if(max < lis[i]) {
			max = lis[i];
		}
	}
	
	return max;
}
	
int main(void) {
	int a[] = {5, 13, 8, 11, 6, 3, 2, -1, 8, 9, 13};
	cout<<lengthLIS(a, sizeof(a)/sizeof(a[0]))<<endl;
	return (0);
}
