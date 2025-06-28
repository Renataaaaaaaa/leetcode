#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// f(i) = min j = 0...n-1 f(i - c_i) + 1
int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp (coins.size() + 1, vector<int>(amount + 1, INT32_MAX));
    for(int i = 1; i < coins.size() + 1; i++){
        dp[i][0] = 0;
    }
    for(int i = 1; i < coins.size() + 1; i++){
        for(int j = 1; j < amount + 1; j++){
            dp[i][j] = dp[i-1][j]; //不用i
            if (j >= coins[i-1]){
                dp[i][j] = min(dp[i][j], dp[i][j - coins[i-1]] + 1) ; //重点
            }
        }
    }
    return dp[coins.size()][amount];
}
int main(){
    vector<int> data = {1,2,5};
    cout << coinChange(data, 11) << endl;
}