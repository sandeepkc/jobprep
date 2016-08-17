#include <stdio.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/un.h>
#include <stdlib.h>

char *socket_path = "test_sock";

int main(int argc, char *argv[]) {
	struct sockaddr_un addr;
	char buf[100];
	int fd,cl,rc;
	fd_set rd_set;

	/*
 	 * 	int socket(int domain, int type, int protocol);
	 *
	 *	AF_UNIX 	- local communication
	 *	SOCK_STREAM 	- sequenced, reliable, two-way, connection based byte-stream 
	 *	0 		- default protocol
	 */
	
	if ( (fd = socket(AF_UNIX, SOCK_SEQPACKET, 0)) == -1) {
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

	if (listen(fd, 5) == -1) {
		perror("listen error");
		exit(-1);
	}

	FD_ZERO(&rd_set);
	FD_SET(fd, &rd_set);

	while (1) {
		if ( (cl = select(fd + 1, &rd_set, NULL, NULL, NULL)) == -1) {
			perror("select error");
			continue;
		}

		if ( (cl = accept(fd, NULL, NULL)) == -1) {
			perror("accept error");
			continue;
		}

		while ( (rc=read(cl,buf,sizeof(buf))) > 0) {
			printf("Read: %s\n", buf);
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
