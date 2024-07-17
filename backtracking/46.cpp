#include <vector>
#include <iostream>
#include <ctype.h>
using namespace std;

void swap(vector<int>& nums, int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void permuteHelp(vector<int>& nums, int index, vector< vector<int>>& res){
    if (index == nums.size()){
        res.push_back(nums);
    }
    for (int i = index; i < nums.size(); i++){
        swap(nums, i, index);
        permuteHelp(nums, index + 1, res);
        swap(nums, i, index);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur_res;
    permuteHelp(nums, 0, res);
    return res;
}