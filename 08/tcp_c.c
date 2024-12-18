/*
 * tcp_c.c
 *
 * gcc -o c -lwsock32 tcp_c.c -lws2_32
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* only win */
#include <winsock2.h>
#include <ws2tcpip.h>

/* only linux */
// #include <netinet/in.h> 
// #include <sys/socket.h> 
// #include <netdb.h> 

int main(int argc,char *argv[])
{
	int fd;
	int real_rcvsize,real_sndsize;

	/* only linux */
	// in_port_t myport = 0; //rely OS
	// in_port_t srvport;

	/* only win */
	unsigned short myport = 0; //rely OS
	unsigned short srvport;

	struct sockaddr_in srvskt;//server
	struct hostent *srv_ent;
	struct sockaddr_in myskt;//client
	char rbuf[BUFSIZ];//receive buffer
	char sbuf[BUFSIZ];//send buffer
	socklen_t srv_sktlen;

	if(argc != 3){
		fprintf(stderr,"[Usage]:./a.out SRV_HOST_NAME SRV_PORT\n");
		exit(-1);
	}

	/* only win */
	WSADATA data;
	WSAStartup(MAKEWORD(2,0), &data);

	/* create socket */
	if((fd = socket(AF_INET,SOCK_STREAM,0)) < 0){
		perror("socket");
		exit(-1);
	}

	/* client addr */
	memset(&myskt,0,sizeof(myskt));
	myskt.sin_family = AF_INET;
	myskt.sin_addr.s_addr = htonl(INADDR_ANY);//client IP (rely OS)
	myskt.sin_port = htons(myport);//client port (rely OS)

	/* server addr */
	memset(&srvskt, 0, sizeof(srvskt));
	srvskt.sin_family = AF_INET;
	if((srv_ent = gethostbyname(argv[1])) == NULL){
		perror("gethostbyname");
		exit(-1);
	}
	memcpy((char *)&srvskt.sin_addr, srv_ent->h_addr, srv_ent->h_length);
	srvport = atoi(argv[2]);
	srvskt.sin_port = htons(srvport);
	srv_sktlen = sizeof(srvskt);

	if(connect(fd, (struct sockaddr *)&srvskt, srv_sktlen) < 0){
		perror("connect");
		exit(-1);
	}

	while(1){
		memset(rbuf, 0, sizeof(rbuf));
		memset(sbuf, 0, sizeof(sbuf));
		printf("input = ");
		fgets(sbuf, sizeof(sbuf), stdin);
		//delete '\n'
		char *p = strchr(sbuf, '\n');
		if(p) *p = '\0';

		if((real_sndsize = send(fd,sbuf,sizeof(sbuf),0)) < 0){
			perror("send");
			exit(-1);
		}
		if(strcmp(sbuf, "exit") == 0 || strcmp(sbuf, "quit") == 0){
			break;
		}
		if((real_rcvsize = recv(fd, rbuf, sizeof(rbuf), 0)) < 0){
			perror("recv");
			exit(-1);
		}
		printf("recv = %s\n",rbuf);
	}

	/* only win */
	closesocket(fd);
	WSACleanup();

	/* only linux */
	// close(fd);
}




