#include <iostream>
#include <assert.h>

// 迭代
int myStrLen1(const char* str) {
    assert(str);

    int len = 0;
    while(*str++) {
        ++len;
    }

    return len;   
}

// 递归
int myStrLen2(const char* str) {
    assert(str);

    return (*str == 0) ? 0 : 1 + myStrLen2(str+1);
}