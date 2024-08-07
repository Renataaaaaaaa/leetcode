#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);

    dp[0] = 1;
    for (int i = 1; i < nums.size(); i++){
        for (int j = 0; j < i; j++){
            if (nums[j] < nums[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int main(){
    vector<int> data = {0,1,0,3,2,3};
    cout << lengthOfLIS(data) << endl;
}