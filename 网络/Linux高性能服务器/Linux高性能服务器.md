# Linux 高性能服务器编程

<!-- TOC -->

- [Linux 高性能服务器编程](#linux-%E9%AB%98%E6%80%A7%E8%83%BD%E6%9C%8D%E5%8A%A1%E5%99%A8%E7%BC%96%E7%A8%8B)
    - [网络编程常用函数](#%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%B8%B8%E7%94%A8%E5%87%BD%E6%95%B0)
        - [创建 socket](#%E5%88%9B%E5%BB%BA-socket)
        - [命名 socket](#%E5%91%BD%E5%90%8D-socket)
        - [监听 socket](#%E7%9B%91%E5%90%AC-socket)
        - [接受连接](#%E6%8E%A5%E5%8F%97%E8%BF%9E%E6%8E%A5)
        - [发起连接](#%E5%8F%91%E8%B5%B7%E8%BF%9E%E6%8E%A5)
        - [关闭连接](#%E5%85%B3%E9%97%AD%E8%BF%9E%E6%8E%A5)
        - [TCP 数据读写](#tcp-%E6%95%B0%E6%8D%AE%E8%AF%BB%E5%86%99)
        - [管道](#%E7%AE%A1%E9%81%93)
        - [sendfile 函数](#sendfile-%E5%87%BD%E6%95%B0)
        - [mmap 函数与 munmap 函数](#mmap-%E5%87%BD%E6%95%B0%E4%B8%8E-munmap-%E5%87%BD%E6%95%B0)
        - [fcntl 函数](#fcntl-%E5%87%BD%E6%95%B0)
        - [内核事件表](#%E5%86%85%E6%A0%B8%E4%BA%8B%E4%BB%B6%E8%A1%A8)
    - [IO 复用区别](#io-%E5%A4%8D%E7%94%A8%E5%8C%BA%E5%88%AB)
    - [线程](#%E7%BA%BF%E7%A8%8B)
        - [创建线程](#%E5%88%9B%E5%BB%BA%E7%BA%BF%E7%A8%8B)
        - [获取线程ID](#%E8%8E%B7%E5%8F%96%E7%BA%BF%E7%A8%8Bid)
        - [等待线程结束](#%E7%AD%89%E5%BE%85%E7%BA%BF%E7%A8%8B%E7%BB%93%E6%9D%9F)
        - [结束线程](#%E7%BB%93%E6%9D%9F%E7%BA%BF%E7%A8%8B)
        - [分离线程](#%E5%88%86%E7%A6%BB%E7%BA%BF%E7%A8%8B)
        - [线程同步机制](#%E7%BA%BF%E7%A8%8B%E5%90%8C%E6%AD%A5%E6%9C%BA%E5%88%B6)

<!-- /TOC -->


## 网络编程常用函数
### 创建 socket
socket 就是一个可读、可写、可控制、可关闭的文件描述符；
```cpp
#include <sys/types.h>
#include <sys/socket.h>
int socket( int domain, int type, int protocal);
```
* domian : PF_INET 表示 TCP/IP 协议族；
* type : SOCK_STREAM 表示流服务，SOCK_UGRAM 表示数据报服务；也可以加入与 SOCK_NONBLOCK 相与的值，表示创建的  socket 为非阻塞的；
* 通常设置为 0 ，表示使用默认协议；

```cpp
int fd = socket(PF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
```

### 命名 socket
```cpp
#include <sys/types.h>
#include <sys/socket.h>
int bind( int sockfd, const struct sockaddr* my_addr, socklen_t addrlen);
```
* bind 将 my_addr 所指的 socket 地址分配给未命名的 sockfd 文件描述符，addrlen 表示该 socket 地址的长度；
* bind 成功时返回 0 ，失败返回 -1 并设置 errno；
  - EACCES : 被绑定的地址是受保护的地址；
  - EADDRINUSE : 被绑定的地址正在使用中；

### 监听 socket
```cpp
#include <sys/socket.h>
int listen( int sockfd, int backlog);
```
* backlog 表示处于完全连接状态的 socket 的上限；参数典型值为 5 ；

### 接受连接
```cpp
#include <sys/types.h>
#include <sys/socket.h>
int accept( int sockfd, struct sockaddr* addr, socklen_t* addrlen);
```

### 发起连接
```cpp
#include <sys/types.h>
#include <sys/socket.h>
int connect( int sockfd, const struct sockaddr* serv_addr, socklen_t addrlen);
```
* 客户端主动发起连接；
* sockfd 参数由 socket 系统调用返回一个 socket；
* serv_addr 参数是服务器监听的 socket 地址；

### 关闭连接
```cpp
#include <unistd.h>
int close( int fd);
```
* 并非立即关闭连接，而是将 fd 的引用计数 -1；当引用计数为 0 时，才真正关闭连接；

### TCP 数据读写
```cpp
#include <sys/types.h>
#include <sys/socket.h>
ssize_t recv( int sockfd, void* buf, size_t len, int flags);
ssize_t send( int sockfd, const void* buf, size_t len, int flags);
```
* recv 读物 sockfd 上的数据，buf 和 len 参数分别表示读缓冲区的位置和大小，flags 参数通常为 0 ；成功返回实际读取到的数据的长度；
* send 往 sockfd 上写入数据，buf 和 len 参数分别指定写缓冲区的位置和大小；send 成功返回实际写入数据的长度；

### 管道
```cpp
#include <unistd.h>
int pipe( int fd[2]);
```
* fd[0] 表示读端，fd[1]表示写端；管道内部传输的数据是字节流；

双向数据传输
```cpp
#include <sys/types.h>
#include <sys/socket.h>
int socketpair( int domain, int type, int protocal, int fd[2]);
```
* domain 只能使用 UNIX 本地协议族 AF_UNIX；

### sendfile 函数
```cpp
#include <sys/sendfile.h>
ssize_t sendfile( int out_fd, int in_fd, off_t* offest, size_t count);
```
* 两个文件描述符之间直接传输数据（完全在内核中操作），避免了内核缓冲区和用户缓冲区之间数据拷贝，这就是零拷贝；

### mmap 函数与 munmap 函数
```cpp
#include <sys/mman.h>
void* mmap( void* start, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void* start, size_t length);
```
* start 参数这段内存的起始地址，如果设置成 NULL，系统自动分配一个地址；
* length 参数指定内存段的长度；
* prot 参数用来设置内存段的访问权限；
  - PROT_READ，内存段可读；
  - PROT_WRITE，内存段可写；
  - PROT_EXEC，内存段可执行；
  - PROT_NONE，内存段不能被访问；
* fd 参数是被映射文件对应的文件描述符，一般通过打开 open 系统调用获得；
* mmap 函数成功时返回指向目标内存区域的指针；

### fcntl 函数
```cpp
#include <fcntl.h>
int fcntl( int fd, int cmd, ...);
```
* 提供对文件描述符的各种控制操作；
* 常用来将一个文件描述符设置为非阻塞的； 

### 内核事件表
```cpp
#include <sys/epoll.h>
int epoll_create( int size);
```
* 该函数返回的文件描述符将用作其他所有 epoll 系统调用的第一个参数，以指定要访问的内核事件表；

```cpp
#include <sys/epoll.h>
int epoll_ctl( int epfd, int op, int fd, struct epoll_event* event);
```
* event 参数指定事件，epoll_event 结构指针类型；

```cpp
#include <sys/epoll.h>
int epoll_wait( int epfd, struct epoll_event* events, int maxevents, int timeout);
```
* 该函数返回时返回就绪的文件描述符的个数，失败时返回 -1 并设置 errno；
* maxevents 参数指定最多监听多少个事件；

---
## IO 复用区别

<div align = center> <img src="../网络/pic/io复用区别.png" width="700"></div>

---
## 线程

### 创建线程
```cpp
#include <pthread.h>
int pthread_create( pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg);
```
* thread 参数是新线程的标识符，pthread_*函数通过它来引用新线程；
* attr 参数用于设置新线程的属性，传递 NULL 表示使用默认线程属性；
* start_routine 和 arg 参数分别指定新线程将运行的函数及其参数；

### 获取线程ID
```cpp
pthread_t pthread_self();
```

### 等待线程结束
```cpp
int pthread_join(pthread_t tid, void** retval);
```
* 主线程调用，等待子线程退出并回收其资源，类似于进程中wait/waitpid回收僵尸进程，调用pthread_join的线程会被阻塞。
* tid：创建线程时通过指针得到tid值。
* retval：指向返回值的指针。

### 结束线程
```cpp
#include <pthread.h>
void pthread_exit( void* retval);
```
* 确保安全、干净的退出；

### 分离线程
```cpp
int pthread_detach(pthread_t tid);
```
* 主线程、子线程均可调用。主线程中pthread_detach(tid)，子线程中pthread_detach(pthread_self())，调用后和主线程分离，子线程结束时自己立即回收资源。

### 线程同步机制
* `POSIX` 信号量、互斥量和条件变量
* 信号量
```cpp
#include<semaphore.h>
int sem_init(sem_t* sem,int pshared,unsigned int value);
int sem_destroy(sem_t* sem);
int sem_wait(sem_t* sem);
int sem_trywait(sem_t* sem);
int sem_post(sem_t* sem);
```
* 互斥量(互斥锁)
  - 用于同步线程对共享数据的访问；

* 条件变量
  - 用于在线程之间同步共享数据的值；


