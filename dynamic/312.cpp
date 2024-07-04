
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#include "utils.cpp"

int maxCoins(vector<int>& nums) {
    vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2));
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    for (int i = nums.size() - 2; i >= 0; i--) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i]*nums[j]*nums[k]);
            }
        }
    }
    return dp[0][dp.size()-1];
}

int main(){
    vector<int> nums = {3,1,5,8};
    cout << maxCoins(nums) << endl;
}