#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    //dp[i][0]not hold, sell in i or 
    //dp[i][1]hold, buy in anyday
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for(int i = 1; i < prices.size(); i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
    }
    return dp[prices.size()-1][0];
}
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;;
}