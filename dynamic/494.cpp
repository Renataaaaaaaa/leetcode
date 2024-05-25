
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

//
int count_res = 0;
void backtrack(vector<int>& nums, int target, int index, int sum) {
    if (index == nums.size()) {
        if (sum == target) {
            count_res++;
        }
    } else {
        backtrack(nums, target, index + 1, sum + nums[index]);
        backtrack(nums, target, index + 1, sum - nums[index]);
    }
}

int findTargetSumWays(vector<int>& nums, int target) {
    backtrack(nums, target, 0, 0);
    return count_res;
}
