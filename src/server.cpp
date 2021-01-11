#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include  <arpa/inet.h>
#include  <sys/socket.h>
#include  <netinet/in.h>

using namespace std;

int main()
{
    // First create a socket
    //int socket(int domain, int type, int protocol)
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 

    //bind socket with IP and Port
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr)); //initialize the address

    server_addr.sin_family = AF_INET; //IPV4

    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //IP Address

    server_addr.sin_port = htons(1234); //Port

   bind(server_socket, (const struct sockaddr_in*) &server_addr, sizeof(server_addr));//？？？

    //wait for request
    listen(server_socket, 20);

    //accept request from client
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);//???????
    int client_socket = accept(server_socket, (sockaddr*)&client_addr, &client_addr_size);//中间有问题








}