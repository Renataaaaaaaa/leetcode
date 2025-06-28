#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#include "utils.cpp"


int minCapability(vector<int>& nums, int k) {
    vector<vector<int>> dp(nums.size() + 1, vector<int>(k + 1, INT32_MAX));
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < k; j++){
            if (j == 0){
                dp[i][j] = 0;
            }else{
                dp[i][j] = min(max(dp[i-2][j-1], nums[i]), dp[i-1][j]);
            }
            
        }
    }
    int res = 0;
    for(int i = 0; i < nums.size(); i++){
        res = min(res, dp[i][k-1]);
    }
    return res;
}
int main(){
    vector<int> nums = {2,7,9,3,1};
    cout << minCapability(nums, 2) << endl;
}