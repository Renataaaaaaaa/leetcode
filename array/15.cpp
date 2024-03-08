#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++){
        int target = 0 - nums[i];
        int p = i + 1;
        int q = nums.size() - 1;
        while(q > p){
            if ((nums[p] + nums[q]) > target){
                q--;
            }else if ((nums[p] + nums[q]) < target){
                p++;
            }else{
                res.push_back({nums[i], nums[p], nums[q]});
                while(p+1 < nums.size() && nums[p] == nums[p+1]){
                    p++;
                }
                p++;
                q--;
            }
        }
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
    }
    return res;
}