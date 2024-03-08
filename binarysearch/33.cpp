#include <vector>
#include <iostream>
using namespace std;

int search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;
    while(hi >= lo){

        mid = (lo + hi) / 2;
        if (nums[mid] == target){
            return mid;
        }
        if (nums[mid] < nums[lo] && nums[mid] < nums[hi]){
            if ((nums[mid] > target) || (nums[mid] < target && nums[hi] < target)){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }else{
            if ((nums[mid] < target) || (nums[mid] > target && nums[lo] > target)){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
    }
    return -1;
}