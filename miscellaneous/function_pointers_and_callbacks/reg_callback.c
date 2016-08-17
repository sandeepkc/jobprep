#include<stdio.h>
#include "reg_callback.h"

void register_callback(callback ptr_reg_callback) {
	printf("Inside register_callback.\n");
	
	(*ptr_reg_callback)();
}
