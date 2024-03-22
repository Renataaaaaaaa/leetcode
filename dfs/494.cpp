#include "utils.cpp"
#include <queue>


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

int main(){
    vector<int> data = {1,1,1,1,1};
    cout << findTargetSumWays(data, 3) << endl;
}