#include <sys/stat.h>

#include <fcntl.h>

#include <errno.h>

#include <netdb.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <unistd.h>

#include "struct.h"

#include <iostream>
using namespace std;

#define SERVER_PORT 6666

/*
连接到服务器后，会不停循环，等待输入，
输入quit后，断开与服务器的连接
*/

int main()

{

    //客户端只需要一个套接字文件描述符，用于和服务器通信

    int clientSocket;

    //描述服务器的socket

    struct sockaddr_in serverAddr;

    char recvbuf[200];

    int iDataNum;

    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)

    {

        perror("socket");

        return 1;
    }

    serverAddr.sin_family = AF_INET;

    serverAddr.sin_port = htons(SERVER_PORT);

    //指定服务器端的ip，本地测试：127.0.0.1

    //inet_addr()函数，将点分十进制IP转换成网络字节序IP

    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)

    {

        perror("connect");

        return 1;
    }

    printf("连接到主机...\n");
    while (1)
    {

        // 发消息————————————————————————————————————————————————————————————————
        A *a;
        printf("发送消息:\n");
        printf("\n请依次输入i和j以及他们的操作【空格分开】(操作说明：1表示加，2表示乘)：");
        cin >> a->i >> a->j >> a->opt;
        void *sendbuf = (void *)a;
        printf("\n");
        send(clientSocket, sendbuf, 1024, 0);

        // 收消息————————————————————————————————————————————————————————————————
        printf("读取消息:");

        recvbuf[0] = '\0';

        iDataNum = recv(clientSocket, recvbuf, 200, 0);

        recvbuf[iDataNum] = '\0';

        printf("%s\n", recvbuf);
    }

    close(clientSocket);

    return 0;
}
