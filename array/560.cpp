#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    vector<int> sums(nums.size(), 0);
    unordered_map<int, int> map;
    int res = 0;

    for (int i = 0; i < nums.size(); i++){
        sums[i] = i == 0 ? nums[0] : sums[i - 1] + nums[i];
        if (sums[i] == k){
            res = res + 1;
        }
        if (map.find(sums[i] - k) != map.end()) {
            res = res + map[sums[i] - k];
        }        
        map[sums[i]] += 1;

    }
    return res;
}