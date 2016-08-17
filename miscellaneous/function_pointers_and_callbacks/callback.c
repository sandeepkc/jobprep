#include<stdio.h>
#include "reg_callback.h"

void my_callback(void) {
	printf("Inside my callback.\n");
}

int main(void) {
	callback ptr_my_callback = my_callback;

	printf("This is a program demonstrating function callback.\n");

	register_callback(ptr_my_callback);

	return (0);
}
