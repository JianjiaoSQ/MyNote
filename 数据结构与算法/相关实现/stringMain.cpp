#include<iostream>
#include"myStrCpy.h"

using namespace std;

int main() {
    char ch[8] = "abdjfgj";
    char copy[3] = "";

    myStrCpy(copy,ch);
    cout << copy << endl;

    return 0;
}