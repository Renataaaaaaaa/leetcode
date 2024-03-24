#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// f(i) = min j = 0...n-1 f(i - c_i) + 1
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for(int i = 1; i <= amount; i++){
        for (int j = 0; j < coins.size(); j++){
            if (coins[j] <= i){
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return (dp[dp.size() - 1] == amount + 1) ? -1 : dp[dp.size() - 1];
}
int main(){
    vector<int> data = {2};
    cout << coinChange(data, 3) << endl;
}