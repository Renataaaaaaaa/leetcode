#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

int longestNiceSubarray(vector<int>& nums) {
    int left = 0, right = 0;
    int cur_or = 0;
    int res = 0;
    while(right < nums.size()){
        while ((cur_or & nums[right]) != 0){
            cur_or ^= nums[left];
            left++;
        }
        res = max(res, right - left + 1);
        cur_or |= nums[right];
        right++;
    }
    return res;
}

int main(){
    // vector<int> nums = {1,3,8,48,10};
     vector<int> nums = {3,1,5,11,13};
    cout << longestNiceSubarray(nums) << endl;
}