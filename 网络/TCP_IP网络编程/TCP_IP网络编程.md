# TCP/IP网络编程 - 阅读笔记

## 套接字与标准IO
---
### 标准IO的优缺点
**优点：** 具有良好的移植性；可以利用缓冲提高性能；

**缺点：** 不容易进行双向通信；有时候频繁的调用 fflush() 函数；需要以 FILE 结构体指针的形式返回文件描述符；

## 优于 select 的 epoll
---
### 基于 select IO 复用技术速度慢的原因
* 调用 select 函数后常见的针对所有文件描述符的循环语句；

  - 调用 select 函数后，并不是把发生变化的文件描述符单独集中到一起，而是通过观察作为监视对象的 fd_set 变量的变化，找出发生变化的文件描述符，因此无法避免针对所有监视对象的循环语句；
* 每次调用 select 函数时都需要向该函数传递监视对象信息；

  - 作为监视对象的 fd_set 变量会发生变化，所以调用 select 函数前应复制并保存原有信息，并在每次调用 select 函数时传递信息的监视对象信息；

分析：

提升性能的最大障碍就是**每次传递监视对象信息**，因为每次调用 select 函数时向操作系统传递监视对象信息，这将对程序造成很大的负担，而且无法通过优化代码来解决；

**为什么需要向操作系统传递监视对象信息？** 因为 select 函数与文件描述符有关，也就是监视套接字变化的函数，而套接字是由操作系统管理的，所以 select 函数绝对需要借助操作系统才能完成功能；

### epoll 

**优点：** 

无需编写以监视状态变化为目的的针对所有文件描述符的循环语句； 

调用对应于 select 函数的 epoll_wait 函数时无需每次传递监视对象信息；

**epoll 服务器端实现中需要的函数：**
* epoll_create：创建保存 epoll 文件描述符的空间；
* epoll_ctl：向空间注册并注销文件描述符；
* epoll_wait：与 select 函数类似，等待文件描述符发变化；

|select|epoll|
|:--:|:--:|
|为了保存监视对象文件，直接声明了 fd_set 变量|由操作系统负责保存监视对象文件描述符，epoll_create 向操作系统请求空间|
|添加删除文件描述符，需要 FD_SET、FD_CLR 函数|通过 epoll_ctl 函数请求操作系统完成|
|调用 select 函数等待文件描述符的变化|调用 epoll_wait 函数|
|通过 fd_set 变量查看监视对象的状态变化（发生事件与否）|通过结构体 epoll_event 将发上变化的（发生事件的）文件描述符单独集中到一起|

## 10多进程服务器端
---
### 创建进程
```cpp
#include <unistd.h>
pid_t fork(void);
```

### 僵尸进程
向exit函数传递到参数值和main函数的return语句返回的值都会传递给操作系统，而操作


## 多线程服务器端的实现
---
### 线程与进程
进程：在操作系统构成单独执行流的单位；

线程：在进程构成单独执行流的单位；

### 进程创建与运行
>POSIX Porttable Operating System Interface for Computer Environment 适用于计算机环境的可移植操作系统接口

```cpp
#include <pthread.h>
int pthread_create(pthread_t* restrict thread, const pthread_attr_t* restrict attr, void* (* start_routine)(void*), void* restrict arg);
```
<div align="center"> <img src="../pic/pthread_create.png" width="800"/> </div><br>

### 线程同步
线程同步用于解决线程访问顺序引发的问题；
* 互斥量，`Mutual Exclusion`的简写；
* 信号量，`Semaphore`的简写；

### 线程销毁
Linux 线程并不是在首次调用的线程main函数返回时自动销毁，所以需要加以明确；否则由线程线程创建的内存空间一致存在；
* 调用 pthread_join 函数，不仅会等待线程终止，还会引导线程销毁；但是该函数的问题是线程在终止前，调用该函数的线程将进入阻塞状态；
* pthread_detach 函数不会引起线程终止或者进入阻塞状态，可以通过该函数引导销毁线程创建的内存空间；注意的是：调用该函数之后不能再针对相应线程调用 pthread_join 函数；

```cpp
#include <pthread.h>
int pthread_detach(pthread_t thread);
```

