#include <vector>
#include <iostream>
#include <ctype.h>
#include <unordered_set>
using namespace std;


void permuteHelp(vector<int>& nums, vector<bool> used, vector<int>& path, vector< vector<int>>& res){
    if (path.size() == nums.size()){
        res.push_back(path);
    }
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++){
        if (!used[i] && set.find(nums[i]) == set.end()){
            set.insert(nums[i]);
            used[i] = true;
            path.push_back(nums[i]);
            permuteHelp(nums, used, path, res);
            path.pop_back();
            used[i] = false;
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur_res;
    vector<bool> used (nums.size());
    permuteHelp(nums, used, cur_res, res);
    return res;
}

int main(){
    vector<int> nums = {1,1,2};
    for(auto permutee: permute(nums)){
        for(auto item: permutee){
            cout << item << " ";
        }
        cout << endl;
    }
}