#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;
int main()
{
    //create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    //make a request to specific IP and Port
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr)); // initialize
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //IP address
    serv_addr.sin_port = htons(1234);//port
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    //read data
    //char buffer[100];
    char bufSend[100]= {0};
    std::cout<<"Please input a message: "<<endl;
    std::cin>>bufSend;

    write(sock, bufSend, sizeof(bufSend));

    //reveive data from server
    char bufRecv[100] = {0};
    read(sock, bufRecv, sizeof(bufRecv));

    std::cout<<"Message form server is: "<<bufRecv<<std::endl;

    //close socket
    close(sock);
    return 0;

}
