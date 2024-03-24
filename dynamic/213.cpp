#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int robRange(vector<int>& nums, int i, int j) { //往回看

    if (i >= j){
        return nums[i];
    } else if (j == (i + 1)){
        return max(nums[i], nums[j]);
    }

    vector<int> dp((j - i + 1), 0);
    cout << dp.size() << endl;
    dp[0] = nums[i];
    dp[1] = max(nums[i], nums[i + 1]);
    for(int k = i + 2; k <= j; k++){
        cout << "k " << k << endl;
        dp[k - i] = max(nums[k] + dp[k - i - 2], dp[k - i - 1]);
    }
    return dp[dp.size() - 1];
}


int rob(vector<int>& nums) { //往前看

    int res_with_first = robRange(nums, 0, nums.size() - 2);
    int res_without_first = robRange(nums, 1, nums.size() - 1);
    return max(res_with_first, res_without_first);
}

int main(){
    vector<int> data = {0};
    cout << rob(data) << endl;
}