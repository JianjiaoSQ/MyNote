#include <assert.h>

void* myMemcpy(void* dest, const void* src, size_t count) {
    assert(dest != NULL || src != NULL);

    char* tmp = (char*)dest;
    char* p = (char*)src;

    while(count--) {
        *tmp++ = *p++;
    }
    return dest;
}