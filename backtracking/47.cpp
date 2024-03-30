#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
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
    set<int> swaped;
    for (int i = index; i < nums.size(); i++){
        if (swaped.find(nums[i]) != swaped.end()){
            continue;
        }
        swaped.insert(nums[i]);
        swap(nums, i, index);
        permuteHelp(nums, index + 1, cur_res, res);
        swap(nums, i, index);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur_res;
    // sort(nums.begin(), nums.end());
    permuteHelp(nums, 0, cur_res, res);
    return res;
}