#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

// 右边到了边界，左边一直收敛到满足条件为止

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0;
    int res = INT32_MAX;
    int sum = 0;
     while (right < nums.size()) {
        sum += nums[right];
        while (sum >= target) {
            res = min(res, right - left + 1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    if (res == INT32_MAX){
        return 0;
    }else{
        return res;
    }
}

