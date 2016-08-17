#include<stdio.h>
#include<stdint.h>

/*
 * Returns 1 if the underlying architecture is little endian.
 * Returns 0 if the underlying architecture is big endian.
 */

int is_arch_little_endian(void) {
	union u{
		int16_t s;
		char c[sizeof(int16_t)];
	}; 

	union u u_instance;

	u_instance.s = 0x01;
	
	if(u_instance.c[0] == 1) {
		/*
 		 * Little endian would store '1' from '0x01' in the
 		 * lowest address whereas big endian would store
 		 * it in the highest address.
 		 */
		return (1);
	} else {
		return (0);
	}
}

int main() {
	if(is_arch_little_endian() == 1) {
		printf("Little endian.\n");
	} else {
		printf("Big endian.\n");
	}
	return (0);
}
