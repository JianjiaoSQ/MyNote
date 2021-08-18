#include <assert.h>

char* myStrCat(char* strDest, const char* strSrc) {
    assert(strDest && strSrc);

    char* p = strDest;
    while(*p) p++;

    while(*p++ = *strSrc++)
    return strDest;
}