#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;


int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0;
    int res = INT32_MAX;
    int sum = nums[0];
    while(right < nums.size() && left < nums.size()){
        if (sum >= target){
            sum -= nums[left];
            res = std::min(res, (right - left + 1));
            left++;
        }else{
            if (right == nums.size() - 1){
                break;
            }
            sum += nums[++right];
        }
    }
    if (res == INT32_MAX){
        return 0;
    }else{
        return res;
    }
}

