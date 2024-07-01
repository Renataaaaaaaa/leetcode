#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

//f(i, j) 从0...i放满j，j等于sum/2
//dp(i, j) = dp(i-1, j-nums[i]) || dp(i-1,j)
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0){
        return false;
    }
    sum = sum / 2;
    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false)); //dp[i][j] j是target num
    for (int i = 0; i < nums.size() + 1; i++){
        dp[i][0] = true;
    }
    for (int i = 1; i < nums.size() + 1; i++){
        for (int j = 1; j <= sum; j++){
            bool res = false;
            res |= dp[i-1][j];
            if (j >= nums[i-1]){
                res |= dp[i-1][j  - nums[i-1]];
            }
            dp[i][j] = res;
        }
    }
    return dp[nums.size()][sum];
}

int main(){
    vector<int> nums = {1,2,3,5};
    cout << canPartition(nums) << endl;
}