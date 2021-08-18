# [**复原IP地址**](https://leetcode-cn.com/problems/restore-ip-addresses/ "leetcode-93")
## **题目：**
给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。
## **解析：**
* **首先，利用回溯法枚举每一种情况，如果符合要求，则push到输出中**
* **关于IP地址的要求：只能是数字，且<=255；数字不能出现前导0**
## **题解：**
```cpp
class Solution {
private:
    vector<string> result;

    void dfs(string &s,int index,int numNode) {
        if(numNode == 3) {
            if(isValid(s,index,s.size()-1)) result.push_back(s);
            else return;
        }
        for(int i = index;i < s.size();i++) {
            if(isValid(s,index,i)) {
                s.insert(s.begin()+i+1,'.');
                numNode++;
                dfs(s,i+2,numNode);  // 逗号插入之后多一位
                numNode--;
                s.erase(s.begin()+i+1);        
            }
            else break;
        }
    }
    bool isValid(string &s,int start,int end) {
        if(start > end) return false;
        if(s[start] == '0' && start != end) return false;
        int sum = 0;
        for(int i = start;i <= end;i++) {
            if(s[i] > '9' || s[i] < '0') {
                return false;
            }
            sum = sum*10 + s[i]-'0';
            if(sum > 255) return false;
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s,0,0);
        return result;
    }
};
```