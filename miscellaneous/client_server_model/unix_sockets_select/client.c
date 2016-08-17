#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char *socket_path = "test_sock";

typedef struct str_thdata
{
	int thread_no;
} thdata;

void create_connect_write(void *ptr) {
	thdata *data;            
	data = (thdata *) ptr;  /* type cast to a pointer to thdata */

	struct sockaddr_un addr;
	char buf[100];
	int fd,rc;

	if ( (fd = socket(AF_UNIX, SOCK_SEQPACKET, 0)) == -1) {
		perror("socket error");
		exit(-1);
	}

	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);

	if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
		perror("connect error");
		exit(-1);
	}

	int count = 0;
	while(count<10) {
		sleep(1);
		sprintf(buf, "Client : %d, count: %d", data->thread_no, count); 
		count++;
		write(fd, buf, sizeof(buf));
	}

	pthread_exit(0);
}

int main(int argc, char *argv[]) {

	pthread_t thread[100];
	//pthread_t thread1, thread2, thread3, thread4, thread5;
	//pthread_t thread6;  /* thread variables */
	thdata data[100];
	//thdata data1, data2, data3, data4, data5;
	//thdata data6;         /* structs to be passed to threads */

	//data1.thread_no = 1;
	//data2.thread_no = 2;
	//data3.thread_no = 3;
	//data4.thread_no = 4;
	//data5.thread_no = 5;
	//data6.thread_no = 6;
	
	int i = 0;
	for(i = 0; i < 100;  i++) {
		data[i].thread_no = i;
	}
	
	for(i = 0; i < 100;  i++) {
		pthread_create (&thread[i], NULL, (void *) &create_connect_write, (void *) &data[i]);
	}

	/* create threads */    
	/*pthread_create (&thread1, NULL, (void *) &create_connect_write, (void *) &data1);
	pthread_create (&thread2, NULL, (void *) &create_connect_write, (void *) &data2);
	pthread_create (&thread3, NULL, (void *) &create_connect_write, (void *) &data3);
	pthread_create (&thread4, NULL, (void *) &create_connect_write, (void *) &data4);
	pthread_create (&thread5, NULL, (void *) &create_connect_write, (void *) &data5);
	pthread_create (&thread6, NULL, (void *) &create_connect_write, (void *) &data6);
	*/

	for(i = 0; i < 100;  i++) {
		pthread_join(thread[i], NULL);
	}
	
	/*pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(thread5, NULL);
	pthread_join(thread6, NULL);
	*/

	return (0);
}
