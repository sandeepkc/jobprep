#include<stdio.h>
#include <arpa/inet.h>

//16777343  is 1.0.0.127
//2130706433 is 127.0.0.1

void print_ip(uint32_t);

int main() {
	char *c = "127.0.0.1";

	FILE *fp;
	fp = fopen("data.txt", "r");
	char a[20];
	fscanf(fp, "%s", a);
	fclose(fp);
	
	uint32_t addr;
	inet_pton(AF_INET, c, &addr);
	printf("%x\n", addr);

	//printf("%x\n", addr & 0xFF);
	print_ip(addr);

	//inet_pton(AF_INET, a, &addr);
	//printf("%u\n", addr);

	uint32_t haddr = ntohl(addr);
	printf("%x\n", haddr);

	return (0);
} 

void
print_ip(uint32_t ip)
{
        printf("%d.%d.%d.%d\n",
            ip & 0x0FF,
            ip >>  8 & 0x0FF,
            ip >> 16 & 0x0FF,
            ip >> 24 & 0x0FF);
}

