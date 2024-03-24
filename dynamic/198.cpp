#include <vector>
#include <iostream>
using namespace std;

int rob(vector<int>& nums) { //往回看

    if (nums.size() == 1){
        return nums[0];
    } else if (nums.size() == 2){
        return max(nums[0], nums[1]);
    }

    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); i++){
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    }
    return dp[dp.size() - 1];
}

int main(){
    vector<int> data = {2,7,9,3,1};
    cout << rob(data) << endl;
}