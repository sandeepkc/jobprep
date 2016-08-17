#include<iostream>
using namespace std;

int maxSubArraySum(int a[], int size) {
	//Need to return the max if all numbers are negative
	
	int max_so_far = 0, current_sum = 0;

	for(int i = 0; i < size; ++i) {
		current_sum += a[i];
		if(current_sum < 0)
			current_sum = 0;
		else if(current_sum > max_so_far) {
			max_so_far = current_sum;
		}
	}

	return max_so_far;
}

int main(void) {
	int a[] = {-8, -13, 10, 1, 6, 3, -18, 19};
	cout<<maxSubArraySum(a, sizeof(a)/sizeof(a[0]))<<endl;
	return (0);
}
