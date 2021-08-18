**:fire: :fire: :fire:**
<br>

# **目录**
<!-- TOC -->

- [**目录**](#%E7%9B%AE%E5%BD%95)
    - [**1、斐波那契数列**](#1%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97)
    - [**2、数组中重复的数字**](#2%E6%95%B0%E7%BB%84%E4%B8%AD%E9%87%8D%E5%A4%8D%E7%9A%84%E6%95%B0%E5%AD%97)
    - [**3、二维数组中的查找**](#3%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9F%A5%E6%89%BE)
    - [**4、替换空格**](#4%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC)
    - [**5、反转链表**](#5%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8)
    - [**6、字符串中不重复的最长子串**](#6%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E4%B8%8D%E9%87%8D%E5%A4%8D%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%90%E4%B8%B2)
    - [**7、从尾到头打印链表**](#7%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8)
    - [**8、重建二叉树**](#8%E9%87%8D%E5%BB%BA%E4%BA%8C%E5%8F%89%E6%A0%91)
    - [**9、用两个栈实现队列**](#9%E7%94%A8%E4%B8%A4%E4%B8%AA%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97)
    - [**10、对称二叉树**](#10%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91)
    - [**11、平衡二叉树**](#11%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91)
    - [**12、二叉树的最大深度**](#12%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%A4%A7%E6%B7%B1%E5%BA%A6)
    - [**13、二叉搜索树中第 K 大节点**](#13%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%AC%AC-k-%E5%A4%A7%E8%8A%82%E7%82%B9)
    - [**14、合并两个有序链表**](#14%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E9%93%BE%E8%A1%A8)
    - [**15、二叉树的最近公共祖先**](#15%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88)
    - [**16、旋转数组的最小数字**](#16%E6%97%8B%E8%BD%AC%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%B0%8F%E6%95%B0%E5%AD%97)
    - [**17、矩阵中的路径**](#17%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E8%B7%AF%E5%BE%84)
    - [**18、机器人的运动范围**](#18%E6%9C%BA%E5%99%A8%E4%BA%BA%E7%9A%84%E8%BF%90%E5%8A%A8%E8%8C%83%E5%9B%B4)
    - [**19、剪绳子**<br>](#19%E5%89%AA%E7%BB%B3%E5%AD%90br)
    - [**20、打印从 1 到最大的 n 位数**](#20%E6%89%93%E5%8D%B0%E4%BB%8E-1-%E5%88%B0%E6%9C%80%E5%A4%A7%E7%9A%84-n-%E4%BD%8D%E6%95%B0)
    - [**21、字符串的排列**](#21%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%8E%92%E5%88%97)
    - [**22、链表中倒数第K个节点**](#22%E9%93%BE%E8%A1%A8%E4%B8%AD%E5%80%92%E6%95%B0%E7%AC%ACk%E4%B8%AA%E8%8A%82%E7%82%B9)
    - [****](#)

<!-- /TOC -->

<br>

## [**1、斐波那契数列**](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)
---
```cpp
class Solution {
public:
    long long fib(int n) {
        int sum[2] = {0,1};
        if(n < 2) return sum[n];

        long long numOne = 0;
        long long numTwo = 1;
        long long sumTemp = 0;
        for(int i = 2;i <= n;++i) {
        /* 对于 i++ 和 ++1 ，都可以达到 +1 的效果，但是 ++i 更加高效 */
            sumTemp = numOne + numTwo;

            numOne = numTwo % 1000000007;
            numTwo = sumTemp % 1000000007;
        }
        return sumTemp % 1000000007;
    }
};
```

## [**2、数组中重复的数字**](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)
---
**原地置换**
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& num) {
        int temp;
        for(int i = 0;i < num.size();i++) {
            while(num[i] != i) {  /* 如果下标与数值不相等，即位置不匹配*/
                if(num[i] == num[num[i]]) // 退出条件，如果另外一个数字与已经位置匹配的数值相等，即重复数字*/
                    return num[i];
                // 交换数字，使其位置与数字匹配
                swap(num[i],num[num[i]]);
                /*temp = num[i];
                num[i] = num[num[i]];
                num[num[i]] = temp;*/
            }
        }
        return -1; // 没有重复数字
    }
};
```
* 传入数组时，必须是同时传入数组的名称和大小，只传入名称在函数内求数组大小是 `NO WAY`
* `C++ swap()`函数是引用交换，因此效率高于值交换，在`Leetcode OJ`中，值交换会出现超时

## [**3、二维数组中的查找**](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)
**线性查找**
```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;

        int i = matrix.size()-1,j = 0;
        while(i >= 0 && j < matrix[0].size()) {
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};
```
* 以左下角或者右上角值为对比值均可
* 数组传入函数中、新建一个容器，不能直接用`=`赋值，也不能直接去调用其中的数值，会出现`null pointer`问题(初始化)
* 在这个题中，首先要判断矩阵是否为空，不为空时，才能调用数值计算 `matrix[0].size()` ;

## [**4、替换空格**](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/)
**字符串问题**：字符串查找算法、正则表达式算法、模式匹配、字符串的匹配算法`kmp`
```cpp
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0,strLength = s.length();
        if(!strLength) return s;
        for(char c:s) {
            if(c == ' ') ++count;
        }
        s.resize(2*count + strLength);

        for(int i = strLength-1,j = s.length()-1;i < j; i--,j--) {
            if(s[i] != ' ') s[j] = s[i];
            else {
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 2;  // -2是减掉多出的位置数
            }
        }
        return s;
    }
};
```
* 在`C++`中，`string`被设计成可修改的，因此这个算法就是根据这个特性，**原地置换**，特别注意的是，在最后遍历置换`' '`时，要从后往前遍历，反之则会出现覆盖，置换错误
* 现成`api:` `repleace/replaceAll、encodeURIComponent、split/join`

## [**5、反转链表**](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

**双指针法**
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head; /*这一步异常判断不用做，在while循环中可以判断并退出*/
        ListNode* cur = NULL;
        ListNode* pre = head;
        while(pre) {
            ListNode* t = pre->next;

            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return cur;
    }
};
```
* 设置两个指针，一前`pre`一后`cur`，前面的指针初始化为`head`节点，后面的指针为空，每一次将`pre`的下一个节点指向`cur`即可，当`pre`指向为空时，结束循环退出
* 每次 转换完链表指向后，将两个指针同时指向下一个节点，即同时前进一步

**递归法**
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        // 递归到最后一个节点
        ListNode* ret = reverseList(head->next); /* 在最后一次判空后，ret == head->next(尾节点)*/
        head->next->next = head;
        head->next = NULL;

        return ret; // 旧链表的尾节点即链表的头节点
    }
};
```
* 首先，相较于双指针等其他非递归方法，递归法 时间、空间开销较大
* 递归法的总体思路就是递归到尾节点，然后转换相邻两个节点之间的指向关系，根据退出条件不断递归退出，最后给尾节点`->next == NULL`;

## [**6、字符串中不重复的最长子串**](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/)
---
**滑动窗口**
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int s_size = s.size();
        int left = 0,right = 0,lengthest = 0;

        // for(;left < s_size;++left) { // 以左边界遍历整个字符串
        for(;left < strSize-length;++left) { // 左遍历,这样减少遍历
            while(right < s_size && chars.count(s[right]) == 0) {
                chars.insert(s[right]);
                lengthest = max(lengthest,right-left+1);
                ++right;
            }
            /* 当不满足while条件时，也即是容器中出现重复字符，不符合要求了，将最左边的字符删除，实现容器向前一步，匹配 ++left */
            chars.erase(s[left]);
        }
        return lengthest;
    }
};
```
* 对于这个滑动窗口方法，其中包含 **窗口滑动** 和 **哈希** ，另外也可以用 **动态规划** 和 **哈希** 实现；
* 时间复杂度 `O(n)`;

## [**7、从尾到头打印链表**](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)
---
**非栈非递归(暴力)**
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* node = head;
        int count = 0;
        while(node) {
            ++count;
            node = node->next;
        }
        vector<int> result(count);
        node = head;
        for(auto i = result.rbegin();i != result.rend();++i) {
            *i = node->val; // *iter 返回迭代器iter所指元素的引用
            node = node->next;
        }
        return result;
    }
};
```
* 其他方法包含：入栈出栈、递归法(空间时间开销特别大)、反转链表；其实递归法的本质也是一个栈，先进后出
* 利用vector的insert特性

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode* pre=head;
        while(pre){
            res.insert(res.begin(),pre->val);
            pre=pre->next;
        }
        return res;
    }
}; 
```

## [**8、重建二叉树**](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)
---
**递归**
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> index;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int preLeft,int preRight,
                int inLeft,int inRight) {
        if(preLeft > preRight) return nullptr;

        int preorderRoot = preLeft;
        int inorderRoot = index[preorder[preorderRoot]];
        TreeNode* root = new TreeNode(preorder[preorderRoot]);
        int sizeLeftSubTree = inorderRoot - inLeft;

        root->left = build(preorder,inorder,preLeft+1,preLeft+sizeLeftSubTree,inLeft,inorderRoot-1);
        root->right = build(preorder,inorder,preLeft+sizeLeftSubTree+1,preRight,inorderRoot+1,inRight);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int num = inorder.size();
        for(int i = 0;i < num;++i) {
            index[inorder[i]] = i;
        }
        return build(preorder,inorder,0,num-1,0,num-1);
    }
};
```
* 前序遍历：中左右；中序遍历：左中右；根据前序遍历首个元素时根节点来划分中序遍历数组；
* 对于迭代法，暂时没看懂，后面接着看

## [**9、用两个栈实现队列**](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)
---
* 本题的题意大概是：单词为具体操作，数组对应位置的值为返回值，新建队列、队尾增加都没有返回值，即时 `null` ，只有删除操作有返回值，有值则返回删除的值，没值则返回 `-1` ；
```cpp
class CQueue {
public:
    stack<int> stack1,stack2;
    CQueue() {

    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if(stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.empty()) {return -1;}
        else {
            auto head = stack2.top();
            stack2.pop();
            return head;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```
## [**10、对称二叉树**](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/)
---
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return compare(root->left,root->right);
    }
    bool compare(TreeNode* left,TreeNode* right) {
        if(left == NULL && right == NULL) return true;
        if((left != NULL && right == NULL) || (left == NULL && right != NULL)) return false;
        if(left->val != right->val) return false;

        return compare(left->left,right->right) && compare(left->right,right->left);
    }
};
```

## [**11、平衡二叉树**](https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/)
---
**递归：自低至上**
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root) {
        if(root == NULL) return 0;

        int leftHeight = getHeight(root->left);
        if(leftHeight == -1) return -1;
        else {
            int rightHeight = getHeight(root->right);
            if(rightHeight == -1) return -1;
            else return abs(leftHeight - rightHeight) > 1 ? -1 : 1+max(leftHeight,rightHeight);
        }
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};
```
**从顶到下**
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if(root == NULL) {return 0;}
        else {
            return max(height(root->left),height(root->right))+1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) { return true;}
        else {
            return abs(height(root->left)-height(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
```

## [**12、二叉树的最大深度**]()
---
**非递归**
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int sizeQue = que.size();
            while(sizeQue) {
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                sizeQue--;
            }
            depth++;
        }
        return depth;
    }
};
```

**递归**
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {return 0;}
        else {
            return max(maxDepth(root->left),maxDepth(root->right))+1;
        }
    }
};
```

* 此题与第11题是同一问题，第11题是此题 **关于深度、平衡树** 的进一步讨论
* 第12题的非递归解法又叫 **层序遍历** ，同样也是层序遍历的非递归解法

<br><br>

## [**13、二叉搜索树中第 `K` 大节点**](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/)
---
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    void inOrder(TreeNode* root) {
        if(root == NULL) return;

        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        inOrder(root);
        return res[res.size()-k];
    }
};
```
* 采用中序对二叉搜索树进行遍历，刚好是从小到大进行排列；
* 这种方法开销较大，需要对每一个节点进行遍历并要进行存储；

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int result,temp;
    void reverseInOrder(TreeNode* root) {
        if(root == NULL) return;

        reverseInOrder(root->right);
        if(temp == 0) return;
        if(--temp == 0) result = root->val;
        reverseInOrder(root->left);
    }
    int kthLargest(TreeNode* root, int k) {
        temp = k;
        reverseInOrder(root);
        return result;
    }
};
```

## [**14、合并两个有序链表**](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)
---
**递归**
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        } else if(l2 == NULL) {
            return l1;
        } else if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
```
**迭代**
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pHead = new ListNode(-1);
        ListNode* pre = pHead;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre ->next;
        }
        pre->next = l1 == NULL ? l2 :l1;
        return pHead->next;
    }
};
```

## [**15、二叉树的最近公共祖先**](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/)
---
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* leftSub = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSub = lowestCommonAncestor(root->right,p,q);
        if(leftSub == NULL) return rightSub;
        if(rightSub == NULL) return leftSub;
        return root;
    }
};
```
* 此解采用递归，还需进一步学习

## [**16、旋转数组的最小数字**](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)
---
**二分查找**
```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0,right = numbers.size()-1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(numbers[mid] < numbers[right]) {
                right = mid;
            } else if(numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else {
                int index = left;
                for(int i = index+1;i < right;i++) {
                    if(numbers[i] < numbers[index]) {
                        index = i;
                    }
                }
                return numbers[index];
            }   
        }
        return numbers[left];
    }
};
```
* 如果按照线性查找，时间复杂度为 `O(n)` ,采用二分法，时间复杂度降至 `O(logN)`

## [**17、矩阵中的路径**](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)
---
[`Leetcode` 单词搜索](https://leetcode-cn.com/problems/word-search/)<br>
**DFS + 剪枝 + 递归**
- 矩阵元素和目标字符不同或此元素已被访问，则应立即返回，称之为**可行性剪枝**
```cpp
class Solution {
public:
    int row,col;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size(),col = board[0].size();
        for(int i = 0;i < row;i++) {
            for(int j = 0;j < col;j++) {
                if(dfs(board,word,i,j,0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,string& word,int i,int j,int k) {
        if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[k]) {
            return false;
        }
        if(k == word.size()-1) {return true;}
        char temp = board[i][j];
        board[i][j] = '\0'; /*打标签的目的是防止走回头路*/
        bool res = dfs(board,word,i-1,j,k+1) || dfs(board,word,i+1,j,k+1) || dfs(board,word,i,j-1,k+1) || dfs(board,word,i,j+1,k+1);
        board[i][j] = temp; /*匹配不成功，复原字符，下一次路径也需要查询*/
        return res;
    }
};
```

## [**18、机器人的运动范围**](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)
----
```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> result(m,vector<bool>(n,0));
        return DFS(0,0,0,0,result,m,n,k);
    }
    int DFS(int i,int j,int sumI,int sumJ,vector<vector<bool>> &result,int m,int n,int k) {
        if(i >= m || j >= n || result[i][j] || sumI + sumJ > k) {
            return 0;
        }
        result[i][j] = true; // (i,j)格 能够达到
        return 1 + DFS(i+1,j,(i+1)%10 == 0 ? sumI-8 : sumI +1,sumJ,result,m,n,k) + DFS(i,j+1,sumI,(j+1)%10 == 0 ? sumJ-8 : sumJ+1,result,m,n,k);
    }
};
```
* 利用 **深度优先遍历** 和 **递归法** 实现；
* 解题整体思路: 从 `(0,0)` 点开始出发，分别 **向下** **向右** 递归遍历所有的格子，如果 符合终止条件，则退出；
* 剩下的格子中有 **非解** 和 **不可达解** ，整体结果就是不符合要求；
```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> result(m,vector<bool>(n,0));
        int sum = 0;
        queue<vector<int>> que;
        que.push({0,0,0,0});
        while(que.size()) {
            vector<int> temp = que.front();
            que.pop();
            int i = temp[0],j = temp[1],sumI = temp[2],sumJ = temp[3];
            if(i >= m || j >= n || sumI + sumJ > k || result[i][j]) {
                continue;
            }
            result[i][j] = true;
            sum++; // 计数
            que.push({i+1,j,(i+1)%10 == 0 ? sumI-8 : sumI+1,sumJ});
            que.push({i,j+1,sumI,(j+1)%10 == 0 ? sumJ-8 : sumJ+1});
        }
        return sum;
    }
};
```
* 本题解利用 **广度优先遍历** ，分别在每个点处 **向下** **向右** 遍历，符合条件进行标记和计数；
* 不符合条件时，`continue` 进入下一个循环；
* 对于 `continue & break` :
  - break 作用：用于终止当前循环<br>
	break 如果用于循环是用来终止循环，break只能终止距离它最近的循环<br>
	break如果用于switch，则是用于终止switch<br>
	break不能直接用于if中，除非if属于循环的一个句子，但此时它的作用是循环而不是if<br>
  - continue 作用：用以跳过本次循环余下的语句，转去判断是否需要执行下次循环<br>
	只作用于距离它最近的循环：for 、while 、do ...while<br>
	continue也不能直接用于if中，除非if属于循环的一个句子，同break，此时它的作用是循环而不是if<br>

## [**19、剪绳子**](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/)<br>
* [**整数拆分**](https://leetcode-cn.com/problems/integer-break/)
---
```cpp
class Solution {
public:
    int cuttingRope(int n) {
         if(n < 4) return n-1;
         int res = 1;
         if(n > 4) {
             while(n > 4) {
                 res *= 3;
                 n -= 3;
             }
         }
         return res * n;
    }
};
```
* **贪心算法** : [**分析过程**](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/)

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1);

        for(int i = 2;i < n+1;i++) {
            int curMax = 0;
            for(int j = 1;j < i;j++) {
                curMax = max(curMax,max(j * (i-j),j * dp[i-j]));
            }
            dp[i] = curMax;
        }      
        return dp[n];
    }
};
```
* 动态规划，难点在于转移方程的总结；

## [**20、打印从 `1` 到最大的 `n` 位数**](https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/)
---
```cpp
#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
    void print1toN(int n) {
        if(n <= 0) return;
        char* number = new char[n+1];
        number[n] = '\0';
        for(int i = 0;i < 10;i++) {
            number[0] = i + '0';
            Recursively(number,n,0);
        }
        delete[] number;
    }
private:
    void Recursively(char* number,int length,int index) {
        if(index == length-1) {
            print(number);
            return;
        }
        for(int i = 0;i < 10;i++) {
            number[index+1] = i + '0';
            Recursively(number,length,index+1);
        }
    }
    void print(char* number) {
        bool is0 = true;
        int length = strlen(number);
        for(int i = 0;i < length;++i) {
            if(is0 && number[i] != '0')
                is0 = false;
            if(!is0)
                cout << number[i];
        }
        if(!is0)
            cout << endl;
    }
};
int main() {
    Solution sol;
    sol.print1toN(2);
    return 0;
}
```
* 考虑大数情况，则应该利用字符串去打印大数，利用 **递归法** 实现 **全排列**

<br><br>

## [**21、字符串的排列**](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/)
---
```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s,0);
        return res;
    }
private:
    vector<string> res;
    void dfs(string& s,int index) {
        if(index == s.size()-1) {
            res.push_back(s);
            return;
        }
        set<char> st;
        for(int i = index; i < s.size(); ++i) {
            if(st.find(s[i]) != st.end()) continue;

            st.insert(s[i]);
            swap(s[i],s[index]);
            dfs(s,index+1);
            swap(s[i],s[index]);
        }
    }
};
```
* **回溯算法**，固定一个位置，依次和其他字符进行交换，输出之后，然后再交换，换回原位置；

## [**22、链表中倒数第K个节点**](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)
---
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == NULL) return NULL;

        ListNode* pre = head;
        for(int i = 1; i < k; ++i) {
            pre = pre->next;
        }
        ListNode* res = head;
        while(pre->next) {
            pre = pre->next;
            res = res->next;
        }
        return res;

    }
};
```

## [****]()
---
```cpp

```
