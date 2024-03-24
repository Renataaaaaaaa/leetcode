#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int maxSubArray(vector<int>& nums) {
    vector<int> dp (nums.size() + 1, 0);
    dp[0] = 0;
    int res = nums[0]; //ATTENTION: 开始值注意
    for (int i = 0; i < nums.size(); i++){
        dp[i + 1] = max(dp[i - 1 + 1] + nums[i], nums[i]);
        res = max(res, dp[i + 1]);
    }
    return res;
}

int main(){
    vector<int> data = {-1};
    cout << maxSubArray(data) << endl;
}