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
			int argcnt;
			char *argv[BUFSIZ];
			char *endp1, *endp2;
			char error_msg[] = "Invalid Format";
			strcpy(sbuf, rbuf);
			getargs(rbuf, &argcnt, argv);
			if(argcnt == 3) {
				int num1 = (int) strtol(argv[0], &endp1, 10);
				int num2 = (int) strtol(argv[2], &endp2, 10);
				char op = argv[1][0];
				if(*endp1 == '\0' && *endp2 == '\0') {
					int error, ans;
					char ans_str[BUFSIZ];
					switch(op) {
						case '+':
							ans = num1 + num2;
							break;
						case '-':
							ans = num1 - num2;
							break;
						case '*':
							ans = num1 * num2;
							break;
						case '/':
							ans = num1 / num2;
							break;
						case '%':
							ans = num1 % num2;
							break;
						default:
							strcpy(sbuf, "Invalid Opcode");
							error = 1;
					}
					if(!error) {
						sprintf(ans_str, " = %d", ans);
						strcat(sbuf, ans_str);
					}
				} else {
					strcpy(sbuf, "Invalid Number");
				}
			} else {
				strcpy(sbuf, "The number of arguments must be 3");
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
accepted connection from 127.0.0.1, port=62909
recv_msg:10 + 5
recv_msg:5 - 10
recv_msg:1024 * 1024
recv_msg:10 / 3
recv_msg:10 % 3
recv_msg:10
recv_msg:10 +
recv_msg:10 + 1 + 1
recv_msg:10 + a
recv_msg:a + 10
recv_msg:10+5
recv_msg:10 & 5
connection closed

Client
input = 10 + 5
recv = 10 + 5 = 15
input = 5 - 10
recv = 5 - 10 = -5
input = 1024 * 1024
recv = 1024 * 1024 = 1048576
input = 10 / 3
recv = 10 / 3 = 3
input = 10 % 3
recv = 10 % 3 = 1
input = 10
recv = The number of arguments must be 3
input = 10 +
recv = The number of arguments must be 3
input = 10 + 1 + 1
recv = The number of arguments must be 3
input = 10 + a
recv = Invalid Number
input = a + 10
recv = Invalid Number
input = 10+5
recv = The number of arguments must be 3
input = 10 & 5
recv = Invalid Opcode
input = exit
*/
