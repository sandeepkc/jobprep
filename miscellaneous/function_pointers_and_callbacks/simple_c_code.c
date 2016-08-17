#include<stdio.h>

int func(int, int);

int main(void)
{
	int result;
	
	result = func(10, 20);
	printf("result = %d\n", result);

	return (0);
}

int func(int a, int b) {
	return a + b;
}
