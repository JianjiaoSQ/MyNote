/* 字符串匹配算法：kmp算法
*/
#include<iostream>
#include<string>
using namespace std;

void getNext(int* next,string &s){
     int j = -1;
     next[0] = j;
     for(int i = 1;i < s.size();i++){
         while(j >= 0 && s[i] != s[j+1]){
             j = next[j];
         }
         if(s[i] == s[j+1]){
             j++; 
         }
         next[i] = j;
     }
}

bool kmp(string &mainString,string &sonString){
    if(sonString.size() == 0){
        cout << "搜索字符串为空";
        return false;
    }

    int next[sonString.size()];
    int j = -1;

    getNext(next,sonString);
    for(int i = 0;i < mainString.size();i++){
        while(j >= 0 && sonString[j+1] != mainString[i]){
            j = next[j];
        }
        if(sonString[j+1] == mainString[i]){
            j++;
        }
        if(j == sonString.size()-1){
            cout << "字符串匹配找到";
            return true;
        }
    }
    cout << "字符串匹配未找到";
    return false;
}

int main(){ 
    string txt = "abaab aaababaab aabbabb";
    string str = "babbab";  
    cout << "主串：" << txt << " || " << "匹配串：" << str << " || " << "匹配结果：";
    kmp(txt,str);
    /*
    int next[str.size()];
    getNext(next,str); 
    for(int i = 0;i < str.size();i++){ 
        cout << next[i] << "、";
    }  
    cout << endl;
    */
    return 0;
}