#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int robRange(vector<int>& nums, int i, int j) { //往回看

    vector<int> dp((j - i + 3), 0);
    // dp[0] = nums[i];
    // dp[1] = max(nums[i], nums[i + 1]);
    for(int k = 2; k < j - i + 3; k++){
        // cout << "k " << k << endl;
        dp[k] = max(nums[k - 2 + i] + dp[k - 2], dp[k - 1]);
    }
    return dp[dp.size() - 1];
}


int rob(vector<int>& nums) { //往前看

    int res_with_first = robRange(nums, 0, nums.size() - 2);
    int res_without_first = robRange(nums, 1, nums.size() - 1);
    return max(res_with_first, res_without_first);
}

int main(){
    vector<int> data = {1,2,3,1};
    cout << rob(data) << endl;
}