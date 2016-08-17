#include<stdio.h>

int main(void) {
	FILE *fp;
	fp = fopen("print_self.c", "r");

	if(fp == NULL) {
		printf("Error opening file.\n");
		return(-1);
	}

	char ch = '\0';
	while(fscanf(fp, "%c", &ch) != EOF) {
		printf("%c", ch);
	}

	fclose(fp);
	return(0);
}
