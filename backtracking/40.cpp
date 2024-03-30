#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
using namespace std;

void combinationSumHelp(vector<int>& nums, int i, vector<int>& cur_res, int target, vector<vector<int>>& res){
    int sum = accumulate(cur_res.begin(), cur_res.end(), 0);
    if (sum > target){
        return;
    }
    if (i == nums.size()){
        if (sum == target){
            res.push_back(cur_res);
            // cur_res = {};
        }
        return;
    }
    //discard
    int different_index = i + 1;
    while(different_index < nums.size() && nums[different_index] == nums[i]){
        different_index++;
    }
   combinationSumHelp(nums, different_index, cur_res, target, res);

    //keep
    cur_res.push_back(nums[i]);
    combinationSumHelp(nums, i + 1, cur_res, target, res); //
    // cur_res = {};
    cur_res.pop_back(); //ATTENTION
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cur_res;
    sort(candidates.begin(), candidates.end());
    combinationSumHelp(candidates, 0, cur_res, target, res);
    return res;
}
int main(){
    vector<int> data = {2,3,6,7};
    for (auto list: combinationSum2(data, 7)){
        for (auto item: list){
            cout << item << " ";
        }
        cout << endl;
    }
}