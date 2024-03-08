#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    for (auto& item: nums){
        if (item == 0){
            item = -1;
        }
    }

    vector<int> sums(nums.size(), 0);
    unordered_map<int, int> map;
    int res = 0;

    for (int i = 0; i < nums.size(); i++){
        sums[i] = i == 0 ? nums[0] : sums[i - 1] + nums[i];
        if (sums[i] == 0){
            res = max(res, i + 1);
        }
        if (map.find(sums[i] - 0) != map.end()) {
            res = max(res, (i - (map[sums[i]])) );
        }
        if (map.find(sums[i]) == map.end()) {
            map[sums[i]] = i;
        }
    }
    return res;   
    }
};