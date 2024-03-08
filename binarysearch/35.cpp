#include <vector>
#include <iostream>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    int mid = 0;
    while(hi >= lo){
        mid = (hi + lo )/2;
        if (nums[mid] == target){
            return mid;
        }else if (nums[mid] > target){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return lo;
}