#include<stdio.h>

int func(int, int);

int main(void)
{
	int result;

	int (*ptrFunc) (int, int);
	ptrFunc = func;
	
	result = (*ptrFunc)(10, 20);
	printf("result = %d\n", result);

	return (0);
}

int func(int a, int b) {
	return a + b;
}
