#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>

char *socket_path = "\0hidden";

typedef void (*callback)(int);

void callback_func1(int value) {
	printf("Inside callback_func1. Value = %d\n", value);
}

void callback_func2(int value) {
	printf("Inside callback_func2. Value = %d\n", value);
}

void callback_func3(int value) {
	printf("Inside callback_func3. Value = %d\n", value);
}

void callback_func4(int value) {
	printf("Inside callback_func4. Value = %d\n", value);
}

void callback_func5(int value) {
	printf("Inside callback_func5. Value = %d\n", value);
}

void register_callback(callback ptr_reg_callback, int value) {
	(*ptr_reg_callback)(value);
}

int main(int argc, char *argv[]) {
	struct sockaddr_un addr;
	char buf[100];
	int fd,cl,rc;

	if (argc > 1) {
		//If given a path as an argument, use that
		socket_path=argv[1];
	}
	
	/*
 	 * 	int socket(int domain, int type, int protocol);
	 *
	 *	AF_UNIX 	- local communication
	 *	SOCK_STREAM 	- sequenced, reliable, two-way, connection based byte-stream 
	 *	0 		- default protocol
	 */
	
	if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		perror("socket error");
		exit(-1);
	}

	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);

	unlink(socket_path);

	if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
		perror("bind error");
		exit(-1);
	}

	//5 - backlog - limit for number of connections on a socket 
	
	if (listen(fd, 5) == -1) {
		perror("listen error");
		exit(-1);
	}

	int flag = 1;
	int type = 0;
	int value = 0;

	struct {
		callback ptr_my_callback;
	} callback_struct[5];

	callback_struct[0].ptr_my_callback = callback_func1;
	callback_struct[1].ptr_my_callback = callback_func2;
	callback_struct[2].ptr_my_callback = callback_func3;
	callback_struct[3].ptr_my_callback = callback_func4;
	callback_struct[4].ptr_my_callback = callback_func5;

	while (1) {
		if ( (cl = accept(fd, NULL, NULL)) == -1) {
			perror("accept error");
			continue;
		}

		while ( (rc=read(cl,buf,sizeof(buf))) > 0) {
			if(flag == 1) {
				type = atoi(buf);
				flag = 0;
			}
			else {
				value = atoi(buf);
				flag = 1;
			}

			if(flag == 1) {
				register_callback(callback_struct[type].ptr_my_callback, value);
			}
		}
		if (rc == -1) {
			perror("read");
			exit(-1);
		}
		else if (rc == 0) {
			printf("EOF\n");
			close(cl);
		}
	}
	return 0;
}
