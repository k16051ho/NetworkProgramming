#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 256

#include <stdlib.h>
void DieWithError(char*errorMessage){
	perror(errorMessage);
	exit(1);
}
void commun(int sock)
{
	char buf[256];
	char buf[BUF_SIZE];
	int len_r;
	char*message = "BTS";
	send(sock,message,strlen(message),0);
	len_r=recv(sock,buf,256,0);
	buf[len_r]='\n';
	char*message = " TOM & JERRY ";
	if(send(sock,message,strlen(message),0) != strlen(message))

	DieWithError("send() sent a message of unexpected bytes");

	if((len_r = recv(sock,buf,BUF_SIZE,0))<0)
	/*0 の時はサーバーが正常終了、負の時はエラー（多分）*/
	DieWithError("recv()failed");

	buf[len_r] = '\0';
	printf("%s\n",buf);
}

int main (int argc,char**argv)
{

	if(argc != 3)
	DieWithError("arguments is not available");

	char*server_ipaddr = argv[1]; //"10.13.64.20";
	int server_port = atoi(argv[2]);

	int sock = socket(PF_INET,SOCK_STREAM,0);
	if(sock < 0)
	DieWithError("socket()failed");

	struct sockaddr_in target;

	target.sin_family=AF_INET;
	target.sin_addr.s_addr=inet_addr("10.13.64.20");
	target.sin_port=htons(10001);
	target.sin_family = AF_INET;
	target.sin_addr.s_addr = inet_addr("server_ipaddr");
	target.sin_port = htons(server_port);

	/* printf("sock is %d \n",sock); */

	connect(sock,(struct sockaddr*)&target,sizeof(target));
	if(connect(sock,(struct sockaddr*)&target,sizeof(target))<0)
		DieWithError("connect()failed");


	commun(sock);

