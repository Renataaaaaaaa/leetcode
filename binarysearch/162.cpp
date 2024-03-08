#include <vector>
#include <iostream>
using namespace std;


int findPeakElement(vector<int>& nums) {
    if (nums.size() == 1){
        return 0;
    }
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;
    while(hi >= lo){
        mid = (lo + hi) / 2;
        if ((mid == 0 || nums[mid] > nums[mid-1]) && (mid == nums.size() - 1 || nums[mid] > nums[mid+1])){
            return mid;
        }else if ((mid == 0 ||  nums[mid] > nums[mid-1]) && (mid == nums.size() - 1 || nums[mid] < nums[mid+1])){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}