#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 256

void DieWithError(char *errorMessage){
    perror(errorMessage);
    exit(1);
}

void commun(int sock){
    char buf[BUF_SIZE];
    int len_r;
	
	
	/*while文中内容何をやっているか理解しておくこと。TEST！！！！！*/
	while((len_r=recv(sock,buf,BUF_SIZE,0))>0)/*空行が現れるまで*/)
	{
		buf[len_r] = '\0';
		
		printf("%s\n,buf");
		
		if (strstr(buf,"\r\n\r\n")){
			printf("received HTTP request.");
		break;
		}
	}
	
	if("len_r <= 0")
		DieWithError("received() failed.");
		printf("received HTTP Request./n");
		
	sprintf(response,"HTTP/1.1 200 OK\r\n");
if(send(sock,responce,strlen(response,0)!=s))
DieWithError("send() sent a message of unexpe)
	
/*
    	if((len_r=recv(sock,buf,BUF_SIZE,0))<=0)
        DieWithError("recv()failed");
    
    buf[len_r] = '\0';
    printf("%s\n",buf);
	}
*/

	/*↑メッセージの受信*/
	
    if((send(sock,buf,strlen(buf),0))!=strlen(buf))
        DieWithError("send()sent a message of unexpected bytes");
	/*↑メッセージの送信*/
}

int main(int argc, char **argv) {
    int servSock = socket(PF_INET,SOCK_STREAM,0);

    int cliSock;
    struct sockaddr_in clientAddress;
    unsigned int szClientAddr;

    struct sockaddr_in servAddress;
    servAddress.sin_family = AF_INET;
    servAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddress.sin_port = htons(80);
    bind(servSock,(struct sockaddr *)&servAddress,sizeof(servAddress));
    listen(servSock,5);
    while(1){
        szClientAddr = sizeof(clientAddress);
        cliSock = accept(servSock,(struct sockaddr*)&clientAddress,&szClientAddr);
        commun(cliSock);
    }
    close(servSock);
    return 0;
	
}
