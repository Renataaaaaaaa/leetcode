#include <vector>
#include <iostream>
using namespace std;


int pivotIndex(vector<int>& nums) {
    vector<int> sum(nums.size());
    for(vector<int>::size_type i = 0; i < nums.size(); i++){
        sum[i] = (i == 0) ? nums[0] : (sum[i-1] + nums[i]);
    }
    for(vector<int>::size_type i = 0; i < nums.size(); i++){
        if ( (i==0 ? 0 : sum[i-1]) == (sum[nums.size() - 1] - sum[i])){
            return i;
        }
    }
    return -1;
}