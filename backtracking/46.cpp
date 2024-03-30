#include <vector>
#include <iostream>
#include <ctype.h>
using namespace std;

void swap(vector<int>& nums, int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void permuteHelp(vector<int>& nums, int index, vector<int>& cur_res, vector< vector<int>>& res){
    if (index == nums.size()){
        res.push_back(nums);
    }
    for (int i = index; i < nums.size(); i++){
        // cur_res.push_back(nums[i]);
        // swap(nums, i, index);
        // vector<int> nums_cur = nums;
        swap(nums, i, index);
        permuteHelp(nums, index + 1, cur_res, res);
        swap(nums, i, index);
    }
    // cur_res.erase(cur_res.end() - 1);
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur_res;
    permuteHelp(nums, 0, cur_res, res);
    return res;
}