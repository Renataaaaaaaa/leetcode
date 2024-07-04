#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    vector<int> count(nums.size(), 1);
    // dp[0] = 1;
    // count[0] = 1;
    int max_length = 1;
    int res = 1;
    for (int i = 1; i < nums.size(); i++){
        for (int j = 0; j < i; j++){
            if (nums[j] < nums[i]){
                if (dp[j] + 1 == dp[i]){ //another possiblity
                    count[i] += count[j];
                }else if (dp[j] + 1 > dp[i]){
                    count[i] = count[j];
                }
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        cout << "i " << dp[i] << endl;
        if (dp[i] > max_length){
            res = count[i];
        }else if (dp[i] == max_length){
            res += count[i];
        }
        max_length = max(max_length, dp[i]);
    }
    return res;

}

int main(){
    vector<int> nums = {1,2,4,3,5,4,7,2};
    cout << findNumberOfLIS(nums) << endl;
}