#include <assert.h>

void* myMemmove(void* dest, const void* src, size_t count) {
    assert(dest != nullptr && src != nullptr);

    if(dest < src) {
        char* p = (char*)dest;
        char* q = (char*)src;

        while(count--) {
            *p++ = *q++;
        }
    } else {
        char* p = (char*)dest + count;
        char* q = (char*)src + count;

        while(count--) {
            *--p = *--q;
        }
    }
    return dest;
}