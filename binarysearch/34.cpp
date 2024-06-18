#include <vector>
#include <iostream>
using namespace std;

int bisect_left(vector<int>& nums, int target){
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;
    while(hi >= lo){
        mid = lo + (hi - lo) / 2;
        if (nums[mid] == target){
            hi = mid - 1;
        }else if (nums[mid] < target){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return lo;
}
int bisect_right(vector<int>& nums, int target){
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;
    while(hi >= lo){
        mid = lo + (hi - lo) / 2;
        if (nums[mid] == target){
            lo = mid + 1;
        }else if (nums[mid] < target){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return hi;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int left_index = bisect_left(nums, target);
    int right_index = bisect_right(nums, target);
    if (left_index == nums.size() || right_index < 0){
        return {-1, -1};
    }else{
        if (nums[left_index] != target){
            return {-1, -1};
        }else{
            return {left_index, right_index};
        }
        
    }

}
int main(){
    vector<int> nums = {};
    for(auto item: searchRange(nums, 0)){
        cout << item << endl;
    }
}