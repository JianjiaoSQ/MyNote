#include<iostream>
#include<assert.h>

char* myStrCpy(char* strDesk,const char* strSrc) {
    assert((strDesk != NULL) && (strSrc != NULL));

    char* strDeskCopy = strDesk;
    while((*strDesk++ = *strSrc++) != '\0');

    return strDeskCopy;
}