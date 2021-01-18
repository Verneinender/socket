# socket
## Final goal
Create an instant messaging platform with socket
## Requirements
  1.  All codes wirte in C++ Style as much as possible

## Knowledges
### general 
![socket](Resource/Socket.png)
### socket(int domain, int type, int protocol)
### struct sockaddr_in
```c++
    struct sockaddr_in
    {
      short sin_family;/*Address family一般来说AF_INET（地址族）PF_INET（协议族）*/
 
      unsigned short sin_port;/*Port number(必须要采用网络数据格式,普通数字可以用htons()函数转换成网络数据格式的数字)*/
 
      struct in_addr sin_addr;/*IP address in network byte order（Internet address）*/
 
      unsigned char sin_zero[8];/*Same size as struct sockaddr没有实际意义,只是为了　跟SOCKADDR结构在内存中对齐*/
    }

    struct in_addr
    {
    in_addr_t  s_addr;  //32位的IP地址 
    };

    unsigned long ip = inet_addr("127.0.0.1");
    printf("%ld\n", ip);

    struct sockaddr
    {
    sa_family_t  sin_family;   //地址族（Address Family），也就是地址类型
    char         sa_data[14];  //IP地址和端口号
    };
 ```   
 ![sockaddr](Resource/sockaddr.jpeg)
### bind
```c++
 int bind(int sockfd, const struct sockaddr *addr , socklen_t addrlen);//windows
 int bind(int sock, struct sockaddr *addr, socklen_t addrlen);  //Linux
```
### connect()
```c++
int connect(int sock, struct sockaddr *serv_addr, socklen_t addrlen);  //Linux
int connect(SOCKET sock, const struct sockaddr *serv_addr, int addrlen);  //Windows
```



### write() and read()
```c++
ssize_t write(int fd, const void *buf, size_t nbytes);
ssize_t read(int fd, void *buf, size_t nbytes);
```
### listen() and accept()
```c++
int listen(int sock, int backlog);  //Linux
int listen(SOCKET sock, int backlog);  //Windows

int accept(int sock, struct sockaddr *addr, socklen_t *addrlen);  //Linux
SOCKET accept(SOCKET sock, struct sockaddr *addr, int *addrlen);  //Windows
```
`accept()` returns a new `socket`, which restores IP and Port of client socket, and sock is the socket of **server socket**

