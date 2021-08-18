#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
using namespace std;

mutex mtx;
int i = 0;
int j = 0;
condition_variable cv;
int flag = 0;

void print1()
{
    unique_lock<mutex> ul(mtx);
    while (true)
    {
        while (flag != 0)
            cv.wait(ul);
        flag = 1;  
        if (++i > 100) 
        {
            cv.notify_all();
            break;
        }      
        cout << this_thread::get_id() << ":" << i <<endl;     
        cv.notify_all();
    }
}

void print2()
{
    unique_lock<mutex> ul(mtx);
    while (true)
    {
        while (flag != 1)
            cv.wait(ul);
        flag = 2;   
        if (++i > 100) 
        {
            cv.notify_all();
            break;
        }      
        cout << this_thread::get_id() << ":" << i <<endl;    
        cv.notify_all();
    }
}

void print3()
{
    unique_lock<mutex> ul(mtx);
    while (true)
    {
        while (flag != 2)
            cv.wait(ul);
        flag = 0;   
        if (++i > 100) 
        {
            cv.notify_all();
            break;
        }         
        cout << this_thread::get_id() << ":" << i <<endl;    
        cv.notify_all();
    }
}


int main()
{
    cout << "print 100 by order abc" << endl;
    thread a(print1), b(print2), c(print3);
    a.join();
    b.join();
    c.join();

    return 0;
}

/*
run(ubuntu 20.04):
g++ <filename> -o run -lpthread
./run

output:
print 100 by order abc
140684544308992:1
140684535916288:2
140684527523584:3
140684544308992:4
140684535916288:5
140684527523584:6
140684544308992:7
140684535916288:8
140684527523584:9
140684544308992:10
140684535916288:11
140684527523584:12
140684544308992:13
140684535916288:14
140684527523584:15
140684544308992:16
140684535916288:17
140684527523584:18
140684544308992:19
140684535916288:20
140684527523584:21
140684544308992:22
140684535916288:23
140684527523584:24
140684544308992:25
140684535916288:26
140684527523584:27
140684544308992:28
140684535916288:29
140684527523584:30
140684544308992:31
140684535916288:32
140684527523584:33
140684544308992:34
140684535916288:35
140684527523584:36
140684544308992:37
140684535916288:38
140684527523584:39
140684544308992:40
140684535916288:41
140684527523584:42
140684544308992:43
140684535916288:44
140684527523584:45
140684544308992:46
140684535916288:47
140684527523584:48
140684544308992:49
140684535916288:50
140684527523584:51
140684544308992:52
140684535916288:53
140684527523584:54
140684544308992:55
140684535916288:56
140684527523584:57
140684544308992:58
140684535916288:59
140684527523584:60
140684544308992:61
140684535916288:62
140684527523584:63
140684544308992:64
140684535916288:65
140684527523584:66
140684544308992:67
140684535916288:68
140684527523584:69
140684544308992:70
140684535916288:71
140684527523584:72
140684544308992:73
140684535916288:74
140684527523584:75
140684544308992:76
140684535916288:77
140684527523584:78
140684544308992:79
140684535916288:80
140684527523584:81
140684544308992:82
140684535916288:83
140684527523584:84
140684544308992:85
140684535916288:86
140684527523584:87
140684544308992:88
140684535916288:89
140684527523584:90
140684544308992:91
140684535916288:92
140684527523584:93
140684544308992:94
140684535916288:95
140684527523584:96
140684544308992:97
140684535916288:98
140684527523584:99
140684544308992:100
*/
