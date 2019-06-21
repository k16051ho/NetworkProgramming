#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>


#define BUF_SIZE 256

void DieWithError(char *errorMessage) {
	perror(errorMessage);
	exit(1);
}

void commun (int sock) {
	char buf[BUF_SIZE];
	int len_r;
	char *message = " ��";

	if ((len_r = recv(sock, buf, BUF_SIZE, 0)) <= 0)
		DieWithError(�grecv() failed�h);
	buf[len_r] = �e\0�f;
	printf( �g%s\n�h, buf );
	
	if (send(sock, message, strlen(message), 0) != strlen(message))
		DieWithError(�gsend() sent a message of unexpected bytes�h);
}

int main(int arg0, char **argv) {
	char buf[BUF_SIZE];
	int i;
	
	/***********************/
	/*  �N���C�A���g���̕ۑ��p  */
	/***********************/
	struct sockaddr_in clientAddress
	unsinged int szClientAddr;
	int cliSock;

	/***********************/
	/*  �҂��󂯃\�P�b�g�̍쐬  */
	/***********************/
	int servSock = socket(PF_INET, SOCK_STREAM, 0);

	/******************/
	/*  �}�V�����쐬  */
	/******************/
	struct sockaddr_in servAddress;

	servAddress.sin_family      = PF_INET;
	servAddress.sin_port        = (in_port_t)htons(80);  // �҂��󂯃\�P�b�g�̃|�[�g�ԍ�
	servAddress.sin_addr.s_addr = htonl(INADDR_ANY);        // �҂��󂯂邽�߂́i�����́jIP�A�h���X�i���i��INADDR_ANY�j

	/*********************************/
	/* �҂��󂯃\�P�b�g�Ƀ}�V���̏����Z�b�g  */
	/*********************************/
	bind(servSock, (struct sockaddr *)&servAddress, sizeof(servAddress));

	/********************/
	/*   �҂��󂯊J�n   */
	/********************/
	listen(servSock, 5);

	while(1) {
		szClientAddr = sizeof(clientAddress);
		cliSock = accept(servSock, (struct sockaddr *)&clientAddress, &szClientAddr);
		
		/****************/
		/* �@�@�ʐM�J�n    */
		/****************/
		
		commun(cliSock);

		close(cliSock);
	}

	/********************/
	/* �Ҏ�p�\�P�b�g�� */
	/* ����           */
	/********************/
	close(servSock);

	return 0;
}