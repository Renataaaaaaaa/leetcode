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
   combinationSumHelp(nums, i + 1, cur_res, target, res);

    //keep
    cur_res.push_back(nums[i]);
    combinationSumHelp(nums, i, cur_res, target, res);
    cur_res.pop_back();
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cur_res;
    combinationSumHelp(candidates, 0, cur_res, target, res);
    return res;
}
int main(){
    vector<int> data = {2,3,6,7};
    for (auto list: combinationSum(data, 7)){
        for (auto item: list){
            cout << item << " ";
        }
        cout << endl;
    }
}