#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
    //dp[i][0]not hold, sell in i or 
    //dp[i][1]hold, buy in anyday
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[0][2] = -prices[0];
    for(int i = 1; i < prices.size(); i++){
        //0未进行过交易 0
        //hold 购买过一次
        //hold 第二次购买
        //not hold 卖了第一次
        //not hold 卖了第二次
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        dp[i][2] = max(dp[i-1][2], dp[i-1][3] - prices[i]); //?

        dp[i][3] = max(dp[i-1][3], dp[i-1][1] + prices[i]);
        dp[i][4] = max(dp[i-1][4], dp[i-1][2] + prices[i]);
    }
    return max(dp[prices.size()-1][3], dp[prices.size()-1][4]);
}
int main(){
    vector<int> prices = {1,2,3,4,5};
    cout << maxProfit(prices) << endl;;
}