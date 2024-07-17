
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

//
// int count_res = 0;
// void backtrack(vector<int>& nums, int target, int index, int sum) {
//     if (index == nums.size()) {
//         if (sum == target) {
//             count_res++;
//         }
//     } else {
//         backtrack(nums, target, index + 1, sum + nums[index]);
//         backtrack(nums, target, index + 1, sum - nums[index]);
//     }
// }


int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 != 0 || target > sum || target < (-sum)){
        return 0;
    }
    int target_p = (sum + target) / 2;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target_p + 1, 0));
    for(int i = 0; i < nums.size() + 1; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i < nums.size() + 1; i++){
        for(int j = 0; j < target_p + 1; j++){
            dp[i][j] = dp[i-1][j];
            if (j - nums[i-1] >= 0){
                dp[i][j] +=  dp[i-1][j - nums[i-1]];
            }
        }
    }
    return dp[nums.size()][target_p];
}

int main(){
    vector<int> nums = {1,1,1,1,1};
    cout << findTargetSumWays(nums, 3) << endl;
}
