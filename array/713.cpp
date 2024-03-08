#include <vector>
#include <iostream>
using namespace std;


int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int left = 0;
    int product = 1;
    int res = 0;
    for(int right = 0; right < nums.size(); right++){
        product = product * nums[right];
        while(product >= k && left <= right){
            product = product / nums[left++];
        }
        res += right - left + 1; 
    }
    return res;
}