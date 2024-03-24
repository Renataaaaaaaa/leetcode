#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {

    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= target; i++){
        for (int j = 0; j < nums.size(); j++){
            if (nums[j] <= i){
                dp[i] += dp[i - nums[j]];
            }
        }
        
    }
    if (dp[dp.size() - 1] == 0){
        return 0;
    }else{
        return dp[dp.size() - 1];
    }
}
