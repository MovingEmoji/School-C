//Naoya Iida
/*
 * tcp_s.c
 *
 * >gcc -o s -lwsock32 tcp_s.c -lws2_32
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

#define MAX_QUEUE 5
#define MYPORT 10000

void getargs(char *cp, int *argc, char **argv) {
	*argc = 0;
	argv[*argc] = NULL;
	loop:
	while (*cp && isblank(*cp)) //skip space and tab
		cp++;
	if (*cp == '\0') {
		argv[(*argc)] = NULL;
		return;
	}
	argv[(*argc)++] = cp;
	while (*cp && !isblank(*cp)) //search for end of word
		cp++;
	if(*cp == '\0'){
		argv[(*argc)] = NULL;
		return;
	}
	*cp++ = '\0';
	goto loop;
}


int main(int argc,char *argv[])
{
	int fd, new_fd;
	int real_rcvsize,real_sndsize;
	// in_port_t myport = MYPORT; //only linux
	unsigned short myport = MYPORT; //only win
	struct sockaddr_in myskt;//server
	struct sockaddr_in cliskt;//client
	char rbuf[BUFSIZ];//receive buffer
	char sbuf[BUFSIZ];//send buffer
	socklen_t cli_sktlen;

	/* only win */
	WSADATA data;
	WSAStartup(MAKEWORD(2,0), &data); 

	if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(-1);
	}

	//srv addr
	memset(&myskt, 0, sizeof(myskt));
	myskt.sin_family = AF_INET;
	myskt.sin_port = htons(myport);
	myskt.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(fd, (struct sockaddr *)&myskt, sizeof(myskt)) < 0 ){
		perror("bind");
		exit(-1);
	}

	if(listen(fd, MAX_QUEUE) < 0){
		perror("listen");
		exit(-1);
	}

	cli_sktlen = sizeof(cliskt);
	printf("Server Start\n");
	while(1){
		if((new_fd = accept(fd, (struct sockaddr *)&cliskt, &cli_sktlen)) < 0){
			perror("accept");
			break;
		}
		printf("accepted connection from %s, port=%d\n", inet_ntoa(cliskt.sin_addr), ntohs(cliskt.sin_port));

		memset(rbuf, 0, sizeof(rbuf));
		memset(sbuf, 0, sizeof(sbuf));
		while(1){
			if((real_rcvsize = recv(new_fd, rbuf, sizeof(rbuf), 0)) < 0){
				perror("recv");
				break;
			}
			if(strcmp(rbuf, "exit") == 0 || strcmp(rbuf, "quit") == 0) {
				break;
			}
			printf("recv_msg:%s\n",rbuf);
			int i, argcnt;
			char *argv[BUFSIZ];
			char *endp;
			char error_msg[] = "Invalid Format";
			getargs(rbuf, &argcnt, argv);
			strcpy(sbuf, argv[0]);
			int endcnt = (int) strtol(argv[1], &endp, 10);
			if(argcnt == 2) {
				if(*endp == '\0') {
					int buf_size = sizeof(char) * strlen(argv[0]) + sizeof(char) * strlen("_SRV") * endcnt + 1;
					if(buf_size <= BUFSIZ) {
						for(i = 0; i < endcnt; i++) {
							strcat(sbuf, "_SERV");
						}
					} else {
						strcpy(sbuf, "Too long message");
					}
				} else {
					strcpy(sbuf, error_msg);
				}
			} else {
				strcpy(sbuf, error_msg);
			}
			if((real_sndsize = send(new_fd, sbuf, sizeof(sbuf), 0)) < 0){
				perror("send");
				break;
			}
		}
		// close(new_fd); //only linux
		closesocket(new_fd); //only win
		printf("connection closed\n");
	}
	/* only win */
	closesocket(fd);
	WSACleanup();
	printf("Server End\n");
}
/*
Server
Server Start
accepted connection from 127.0.0.1, port=62285
recv_msg:hello 126
recv_msg:hello 127
recv_msg:abc 100000
connection closed

Client
input = hello 126
recv = hello_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_SERV_S
input = hello 127
recv = Too long message
input = abc 100000
recv = Too long message
input = exit
*/
