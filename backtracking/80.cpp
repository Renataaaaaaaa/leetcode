#include <vector>
#include <iostream>
#include <ctype.h>
using namespace std;

void subsetsHelp(vector<int>& nums, int i, vector<int>& cur_subset, vector<vector<int> >& res){
    if (i == nums.size()){
        res.push_back(cur_subset);
        return;
    }
    //discard i
    int old_i = i;
    while(i + 1 < nums.size() && nums[i+1] == nums[i]){
        i++;
    }
    subsetsHelp(nums, i+1, cur_subset, res);

    i = old_i;
    //keep i
    cur_subset.push_back(nums[i]);
    subsetsHelp(nums, i+1, cur_subset, res);

    // res.push_back(cur_subset);
    cur_subset.pop_back();

}

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    vector<int> cur_subset;
    subsetsHelp(nums, 0, cur_subset, res);
    return res;
}