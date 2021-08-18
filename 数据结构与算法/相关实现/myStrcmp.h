#include <assert.h>

int myStrCmp(const char* str1, const char* str2) {
    assert(str1 && str2);

    while(*str1 == *str2 && *str1) {
        str1++;
        str2++;
    }

    if(*str1 == *str2) {
        return 0;
    }

    return *(unsigned char*)str1 > *(unsigned char*)str2 ? 1 : -1;
}