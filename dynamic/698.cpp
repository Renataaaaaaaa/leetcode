#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int all = accumulate(nums.begin(), nums.end(), 0);
    if (all % k > 0) {
        return false;
    }
    int per = all / k; 
    sort(nums.begin(), nums.end());
    if (nums.back() > per) {
        return false;
    }
    int n = nums.size();
    vector<bool> dp(1 << n, false);
    vector<int> curSum(1 << n, 0);
    dp[0] = true;
    for (int i = 0; i < 1 << n; i++) {
        if (!dp[i]) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (curSum[i] + nums[j] > per) {
                break;
            }
            if (((i >> j) & 1) == 0) {
                int next = i | (1 << j);
                if (!dp[next]) {
                    curSum[next] = (curSum[i] + nums[j]) % per;
                    dp[next] = true;
                }
            }
        }
    }
    return dp[(1 << n) - 1];   // all is set to 1
}

//4 3 2 3 5 2 1
// j is one of outside the current dataset
// i = 0  j = 0  cursum[i] = 0  next = 0 | 1 = 1  cursum[1] = 4  dp[1] = true
// i = 0  j = 1  cursum[i] = 0  next = 0 | 1 << 1  = 2(10)  cursum[2] = 3  dp[2] = true
//在空合集的情况下，添加一个元素，以上都为true

// i = 1  j = 0  cursum[i] + nums[j] = 8 break;
// i = 1  j = 6 cursum[i] + nums[j] = 5 next = 1 | 1 << 6（在1的基础上加了6） = cursum[next] = 0 dp[next] = true

// ？为什么一个比较余数一个比较和

int main(){
    vector<int> data = {4, 3, 2, 3, 5, 2, 1};
    cout << canPartitionKSubsets(data, 4) << endl;
}

// 