#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;
//1 2 3 0 2
int maxProfit(vector<int>& prices){
    if (prices.size() == 0){
        return 0;
    }
    vector< vector<int > > dp (prices.size(), vector<int>(3, 0));
    //0 hold
    //1 not hold, cold down
    //2 not hold, not cold down
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 1; i < prices.size(); i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]); //from i - 1 or buy in i
        dp[i][1] = dp[i - 1][0] + prices[i]; //sell this day
        dp[i][2] = *max_element(dp[i - 1].begin(), dp[i-1].end()); //
    }
    return max(dp[dp.size()-1][1], dp[dp.size()-1][2]);
}
// int maxProfit(vector<int>& prices) {
//     vector< vector<int > > dp (prices.size(), vector<int>(prices.size(), 0));

//     for (int i = 0; i < prices.size(); i++){
//         dp[i][i] = 0;
//     }
//     int res = 0;
//     int i = 0; int j = 0;
//     for (int l = 2; l <= prices.size(); l++){
//         for (i = 0; i < prices.size() - l + 1; i++){
//             j = i + l - 1;
//             dp[i][j] = max(0, prices[j] - prices[i]);
//             for (int k = i; k < j; k++){
//                 cout << k << endl;
//                 dp[i][j] = max(dp[i][j], (k-1 >=0 ? dp[i][k-1] : 0) + (k + 1 < prices.size() ? dp[k + 1][j] : 0));
//             }
//             cout << "i " << " " << i << " j " << j << " " << dp[i][j] << endl;
//             res = max(res, dp[i][j]);
//         }
        
        
//     }
//     return res;
// }

int main(){
    vector<int> prices = {1,2,3,0,2};
    // vector<int> prices = {};
    cout << maxProfit(prices) << endl;
}