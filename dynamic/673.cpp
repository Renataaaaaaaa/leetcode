#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    if (nums.size() == 1){
        return 1;
    }
    vector<int> dp(nums.size(), 1);
    vector<int> dp_n(nums.size(), 1);
    int length = INT32_MIN;
    for (int i = 1; i < nums.size(); i++){
        for (int j = 0; j < i; j++){
            if (nums[j] < nums[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        bool first = true;
        for (int j = 0; j < i; j++){
            if (nums[j] < nums[i] && dp[j] + 1 == dp[i]){
                if (!first){
                    dp_n[i] += dp_n[j];
                }else{
                    dp_n[i] += (dp_n[j] - 1);
                }
                first = false;
            }
        }
        length = max(length, dp[i]);
        cout << i << " " << dp_n[i] << endl;
    }
    int res = 0;
    for (int i = 0 ; i < dp_n.size(); i++){
        if (dp[i] == length){
            res += dp_n[i];
        }
    }
    return res;
}

int main(){
    // vector<int> nums = {1,3,5,4,7};
    // vector<int> nums = {2,2,2,2,2};
    // vector<int> nums = {1,2,4,3,5,4,7,2};
    vector<int> nums = {1,1,1,2,2,2,3,3,3};
    cout << findNumberOfLIS(nums) << endl;
}