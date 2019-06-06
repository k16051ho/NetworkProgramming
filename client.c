#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdio.h>
#define BUF_SIZE 256
#include<string.h>
#include<stdlib.h>

void DieWithError(char *erorMessage){
        perror(erorMessage);
        exit(1);
}

void commun(int sock) {
        char buf[BUF_SIZE];
        int len_r;
        char *message = "";
        if(send(sock, message, strlen(message), 0) != strlen(message))
                DieWithError("send()sent a message of unexpected bytes");
        if((len_r = recv(sock, buf, BUF_SIZE, 0)) <= 0)
                DieWithError("recv() failed");
        buf[len_r] = '\0';
        printf("%s\n", buf);
        if(send(sock, buf, strlen(buf), 0) != strlen(buf))
        DieWithError("send() sent a message of unexpected bytes");
}

int main(int argc, char **argv) {

        int cliSock;
        int servSock = socket(PF_INET, SOCK_STREAM, 0);
        struct sockaddr_in servAddress;
        struct sockaddr_in clientAddress;
        unsigned int szClientAddr;

        servAddress.sin_family = AF_INET;
        servAddress.sin_addr.s_addr = htonl(INADDR_ANY);
        servAddress.sin_port = htons(10001);
        bind(servSock, (struct sockaddr *)&servAddress, sizeof(servAddress));
        listen(servSock, 5);
        while(1){
                szClientAddr = sizeof(clientAddress);
                cliSock = accept(servSock, (struct sockaddr *)&clientAddress, &szClientAddr);
                commun(cliSock);
        }

        close(servSock);
        return 0;
}