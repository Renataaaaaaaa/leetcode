#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0){
        return false;
    }
    vector<int> pack;
    for (int i = 1; i <= (sum / 2); i++){
        pack.push_back(i);
    }
    vector<vector<bool>> dp(nums.size(), vector<bool>(pack.size(), false)); //dp[i][j] j是target num
    for (int i = 0; i < nums.size(); i++){
        for (int j = 0; j < pack.size(); j++){
            bool res = false;
            res |= (i == 0 ? false : dp[i-1][j]);
            if (pack[j] - nums[i] >= 0){
                if (pack[j] - nums[i] == 0){
                    res |= true;
                }else{
                    res |= i == 0 ? false: dp[i-1][pack[j]  - nums[i] - 1];
                }
            }
            dp[i][j] = res;
        }
    }
    return dp[nums.size()-1][pack.size()-1];
}
