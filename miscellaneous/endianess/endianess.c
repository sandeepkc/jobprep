#include<stdio.h>

int main() {
	
	union u{
		short s;
		char c[sizeof(short)];
	}; 

	union u u_instance;

	u_instance.s = 1;
	
	if(u_instance.c[0] == 1) {
		printf("Little Endian\n");
	} else printf("Big Endian\n");

	return (0);
}
