#include<iostream>
#include<vector>

using namespace std;

void solution() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {9, 20, 30};
    int bagWeight = 4;
    // ⼆维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
    // 初始化
    for (int j = bagWeight; j >= weight[0]; j--) {
        dp[0][j] = value[0];
    }
    // weight数组的⼤⼩ 就是物品个数
    for(int i = 1; i < weight.size(); i++) { // 遍历物品
        for(int j = 0; j <= bagWeight; j++) { // 遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    cout << dp[weight.size() - 1][bagWeight] << endl;
}

int main() {
    solution();
}