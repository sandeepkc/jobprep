#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int partition(int *a, int l, int r) {
	int i = l;
	
	int p = a[r];

	for(int j = l; j < r; ++j) {
		if(a[j] < p) {
			swap(a, i, j);
			i++;
		}
	}

	swap(a, i, r);
	return i;
}
		
void quicksort(int *a, int l, int r) {
	if(l >= r)
		return;
	int p = partition(a, l, r);
	
	quicksort(a, l, p - 1); 
	quicksort(a, p + 1, r);
}

int main(void) {
	int a[] = {10, 65, 32, 43, 54, 2, 4, 5, 54, 76, 76, 89, 90};
	int size = (int)sizeof(a)/sizeof(int);

	quicksort(a, 0, size - 1);
	for(int i = 0; i < size; ++i) {
		cout<<a[i]<<" ";
	}
	return(0);
}
