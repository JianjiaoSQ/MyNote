#include<iostream>
#include<stack>

using namespace std;

stack<int> stackSort(stack<int>& stk) {
    stack<int> tmp;

    while(!stk.empty()) {
        int stkNum = stk.top();
        stk.pop();

        while(!tmp.empty() && tmp.top() > stkNum) { // 需要进行交换
            int tmpNum = tmp.top();
            tmp.pop();
            stk.push(tmpNum);
        }
        tmp.push(stkNum);
    }
    return tmp;
}

int main() {
    stack<int> stk;
    stk.push(4);
    stk.push(2);
    stk.push(1);
    stk.push(3);
    int s = stk.size();
    /*
    for(int i = 0; i < s; ++i) {
        cout << "第" << 4-i << ": "<< stk.top() << endl;
        stk.pop();
    }*/

    stack<int> result = stackSort(stk);

    int res = result.size();
    for(int i = 0; i < res; ++i) {
        cout << result.top() << endl;
        result.pop();
    }

    return 0;
}